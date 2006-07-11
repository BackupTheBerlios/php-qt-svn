<?php

    /****************************************************************
    **
    ** Qt tutorial 3
    **
    ** http://doc.trolltech.com/4.0/tutorial-t3.html
    **
    ****************************************************************/
                
	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}


    $app = new QApplication($argc,$argv);

    $window = new QWidget();
    $window->resize(200,120);

    $quit = new QPushButton("Quit", $window);
//    $quit->setFont();
    $quit->setGeometry(10, 40, 180, 40);

//    QObject::connect($quit,SIGNAL("clicked()"),$app,SLOT("quit()"));
    $quit->connect($quit,SIGNAL("clicked()"),$app,SLOT("quit()"));

    $window->show();

    $app->exec();

?>
