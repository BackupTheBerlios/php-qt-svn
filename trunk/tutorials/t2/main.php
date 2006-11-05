<?php

    /****************************************************************
    **
    ** Qt tutorial 2
    **
    ** http://doc.trolltech.com/4.0/tutorial-t2.html
    **
    ****************************************************************/
                
	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}


    $app = new QApplication($argc,$argv);

    $quit = new QPushButton("Quit");

    $quit->resize(75,30);
//    $quit->setFont();

//    QObject::connect($quit,SIGNAL("clicked()"),$app,SLOT("quit()"));
    $quit->connect($quit,SIGNAL("clicked()"),$app,SLOT("quit()"));

    $quit->show();

    $app->exec();

?>
