<?php
    /****************************************************************
    **
    ** Qt Calculator
    **
    ** http://doc.trolltech.com/4.0/widgets-calculator.html
    **
    ****************************************************************/

    require_once("button.php");

    class Calculator extends QDialog {
    
        var $sumInMemory = 0.0;
        var $sumSoFar = 0.0;
        var $factorSoFar = 0.0;
        var $pendingAdditiveOperator;
        var $pendingMultiplicativeOperator;
        var $waitingForOperand = true;

        var $display;           /// QLineEdit

        var $NumDigitButtons = 10;
        var $digitButtons;      /// Array of buttons

        /// Buttons
        var $pointButton;
        var $changeSignButton;
        var $backspaceButton;
        var $clearButton;
        var $clearAllButton;
        var $clearMemoryButton;
        var $readMemoryButton;
        var $setMemoryButton;
        var $addToMemoryButton;

        var $divisionButton;
        var $timesButton;
        var $minusButton;
        var $plusButton;
        var $squareRootButton;
        var $powerButton;
        var $reciprocalButton;
        var $equalButton;

        var $slots = array(
            "digitClicked()",
            "unaryOperatorClicked()",
            "additiveOperatorClicked()",
            "multiplicativeOperatorClicked()",
            "equalClicked()",
            "pointClicked()",
            "changeSignClicked()",
            "backspaceClicked()",
            "clear()",
            "clearAll()",
            "clearMemory()",
            "read_Memory()",
            "setMemory()",
            "addToMemory()"
        );
        var $signals = array("");

        function __construct() {

            parent::__construct();

            $this->pendingAdditiveOperator = new QString();
            $this->pendingMultiplicativeOperator = new QString();

            $this->display = new QLineEdit("0");
            $this->display->setReadOnly(true);
            $this->display->setAlignment(QT_ALIGNMENT_ALIGNRIGHT);
            $this->display->setMaxLength(15);
            $this->display->installEventFilter($this);

            for ($i = 0; $i < $this->NumDigitButtons; ++$i) {
                    $this->digitButtons[$i] = $this->createButton($i."", SLOT("digitClicked()"));
            }

            $this->pointButton = $this->createButton(".", SLOT("pointClicked()"));
            $this->changeSignButton = $this->createButton("\261", SLOT("changeSignClicked()"));

            $this->backspaceButton = $this->createButton("Backspace", SLOT("backspaceClicked()"));
            $this->clearButton = $this->createButton("Clear", SLOT("clear()"));
            $this->clearAllButton = $this->createButton("Clear All", SLOT("clearAll()"));

            $this->clearMemoryButton = $this->createButton("MC", SLOT("clearMemory()"));
            $this->readMemoryButton = $this->createButton("MR", SLOT("read_Memory()"));
            $this->setMemoryButton = $this->createButton("MS", SLOT("setMemory()"));
            $this->addToMemoryButton = $this->createButton("M+", SLOT("addToMemory()"));

            $this->divisionButton = $this->createButton("\367", SLOT("multiplicativeOperatorClicked()"));

            $this->timesButton = $this->createButton("\327", SLOT("multiplicativeOperatorClicked()"));
            $this->minusButton = $this->createButton("-", SLOT("additiveOperatorClicked()"));
            $this->plusButton = $this->createButton("+", SLOT("additiveOperatorClicked()"));

            $this->squareRootButton = $this->createButton("Sqrt", SLOT("unaryOperatorClicked()"));
            $this->powerButton = $this->createButton("x\262", SLOT("unaryOperatorClicked()"));
            $this->reciprocalButton = $this->createButton("1/x", SLOT("unaryOperatorClicked()"));
            $this->equalButton = $this->createButton("=", SLOT("equalClicked()"));

            $this->mainLayout = new QGridLayout($this);

//            $this->mainLayout->setSizeConstraint("QLayout::SetFixedSize");

            $this->mainLayout->addWidget($this->display, 0, 0, 1, 6);
            $this->mainLayout->addWidget($this->backspaceButton, 1, 0, 1, 2);
            $this->mainLayout->addWidget($this->clearButton, 1, 2, 1, 2);
            $this->mainLayout->addWidget($this->clearAllButton, 1, 4, 1, 2);
            $this->mainLayout->addWidget($this->clearMemoryButton, 2, 0);
            $this->mainLayout->addWidget($this->readMemoryButton, 3, 0);
            $this->mainLayout->addWidget($this->setMemoryButton, 4, 0);
            $this->mainLayout->addWidget($this->addToMemoryButton, 5, 0);

            for ($i = 1; $i < $this->NumDigitButtons; ++$i) {

                    $row = ceil(((8 - ($i+1))) / 3) + 2;
                    $column = ceil((($i-1) % 3)) + 1;

                    $this->mainLayout->addWidget($this->digitButtons[$i], (int) $row, (int) $column);

            }

            $this->mainLayout->addWidget($this->digitButtons[0], 5, 1);
            $this->mainLayout->addWidget($this->pointButton, 5, 2);
            $this->mainLayout->addWidget($this->changeSignButton, 5, 3);

            $this->mainLayout->addWidget($this->divisionButton, 2, 4);
            $this->mainLayout->addWidget($this->timesButton, 3, 4);
            $this->mainLayout->addWidget($this->minusButton, 4, 4);
            $this->mainLayout->addWidget($this->plusButton, 5, 4);
                                
            $this->mainLayout->addWidget($this->squareRootButton, 2, 5);
            $this->mainLayout->addWidget($this->powerButton, 3, 5);
            $this->mainLayout->addWidget($this->reciprocalButton, 4, 5);
            $this->mainLayout->addWidget($this->equalButton, 5, 5);

            $this->setLayout($this->mainLayout);
            $this->setWindowTitle(new QString("Calculator"));

        }

        function createButton($text, $member)
        {
            $button = new Button($text);
            $this->connect($button, SIGNAL("clicked()"), $this, $member);
            return $button;
        }

        function digitClicked()
        {

            $clickedButton = qobject_cast($this->sender(),new QToolButton());
            $digitValue = $clickedButton->text()->toInt();
            if ($this->display->text() == "0" && $digitValue == 0.0)
                return;

            if ($this->waitingForOperand) {
                $this->display->clear();
                $this->waitingForOperand = false;
            }

            $new_value = new QString();
            $display_text = $this->display->text();
            $number = QString::number($digitValue);

            $new_value->append($display_text);
            $new_value->append($number);

            $this->display->setText($new_value);
        }

        function unaryOperatorClicked()
        {
            $clickedButton = qobject_cast($this->sender(), new Button(""));
            $clickedOperator = $clickedButton->text();
            $operand = $this->display->text()->toDouble();
            $result;

            if ($clickedOperator->toAscii() == $this->tr("Sqrt")->toAscii()) {
                if ($operand < 0.0) {
                    $this->abortOperation();
                    return;
                }
                $result = sqrt($operand);
            } else if ($clickedOperator->toAscii() == $this->tr("x\262")->toAscii()) {
                $result = pow($operand, 2.0);
            } else if ($clickedOperator->toAscii() == $this->tr("1/x")->toAscii()) {
                if ($operand == 0.0) {
                    $this->abortOperation();
                    return;
                }
                $result = 1.0 / $operand;
            }

            $this->display->setText(QString::number($result));
            $this->waitingForOperand = true;
        }

        function additiveOperatorClicked()
        {
            $clickedButton = qobject_cast($this->sender(), new Button(""));
            $clickedOperator = $clickedButton->text();

            $operand = $this->display->text()->toDouble();

            if (!$this->pendingMultiplicativeOperator->isEmpty()) {
                if (!$this->calculate($operand, $this->pendingMultiplicativeOperator)) {
                    $this->abortOperation();
                    return;
                }
                $this->display->setText(QString::number($this->factorSoFar));
                $operand = $this->factorSoFar;
                $this->factorSoFar = 0.0;
                $this->pendingMultiplicativeOperator->clear();
            }

            if (!$this->pendingAdditiveOperator->isEmpty()) {
                if (!$this->calculate(operand, $this->pendingAdditiveOperator)) {
                    $this->abortOperation();
                    return;
                }
                $this->display->setText(QString::number($this->sumSoFar));
            } else {
                $this->sumSoFar = $operand;
            }

            $this->pendingAdditiveOperator = $clickedOperator;
            $this->waitingForOperand = true;

        }

        function multiplicativeOperatorClicked()
        {
            $clickedButton = qobject_cast($this->sender(), new Button(""));
            $clickedOperator = $clickedButton->text();

            $operand = $this->display->text()->toDouble();
                                
            if (!$this->pendingMultiplicativeOperator->isEmpty()) {
                if (!$this->calculate($operand, $this->pendingMultiplicativeOperator)) {
                    $this->abortOperation();
                    return;
                }
                $this->display->setText(QString::number($this->factorSoFar));
            } else {
                $this->factorSoFar = $operand;
            }
            $this->pendingMultiplicativeOperator = $clickedOperator;
            $this->waitingForOperand = true;
        }

        function equalClicked()
        {
            $operand = $this->display->text()->toDouble();

            if (!$this->pendingMultiplicativeOperator->isEmpty()) {
                if (!$this->calculate($operand, $this->pendingMultiplicativeOperator)) {
                    $this->abortOperation();
                    return;
                }
                $operand = $this->factorSoFar;
                $this->factorSoFar = 0.0;
                $this->pendingMultiplicativeOperator->clear();
            }
            if (!$this->pendingAdditiveOperator->isEmpty()) {
                if (!$this->calculate($operand, $this->pendingAdditiveOperator)) {
                    $this->abortOperation();
                    return;
                }
                $this->pendingAdditiveOperator->clear();
            } else {
                $this->sumSoFar = $operand;
            }

            $this->display->setText(QString::number($this->sumSoFar));
            $this->sumSoFar = 0.0;
            $this->waitingForOperand = true;                                                                          
        }

        function pointClicked()
        {
            if ($this->waitingForOperand)
                $this->display->setText("0");
            if (!$this->display->text()->contains(".")){

                $new_value = $this->display->text();
                $new_value->append(".");
                $this->display->setText($new_value);
                
            }
            $this->waitingForOperand = false;
        }

        function changeSignClicked()
        {
            $text = $this->display->text();
            $value = $text->toDouble();

            if ($value > 0.0) {
                $text->prepend("-");
            } else if ($value < 0.0) {
                $text->remove(0, 1);
            }
            $this->display->setText($text);
        }

        function backspaceClicked()
        {
            if ($this->waitingForOperand)
                return;

            $text = $this->display->text();
            $text->chop(1);
            if ($text->isEmpty()) {
                $text = "0";
                $this->waitingForOperand = true;
            }
            $this->display->setText($text);
        }

        function clear()
        {
            if ($this->waitingForOperand)
                return;

            $this->display->setText("0");
            $this->waitingForOperand = true;
        }

        function clearAll()
        {
            $this->sumSoFar = 0.0;
            $this->factorSoFar = 0.0;
            $this->pendingAdditiveOperator->clear();
            $this->pendingMultiplicativeOperator->clear();
            $this->display->setText("0");
            $this->waitingForOperand = true;
        }

        function clearMemory()
        {
            $this->sumInMemory = 0.0;
        }
                    
        function read_Memory()
        {
            $this->display->setText(QString::number($this->sumInMemory));
            $this->waitingForOperand = true;
        }

        function setMemory()
        {
            $this->equalClicked();
            $this->sumInMemory = $this->display->text()->toDouble();
        }
                            
        function addToMemory()
        {
            $this->equalClicked();
            $this->sumInMemory += $this->display->text()->toDouble();
        }

        function abortOperation()
        {
            $this->clearAll();
            $this->display->setText($this->tr("####"));
        }

        function calculate($rightOperand, $pendingOperator)
        {
            if ($pendingOperator->toAscii() == "+") {
                $this->sumSoFar += $rightOperand;
            } else if ($pendingOperator->toAscii() == "-") {
                $this->sumSoFar -= $rightOperand;
            } else if ($pendingOperator->toAscii() == "\327") {
                $this->factorSoFar *= $rightOperand;
            } else if ($pendingOperator->toAscii() == "\367") {
                if ($rightOperand == 0.0)
                    return false;
                $this->factorSoFar /= $rightOperand;
            }
            return true;
        }
    }

?>