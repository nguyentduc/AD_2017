<?php
$log_file = 'sound_log.txt';	//log file name
$data = $_POST['data'];
date_default_timezone_set("UTC");
$str = gmdate("M d Y H:i:s", time()).', '.$data." \n";	//two fields in one record, the timestamp and post data
echo "This is form the server \n";

if(file_exists($log_file))
{
	$fp = fopen($log_file, "a");
	fwrite($fp, $str);
	fclose($fg);
}
else		//the file does'nt exist. so open a new one
{
	$fp = fopen($log_file, "w");
	fwrite($fp, $str);
	fclose($fg);
}
echo "Data is stored\n";		
?>