<?php


    class QApplication extends _QApplication
    {
    
	public function __construct($argc, $argv){
	    parent::__construct($argc, $argv);
	}
    
    }

    $app = new QApplication($argc, $argv);
    $app->exec();

?>