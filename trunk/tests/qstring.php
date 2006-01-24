<?php

    if(!extension_loaded('php_qt')) {
        dl('php_qt.' . PHP_SHLIB_SUFFIX);
    }

/* String as parameter */
	$QString_1 = new QString("I'm a test!");

/* ASCII as parameter */
	$QString_2 = new QString(40);
	$QString_3 = new QString(41);

/* this work: */
	echo $QString_2;
	echo $QString_1;
	echo $QString_3;
    echo "\n";

/* this does not work */
	echo $QString_2." ".$QString_1." ".$QString_3;
    echo "\n";

/* this does not work */
	$tmp = $QString_2." ".$QString_1." ".$QString_3;
	print($tmp);

    echo "\n";

/* this does not work */
	$tmp2 = $QString_2;
	$tmp2 = $QString_1;
	$tmp2 = $QString_3;
	echo $tmp;
    echo "\n";

/* this does not work */
	echo "$QString_2 $QString_1 $QString_3";
    echo "\n";

/* this work: */
	$var1 = $QString_1->__toString();
	$var2 = $QString_2->__toString();
	$var3 = $QString_3->__toString();
	print $var2." ".$var1." ".$var3;
    echo "\n";

?>