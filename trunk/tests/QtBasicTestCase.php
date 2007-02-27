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

    class foo {
	const a = "a";
	const b = 24;
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
	}

	// try to fetch a numeric constant
	function testFetchNumConstant() {
	    $this->assertEquals(foo::b, 24, "Could not fetch numeric constant!");
	}

	// try to fetch a Qt constant
	function testQtConstant() {
	    $this->assertTrue(Qt::Horizontal == 1, "Could not fetch constant from Qt!");
	}

	// test the __toString() method
	function testQString() {
	    $s = new QString("hello");
	    $this->assertEquals($s->__toString(), "hello", "Could not handle __toString()!");
	}

	// try to append a PHP string to a QString
	function testQStringAppendString() {
	    $s = new QString("hello");
	    $s->append(" world");
	    $this->assertEquals($s->__toString(), "hello world", "Could append simple string to QString!");
	}

	// try to create an instance of QApplication
	function testQApplication() {
	    $this->app = new QApplication(&$this->argc,$this->argv);
	    $this->assertTrue(is_object($this->app), "Could not create an instance of QApplication!");
	}

	// try to get a QString as return value
	function testReturnQString() {
	    $object = new QObject();
	    $object->setText("hello");
	    $string = $object->getText();
	    $this->assertTrue(is_object($string), "Value returned by getText() is not valid.");
	    $this->assertEquals($string->__toString(), "hello", "Return object does not contain the same text!");
	}

	// try to give a QString as argument
/*	function testAddQString() {
	    $object = new QObject();
	    $string = new QString("hello");
//	    $object->setText($string);
	    $s = $object->getText();
	    $this->assertEquals($s->__toString(),"hello", "Return object does not contain the same text!");
	}
*/
	// try to get an return Object
	// try to give an object as argument
	// try to give an object as argument, modify it, give it back and check if it is the same

	// try to append a QString to a QString
/*	function testQStringAppendObject() {
	    $s = new QString("hello");
	    $t = new QString(" world");
	    $s->append($t);
	    $this->assertEquals($s->__toString(), "hello world", "Could not append QString to QString!");
	}
*/
    

    }    
    
?>