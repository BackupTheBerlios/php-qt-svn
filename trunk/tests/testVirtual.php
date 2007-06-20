<?php


    class myWidget extends QWidget
    {
	public function __construct()
	{
	    parent::__construct();
	}
	
	public function sizeHint()
	{
	    echo "my own sizeHint\n";
	    return parent::sizeHint();
	}
	
    }

    $app = new QApplication($argc, $argv);
    
    $m = new myWidget();
    
    for( $i = 0; $i < 10; $i++ )
    {
      $m->show();
      $m->hide();
    }
    
    $app->exec();

?>