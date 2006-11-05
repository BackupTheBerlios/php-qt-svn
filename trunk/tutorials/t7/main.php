<?php
    /****************************************************************
    **
    ** Qt tutorial 7
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

        var $slots = array("setValue(int)");
        var $signals = array("valueChanged(int)");

        function __construct(){

            parent::__construct();

            $this->lcd = new QLCDNumber(2,$this);
            $this->slider = new QSlider($this);

            $this->slider->setOrientation(Qt::Horizontal);
            $this->slider->setRange(0, 99);
            $this->slider->setValue(0);

            $this->connect($this->slider, SIGNAL("valueChanged(int)"),
                    $this->lcd, SLOT("display(int)"));

            $this->connect($this->slider, SIGNAL("valueChanged(int)"),
                    $this,SIGNAL("valueChanged(int)"));

            $this->layout = new QVBoxLayout($this);
            $this->layout->addWidget($this->lcd);
            $this->layout->addWidget($this->slider);
            $this->setLayout($this->layout);
        }

        function setValue($value){
            $this->slider->setValue($value);
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
            $this->quit->setFont(new QFont("Times", 18, 1));
            $this->connect($this->quit, SIGNAL("clicked()"), QApplication::instance(), SLOT("quit()"));


            $this->grid = new QGridLayout();
            for ($row = 0; $row < 3; ++$row) {
                for ($column = 0; $column < 3; ++$column) {
                    $lcdRange = new LCDRange();
                    $this->grid->addWidget($lcdRange, $row, $column);
                    if($previousRange)
                        $this->connect($lcdRange, SIGNAL("valueChanged(int)"), $previousRange, SLOT("setValue(int)"));
                    $previousRange = $lcdRange;
                }

            }

            $this->layout = new QVBoxLayout($this);
            $this->layout->addWidget($this->quit);
            $this->layout->addLayout($this->grid,0);
            $this->setLayout($this->layout);
        }
    }

    $app = new QApplication($argc,$argv);
echo "argv";
    $widget = new MyWidget();
    $widget->show();
    $app->exec();

?>