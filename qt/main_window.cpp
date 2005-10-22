/*
 * PHP-Qt - The PHP language bindings for Qt
 *
 * Copyright (C) 2005 Thomas Moenicke <tm@ippfp.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <iostream>
using namespace std;

#include <QApplication>

#include "php_qt.h"


int argc__;
char *argv__[1];



/**
 *  Constructor
 */ 

ZEND_METHOD(QApplication,__construct){

    QApplication *app;
    app = new QApplication(argc__, argv__);
    PHP_QT_REGISTER(app);

}

ZEND_METHOD(QApplication,exec){

    QApplication* app = (QApplication*) PHP_QT_FETCH();
    app->exec();

}
