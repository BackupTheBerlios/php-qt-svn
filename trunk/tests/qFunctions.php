<?php

if(!extension_loaded('php_qt')) {
	dl('php_qt.' . PHP_SHLIB_SUFFIX);
}

echo "\nTesting qAbs:\n";
echo "qAbs(4) = ".qAbs(4)."\n";
echo "qAbs(-4) = ".qAbs(-4)."\n";
echo "qAbs(4.3) = ".qAbs(4.3)."\n";
echo "qAbs(-4.3) = ".qAbs(-4.3)."\n";

echo "\nTesting qRound:\n";
echo "qRound(1) = ".qRound(1)."\n";
echo "qRound(4.5) = ".qRound(4.5)."\n";
echo "qRound(-4.47837289) = ".qRound(-4.478327289)."\n";

echo "\nTesting qRound64:\n";
echo "qRound64(1) = ".qRound64(1)."\n";
echo "qRound64(4.5) = ".qRound64(4.5)."\n";
echo "qRound64(-4.47837289) = ".qRound64(-4.478327289)."\n";

echo "\nTesting qMin:\n";
echo "qMin(4,5) = ".qMin(4,5)."\n";
echo "qMin(7,-1.567) = ".qMin(7,-1.567)."\n";

echo "\nTesting qMax:\n";
echo "qMax(4,5) = ".qMax(4,5)."\n";
echo "qMax(7,-1.567) = ".qMax(7,-1.567)."\n";

echo "\nTesting qBound:\n";
echo "qBound(3,4,5) = ".qBound(3,4,5)."\n";
echo "qBound(4,3,5) = ".qBound(4,3,5)."\n";
echo "qBound(4,6,5) = ".qBound(4,6,5)."\n";

echo "\nTesting qPrintable:\n";
echo "qPrintable(\"bob\") = ".qPrintable("bob")."\n";
echo "qPrintable(new QString(\"fred\") = ".qPrintable(new QString("fred"))."\n";
echo 'qPrintable(45) = '.qPrintable(45)."\n";
class test {}
echo "qPrintable(new test) = ".qPrintable(new test)."\n";

echo "\nTesting qDebug:\n";
qDebug("This is a debug message");

echo "Testing qWarning:\n";
qWarning("This is a warning message");

echo "Testing qCritical:\n";
qCritical("This is a fatal error");

?>
