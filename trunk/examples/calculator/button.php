<?php
    /****************************************************************
    **
    ** Qt Calculator
    **
    ** http://doc.trolltech.com/4.0/widgets-calculator.html
    **
    ****************************************************************/

    class Button extends QToolButton {
    
        function __construct($text){

            parent::__construct();
///            $this->setSizePolicy("QSizePolicy::Expanding", "QSizePolicy::Preferred");
            $this->setText(new QString($text));

        }

    }

?>