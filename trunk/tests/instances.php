<?
  if(!extension_loaded('php_qt')) {
    dl('php_qt.' . PHP_SHLIB_SUFFIX);
  }
 
  $app = new QCoreApplication(&$argc,$argv);

  echo $app." app\n";  

  $instance_static = QCoreApplication::instance();
  $instance = $app->instance(); 
 
  echo $instance_static." QCoreApplication::instance()\n";
  echo $instance." app->instance()\n";
  echo $app." app\n";  

?>