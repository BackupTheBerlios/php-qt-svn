<?php

    if(!extension_loaded('php_qt')) {
        dl('php_qt.' . PHP_SHLIB_SUFFIX);
    }

	$QString = new QString("I'm a test!");

	echo $QString;


?>