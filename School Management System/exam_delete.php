<?php
	include "database.php";
	session_start();
	$s="delete from exam where EID={$_GET["id"]}";
	$db->query($s);
	echo "<script>window.open('view_exam.php?mes=Data Deleted...','_self');</script>";


?>