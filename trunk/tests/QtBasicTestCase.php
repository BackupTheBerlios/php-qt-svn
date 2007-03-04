<?php

    /**
     *	This file contains a couple of basic tests
     *
     *	- test fetching constants, the opcode handler has been overwritten
     *	- test __toString()
     *	- test QString
     *	- test returning values and objects
     *  - test returning references
     */

    require_once('PHPUnit/Framework/TestCase.php');
    require_once('PHPUnit/Framework/TestSuite.php');

    /* 
     * check if we can fetch constants
     */

    class foo extends QObject {
	const a = "a";
	const b = 24;
	
	public function testMethod($value = NULL) {
	    if ($value) echo $value."\n";
	}
	
    }



    class QtBasicTestCase extends PHPUnit_Framework_TestCase {
    
	private $argc = 1; 
	private $argv = "init";
	private $app;
    
	public function __construct($name) {
	    parent::__construct($name);
	}

	// try to fetch a string constant
	function testFetchStringConstant() {
	    $this->assertEquals(foo::a, "a", "Could not fetch string constant!");
	    echo "\ntesting foo::a passed";
	}

	// try to fetch a numeric constant
	function testFetchNumConstant() {
	    $this->assertEquals(foo::b, 24, "Could not fetch numeric constant!");
	    echo "\ntesting foo::b passed";
	}

	// try to fetch a Qt constant
	function testQtConstant() {
	    $this->assertTrue(Qt::Horizontal == 1, "Could not fetch constant from Qt!");
	    echo "\ntesting Qt::Horizontal passed";
	}

	// test the __toString() method
	function testQString() {
	    $s = new QString("hello");
	    $this->assertEquals($s->__toString(), "hello", "Could not handle __toString()!");
	    echo "\ntesting QString::__toString() passed";
	}

	// try to append a PHP string to a QString
	function testQStringAppendString() {
	    $s = new QString("hello");
	    $s->append(" world");
	    $this->assertEquals($s->__toString(), "hello world", "Could append simple string to QString!");
	    echo "\ntesting QString::append(\"hello\") passed";
	}

	// try to create an instance of QApplication
	function testQApplication() {
	    $this->app = new QApplication(&$this->argc,$this->argv);
	    $this->assertTrue(is_object($this->app), "Could not create an instance of QApplication!");
	    echo "\ntesting QApplication passed";
	}

	// test returning numbers
	function testReturnNum() {
	    $date = new QDate(2007,3,24);
	    $this->assertTrue((gettype($date->day()) == "integer"), "Value returned is not integer type, ".gettype($date->day())." detected!");
	    $this->assertTrue(($date->day() == 24), "Value returned is wrong!");
	    echo "\ntesting numbers passed";
	}

	// test returning double
	// test returning array
	// test returning null

	// test returning boolean
	function testReturnBool() {
	    $date = new QDate(2007,3,24);
	    $this->assertTrue((gettype($date->setDate(2007,3,24)) == "boolean"), "Value returned is not boolean type, ".gettype($date->setDate(2007,3,24))." detected!");
	    $this->assertTrue(($date->setDate(2007,3,24) == true), "Value returned is wrong!");
	    echo "\ntesting bool passed";
	}

	// test returning object
	function testReturnObject() {
	    $parent = new QObject();
	    $object = new QObject($parent);
	    $parent__ = $object->parent();
	    $this->assertTrue(($parent === $parent__),"Object returned by QObject->parent() is not the same as parent!");
	    echo "\ntesting objects passed";
	}
// ???
	// test returning a new object
	function testReturnNewObject() {
	    $date = new QDate(2007,3,24);
	    $date__ = $date->addDays(2);
	    $this->assertFalse(($date === $date__),"new Object returned by QObject->parent() is the same as parent!");
	    echo "\ntesting new objects passed";
	}

	// test returning string
	function testReturnQString() {
	    $object = new QObject();
	    $object->setObjectName("hello");
	    $string = $object->objectName();
	    $this->assertTrue(is_object($string), "String is not a QString!");
	    $this->assertEquals($string->toAscii(), "hello", "Return object does not contain the same text!");
	    echo "\ntesting QString as return passed";
	}

	// try to give a QString as argument
	function testAddQString() {
	    $object = new QObject();
	    $object->setObjectName(new QString("hello string"));
	    $s = $object->objectName();
	    $this->assertEquals($s->toAscii(),"hello string", "Return object does not contain the same text!");
	    echo "\ntesting QString as argument passed";
	}

	// try to append a QString to a QString
	function testQStringAppendObject() {
	    $s = new QString("hello");
	    $t = new QString(" world");
	    $s->append($t);
	    $this->assertEquals($s->__toString(), "hello world", "Could not append QString to QString!");
	    echo "\ntesting QString::append(new QString(\"hello\")) passed";
	}

	// test methods of an derivated object
	function testUnknownMethod() {
	    $date = new QObject();
	    $foo = new foo($date);
	    $foo->parent();
	    $foo->testMethod();
//	    $foo->___();	// method not defined
	    echo "\ntesting derivated object passed";
	}

    }    
    
?>