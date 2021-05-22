<?php
error_reporting(0);
$mensagem = $_GET['msg'];
$myfile = file_put_contents('logs_users', $mensagem.PHP_EOL , FILE_APPEND | LOCK_EX);
echo 'call from phpenviar.php';
?>
