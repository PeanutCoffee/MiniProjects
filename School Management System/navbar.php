<div class="navbar">

			<ul class="list">
				<b style="color:white;float:left;line-height:50px;margin-left:15px;font-family:Cooper Black;">
				School Management System</b>
			<?php
				if(isset($_SESSION["AID"]))
				{
					echo'
				
						<li><a href="admin_home.php">Admin Home</a></li>
						<li><a href="logout.php">Logout</a></li>
					';
				}
				
				else{
					echo'
					
					<li><a href="index.php">Admin</a></li>';
				}
			?>
				
			</ul>
		</div>
		