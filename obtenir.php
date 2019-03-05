<?php

session_start();

if(!empty($_POST['name'])) {
	if(!isset($_SESSION['posts'])) {
		$_SESSION['posts'] = 0;
	}
	else {
		$_SESSION['posts'] += 1;
		file_put_contents("obtenir.txt", htmlspecialchars($_POST['name']) . "<br />",FILE_APPEND);
	}
}
echo file_get_contents("obtenir.txt");
?>

<form method="post" action="">
	<input name = "name" type = "text" value = "Ernest" />
	<input type = "submit" />
</form>
