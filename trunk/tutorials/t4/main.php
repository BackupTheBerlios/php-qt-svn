<?php

    /****************************************************************
    **
    ** Qt tutorial 4
    **
    ****************************************************************/
                
	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}

    class MyWidget extends QWidget
    {
    
        public $quit;

        function __construct()
        {

			parent::__construct();

            $this->setFixedSize(200, 120);

            $this->quit = new QPushButton("Quit", $this);
            $this->quit->setGeometry(62, 40, 75, 30);
//            $quit->setFont();

            /* the macro qApp is not available in php-qt, we use QApplication::instance() directly. */
            $this->connect($this->quit, SIGNAL("clicked()"), QApplication::instance(), SLOT("quit()"));

        }
    
    }

    $app = new QApplication();

    $widget = new MyWidget();

    $widget->show();

    $app->exec();

?>