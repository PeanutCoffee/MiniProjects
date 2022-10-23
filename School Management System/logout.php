<?php
	include "database.php";
	session_start();
	
	unset ($_SESSION["AID"]);
	unset ($_SESSION["ANAME"]);
	unset ($_SESSION["TID"]);
	unset ($_SESSION["TNAME"]);
	
	session_destroy();
	echo "<script>window.open('index.php','_self');</script>";
?>