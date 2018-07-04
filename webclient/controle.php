<?
if($_GET['c']) file_put_contents('comando.txt',$_GET['c']);
?>
<font size=50><a href='controle.php?c=L1'>Turn On Relay 1</a><br>&nbsp;<br>&nbsp;<br>
<a href='controle.php?c=D1'>Turn Off Relay 1</a><br>&nbsp;<br>&nbsp;<br>
<a href='controle.php?c=L2'>Turn On Relay 2</a><br>&nbsp;<br>&nbsp;<br>
<a href='controle.php?c=D2'>Turn Off Relay 2</a><br></font>
Código do robo.php:
<?
echo (file_get_contents('comando.txt'));
?>