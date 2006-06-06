<?php
    /****************************************************************
    **
    ** Qt Calculator
    **
    ** http://doc.trolltech.com/4.0/widgets-calculator.html
    **
    ****************************************************************/

    if(!extension_loaded('php_qt')) {
        dl('php_qt.' . PHP_SHLIB_SUFFIX);
    }

    require_once('calculator.php');

    $app = new QApplication($argc,$argv);

    $calc = new Calculator();
    $calc->show();
    $app->exec();

?>