<?php
    /****************************************************************
    **
    ** Qt tutorial 6
    **
    ** http://doc.trolltech.com/4.0/tutorial-t6.html
    **
    ****************************************************************/

    if(!extension_loaded('php_qt')) {
        dl('php_qt.' . PHP_SHLIB_SUFFIX);
    }

    class LCDRange extends QWidget
    {
        var $lcd;
        var $slider;
        var $layout;

        function __construct(){

            parent::__construct();

            $this->lcd = new QLCDNumber(2,$this);
            $this->slider = new QSlider($this);
            $this->slider->setOrientation(QT_ORIENTATIONS_HORIZONTAL);
            $this->slider->setRange(0, 99);
            $this->slider->setValue(0);
            $this->connect($this->slider, SIGNAL("valueChanged(int)"),
                    $this->lcd, SLOT("display(int)"));
    
            $this->layout = new QVBoxLayout($this);
            $this->layout->addWidget($this->lcd);
            $this->layout->addWidget($this->slider);
            $this->setLayout($this->layout);
        }

    };

    class MyWidget extends QWidget
    {
        var $quit;
        var $grid;
        var $layout;

        function __construct(){

            parent::__construct();

            $this->quit = new QPushButton("Quit");
    //        $this->quit->setFont(QFont("Times", 18, QFont::Bold));
            $this->connect($this->quit, SIGNAL("clicked()"), QApplication::instance(), SLOT("quit()"));

            $this->grid = new QGridLayout();
            for ($row = 0; $row < 4; ++$row) {
                for ($column = 0; $column < 4; ++$column) {
                    $this->grid->addWidget(new LCDRange(), $row, $column);
                }
            }

            $this->layout = new QVBoxLayout($this);
            $this->layout->addWidget($this->quit);
            $this->layout->addLayout($this->grid,0);
            $this->setLayout($this->layout);
        }
    }

    $app = new QApplication($argc,0);
    $widget = new MyWidget();
    $widget->show();
    $app->exec();

?>