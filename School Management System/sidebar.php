<div class="sidebar"><br>
<h3 class="text">Dashboard</h3><br><hr><br>
<ul class="s">
<?php
	if(isset($_SESSION["AID"]))
	{
		echo'
			<li class="li"><a href="admin_home.php">School Information</a></li>
			<li class="li"><a href="add_class.php"> Class</a></li>
			<li class="li"><a href="add_sub.php"> Subject</a></li>
			<li class="li"><a href="add_staff.php"> Staff</a></li>
			<li class="li"><a href="set_exam.php">Set Exam</a></li>
			<li class="li"><a href="view_exam.php">View Exam</a></li>
		
		';
	
	
	}
	else{
		echo'
			<li class="li"><a href="handle_class.php"> Class</a></li>
			<li class="li"><a href="tech_view_exam.php">View Exam</a></li>
		';
	}


?>
	

</ul>

</div>