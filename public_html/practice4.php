<!DOCTYPE html>
<html>
<head>
	<link href="MyStyleSheet.css" rel="stylesheet">
	<title>Multiplication Table</title>
</head>
<style>
        .title {
                background-color: blue;
        }
        .header {
                background-color: red;
        }
        .body {
                background-color: yellow;
        }
</style>
<body>
	<div class="title">
	<h1 align="center">Multiplication Table</h1>
	</div>
	<div class="header">
	<form align="center" method="post">
		<label for="number">Enter a number:</label>
		<input type="number" id="number" name="number" required>
		<input type="submit" value="Generate Table">
	</form>
	</div>

	<?php
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$number = $_POST["number"];
		echo "<div>";
		echo "<h2>Multiplication Table for $number:</h2>";
		echo "<table>";
		echo "<tr><th>X</th>";
		for ($i = 1; $i <= $number; $i++) {
			echo "<th>$i</th>";
		}
		echo "</tr>";
		for ($i = 1; $i <= $number; $i++) {
			echo "<tr><th>$i</th>";
			for ($j = 1; $j <= $number; $j++) {
				$product = $i * $j;
				echo "<td>$product</td>";
			}
			echo "</tr>";
		}
		echo "</table>";
		echo "</div>";
	}
	?>
</body>
</html>


