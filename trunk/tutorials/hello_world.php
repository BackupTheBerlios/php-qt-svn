<?php
    /****************************************************************
     **
     ** Qt tutorial 1
     **
     ****************************************************************/

	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}


    $app = new QApplication();

    $hello = new QPushButton("Hello world!");
//    hello.resize(100, 30);

    $hello->show();
    $app->exec();

?>