<?php
class dht22{
 public $link='';
 function __construct($suhu, $kelembaban){
  $this->connect();
  $this->storeInDB($suhu, $kelembaban);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'arduino_sensor') or die('Cannot select the DB');
 }
 
 function storeInDB($suhu, $kelembaban){
  $query = "insert into dht_data set kelembaban='".$kelembaban."', suhu='".$suhu."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
  if($result === TRUE){echo "Data Tersimpan";}else{echo "Gagal Menyimpan data";}
 }
 
}
if($_GET['dataSuhu'] != '' and  $_GET['dataKelembaban'] != ''){
 $dht22=new dht22($_GET['dataSuhu'],$_GET['dataKelembaban']);
}

?>