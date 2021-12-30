<?php
$username = "root";
$pass = "";
$host = "localhost";
$db_name = "arduino_sensor";
$con = mysqli_connect ($host, $username, $pass);
$db = mysqli_select_db ( $con, $db_name );
?>
<?php
include ('connection.php');
$sql_insert = "INSERT INTO data (suhu, kelembapan) VALUES ('".$_GET["suhu"]."', '".$_GET["kelembapan"]."')";
if(mysqli_query($con,$sql_insert))
{
echo "Done";
mysqli_close($con);
}
else
{
echo "error is ".mysqli_error($con );
}
?>