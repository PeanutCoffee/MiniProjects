<?php
	include"database.php";
	session_start();
	
	$s="delete from class where CID={$_GET["id"]}";
	$db->query($s);
	echo "<script>window.open('add_class.php?mes=Data Deleted.','_self');</script>"
?>