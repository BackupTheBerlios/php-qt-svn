<?php

    if(!extension_loaded('php_qt')) {
        dl('php_qt.' . PHP_SHLIB_SUFFIX);
    }

	$QString = new QString("hello");

	echo $QString->toUTF8();

	echo $QString;

	$QString->setUnicode(new QChar(65), 1);

	echo $QString;

	echo "\n";

?>