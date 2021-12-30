#include <SPI.h>
#include <Ethernet.h>
#include "DHT.h"
#define DHTPIN 9
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {10, 255, 200, 18 }; //Enter the IP of ethernet shield
byte serv[] = {10, 255, 200, 228} ; //Enter the IPv4 address
EthernetClient cliente;
void setup() {
Serial.begin(9600); //setting the baud rate at 9600
Ethernet.begin(mac, ip);
dht.begin();
}
void loop() {
float kelembapan = dht.readHumidity(); //Reading the humidity and storing in hum
float suhu = dht.readTemperature(); //Reading the temperature as Celsius and storing in temp
//float fah = dht.readTemperature(true); //reading the temperature in Fahrenheit
float heat_index = dht.computeHeatIndex(fah, hum); //Reading the heat index in Fahrenheit
float heat_indexC = dht.convertFtoC(heat_index); //Converting the heat index in Celsius
 if (cliente.connect(serv, 80)) { //Connecting at the IP address and port we saved before
Serial.println("connected");
cliente.print("GET /arduino_sensor/senddata.php?"); //Connecting and Sending values to database
cliente.print("&heat_indexC=");
cliente.println(suhu);
cliente.print("&humidity=");
cliente.print(kelembapan);
//Printing the values on the serial monitor
Serial.print("Suhu= ");
Serial.println(heat_indexC);
Serial.print("Kelembapan= ");
Serial.println(kelembapan);
cliente.stop(); //Closing the connection
}
else {
// if you didn't get a connection to the server:
Serial.println("connection failed");
}
delay(5000);
}
