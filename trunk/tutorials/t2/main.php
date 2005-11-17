<?php

    /****************************************************************
    **
    ** Qt tutorial 2
    **
    ****************************************************************/
                
	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}


    $app = new QApplication();

    $quit = new QPushButton("Quit");
    $quit->resize(75,30);
//    $quit->setFont();

    QObject::connect($quit,SIGNAL("clicked()"),$app,SLOT("quit()"));

    $quit->show();

    $app->exec();

?>