<?php
	include"database.php";
	session_start();
	$s="delete from staff where TID={$_GET["id"]}";
	$db->query($s);
	echo"<script>window.open('view_staff.php','_self');</script>";

?>