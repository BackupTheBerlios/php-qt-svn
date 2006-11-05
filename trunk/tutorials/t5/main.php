<?php
    /****************************************************************
    **
    ** Qt tutorial 5
    **
    ** http://doc.trolltech.com/4.0/tutorial-t5.html
    **
    ****************************************************************/

	if(!extension_loaded('php_qt')) {
		dl('php_qt.' . PHP_SHLIB_SUFFIX);
	}

    class MyWidget extends QWidget
    {

        public $quit;
        public $slider;
        public $layout;
        public $lcd;

        function __construct(){

			parent::__construct();

            $this->quit = new QPushButton("Quit", $this);
//            $this->quit->setFont(QFont("Times", 18, QFont::Bold));

            $this->lcd = new QLCDNumber(2,$this);

            $this->slider = new QSlider($this);
            $this->slider->setOrientation(Qt::Horizontal);
            $this->slider->setRange(0, 99);
            $this->slider->setValue(0);

            $this->connect($this->quit, SIGNAL("clicked()"), QApplication::instance(), SLOT("quit()"));
            $this->connect($this->slider, SIGNAL("valueChanged(int)"),$this->lcd, SLOT("display(int)"));

            $this->layout = new QVBoxLayout($this);

            $this->layout->addWidget($this->quit);
            $this->layout->addWidget($this->lcd);
            $this->layout->addWidget($this->slider);
            $this->setLayout($this->layout);

        }
    }


    $app = new QApplication($argc,$argv);
    $widget = new MyWidget();
    $widget->show();

    $app->exec();

?>
