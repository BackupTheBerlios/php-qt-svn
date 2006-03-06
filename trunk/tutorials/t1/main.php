<?php
    /****************************************************************
     **
     ** Qt tutorial 1
     **
     ** http://doc.trolltech.com/4.0/tutorial-t1.html
     **
     ****************************************************************/

	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}


    $app = new QApplication($argc,0);

    $hello = new QPushButton("Hello world!");
//    hello.resize(100, 30);

    $hello->show();
    $app->exec();

?>
