/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/
/*
 * Copyright (C) 2005
 * Thomas Moenicke <tm@ippfp.org>,
 * Jean-Luc Gyger <jean_luc.gyger@freesurf.ch>
 *
*/
/* $Id: header,v 1.15 2004/01/08 16:46:52 sniper Exp $ */

#ifndef PHP_PHP_QT_H
#define PHP_PHP_QT_H

extern zend_module_entry php_qt_module_entry;
#define phpext_php_qt_ptr &php_qt_module_entry

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(php_qt);
PHP_MSHUTDOWN_FUNCTION(php_qt);
PHP_RINIT_FUNCTION(php_qt);
PHP_RSHUTDOWN_FUNCTION(php_qt);
PHP_MINFO_FUNCTION(php_qt);

PHP_FUNCTION(confirm_php_qt_compiled);	/* For testing, remove later. */

/* emulate SIGNAL(), SLOT() macros */
PHP_FUNCTION(SIGNAL);
PHP_FUNCTION(SLOT);
    



/* QAbstractButton */
ZEND_METHOD(QAbstractButton, QAbstractButton);
ZEND_METHOD(QAbstractButton, text);
ZEND_METHOD(QAbstractButton, icon);
ZEND_METHOD(QAbstractButton, iconSize);
ZEND_METHOD(QAbstractButton, shortcut);
ZEND_METHOD(QAbstractButton, isCheckable);
ZEND_METHOD(QAbstractButton, isChecked);
ZEND_METHOD(QAbstractButton, isDown);
ZEND_METHOD(QAbstractButton, autoRepeat);
ZEND_METHOD(QAbstractButton, autoExclusive);
ZEND_METHOD(QAbstractButton, group);
ZEND_METHOD(QAbstractButton, animateClick);
ZEND_METHOD(QAbstractButton, click);
ZEND_METHOD(QAbstractButton, toggle);
ZEND_METHOD(QAbstractButton, staticMetaObject);
ZEND_METHOD(QAbstractButton, tr);
ZEND_METHOD(QAbstractButton, trUtf8);

/* QAbstractSlider */
ZEND_METHOD(QAbstractSlider, QAbstractSlider);
ZEND_METHOD(QAbstractSlider, orientation);
ZEND_METHOD(QAbstractSlider, minimum);
ZEND_METHOD(QAbstractSlider, maximum);
ZEND_METHOD(QAbstractSlider, setRange);
ZEND_METHOD(QAbstractSlider, singleStep);
ZEND_METHOD(QAbstractSlider, pageStep);
ZEND_METHOD(QAbstractSlider, hasTracking);
ZEND_METHOD(QAbstractSlider, isSliderDown);
ZEND_METHOD(QAbstractSlider, sliderPosition);
ZEND_METHOD(QAbstractSlider, invertedAppearance);
ZEND_METHOD(QAbstractSlider, invertedControls);
ZEND_METHOD(QAbstractSlider, value);
ZEND_METHOD(QAbstractSlider, triggerAction);
ZEND_METHOD(QAbstractSlider, staticMetaObject);
ZEND_METHOD(QAbstractSlider, trUtf8);
ZEND_METHOD(QAbstractSlider, setRepeatAction);
ZEND_METHOD(QAbstractSlider, repeatAction);

/* QActionEvent */
ZEND_METHOD(QActionEvent, action);
ZEND_METHOD(QActionEvent, before);

/* QApplication */
ZEND_METHOD(QApplication, isSessionRestored);
ZEND_METHOD(QApplication, sessionId);
ZEND_METHOD(QApplication, sessionKey);
ZEND_METHOD(QApplication, setInputContext);
ZEND_METHOD(QApplication, inputContext);
ZEND_METHOD(QApplication, notify);
ZEND_METHOD(QApplication, staticMetaObject);
ZEND_METHOD(QApplication, trUtf8);
ZEND_METHOD(QApplication, type);
ZEND_METHOD(QApplication, style);
ZEND_METHOD(QApplication, setStyle);
ZEND_METHOD(QApplication, setStyle);
ZEND_METHOD(QApplication, colorSpec);
ZEND_METHOD(QApplication, setColorSpec);
ZEND_METHOD(QApplication, overrideCursor);
ZEND_METHOD(QApplication, setOverrideCursor);
ZEND_METHOD(QApplication, changeOverrideCursor);
ZEND_METHOD(QApplication, restoreOverrideCursor);
ZEND_METHOD(QApplication, palette);
ZEND_METHOD(QApplication, palette);
ZEND_METHOD(QApplication, palette);
ZEND_METHOD(QApplication, setPalette);
ZEND_METHOD(QApplication, font);
ZEND_METHOD(QApplication, setFont);
ZEND_METHOD(QApplication, fontMetrics);
ZEND_METHOD(QApplication, windowIcon);
ZEND_METHOD(QApplication, allWidgets);
ZEND_METHOD(QApplication, topLevelWidgets);
ZEND_METHOD(QApplication, desktop);
ZEND_METHOD(QApplication, activePopupWidget);
ZEND_METHOD(QApplication, activeModalWidget);
ZEND_METHOD(QApplication, clipboard);
ZEND_METHOD(QApplication, focusWidget);
ZEND_METHOD(QApplication, activeWindow);
ZEND_METHOD(QApplication, setActiveWindow);
ZEND_METHOD(QApplication, widgetAt);
ZEND_METHOD(QApplication, widgetAt);
ZEND_METHOD(QApplication, topLevelAt);
ZEND_METHOD(QApplication, topLevelAt);
ZEND_METHOD(QApplication, syncX);
ZEND_METHOD(QApplication, beep);
ZEND_METHOD(QApplication, keyboardModifiers);
ZEND_METHOD(QApplication, mouseButtons);
ZEND_METHOD(QApplication, setDesktopSettingsAware);
ZEND_METHOD(QApplication, desktopSettingsAware);
ZEND_METHOD(QApplication, cursorFlashTime);
ZEND_METHOD(QApplication, setDoubleClickInterval);
ZEND_METHOD(QApplication, doubleClickInterval);
ZEND_METHOD(QApplication, keyboardInputInterval);
ZEND_METHOD(QApplication, setWheelScrollLines);
ZEND_METHOD(QApplication, wheelScrollLines);
ZEND_METHOD(QApplication, globalStrut);
ZEND_METHOD(QApplication, setStartDragTime);
ZEND_METHOD(QApplication, startDragTime);
ZEND_METHOD(QApplication, setStartDragDistance);
ZEND_METHOD(QApplication, startDragDistance);
ZEND_METHOD(QApplication, layoutDirection);
ZEND_METHOD(QApplication, isRightToLeft);
ZEND_METHOD(QApplication, isLeftToRight);
ZEND_METHOD(QApplication, isEffectEnabled);
ZEND_METHOD(QApplication, setEffectEnabled);
ZEND_METHOD(QApplication, exec);
ZEND_METHOD(QApplication, setQuitOnLastWindowClosed);
ZEND_METHOD(QApplication, quitOnLastWindowClosed);
ZEND_METHOD(QApplication, closeAllWindows);
ZEND_METHOD(QApplication, aboutQt);
ZEND_METHOD(QApplication, event);

/* QBoxLayout */
ZEND_METHOD(QBoxLayout, QBoxLayout);
ZEND_METHOD(QBoxLayout, direction);
ZEND_METHOD(QBoxLayout, setDirection);
ZEND_METHOD(QBoxLayout, addSpacing);
ZEND_METHOD(QBoxLayout, addStretch);
ZEND_METHOD(QBoxLayout, addWidget);
ZEND_METHOD(QBoxLayout, addLayout);
ZEND_METHOD(QBoxLayout, addStrut);
ZEND_METHOD(QBoxLayout, addItem);
ZEND_METHOD(QBoxLayout, insertSpacing);
ZEND_METHOD(QBoxLayout, insertStretch);
ZEND_METHOD(QBoxLayout, insertWidget);
ZEND_METHOD(QBoxLayout, insertLayout);
ZEND_METHOD(QBoxLayout, setStretchFactor);
ZEND_METHOD(QBoxLayout, setStretchFactor);
ZEND_METHOD(QBoxLayout, sizeHint);
ZEND_METHOD(QBoxLayout, minimumSize);
ZEND_METHOD(QBoxLayout, maximumSize);
ZEND_METHOD(QBoxLayout, hasHeightForWidth);
ZEND_METHOD(QBoxLayout, heightForWidth);
ZEND_METHOD(QBoxLayout, minimumHeightForWidth);
ZEND_METHOD(QBoxLayout, expandingDirections);
ZEND_METHOD(QBoxLayout, invalidate);
ZEND_METHOD(QBoxLayout, itemAt);
ZEND_METHOD(QBoxLayout, takeAt);
ZEND_METHOD(QBoxLayout, count);
ZEND_METHOD(QBoxLayout, setGeometry);
ZEND_METHOD(QBoxLayout, staticMetaObject);
ZEND_METHOD(QBoxLayout, tr);
ZEND_METHOD(QBoxLayout, trUtf8);
ZEND_METHOD(QBoxLayout, insertItem);
ZEND_METHOD(QChar, digitValue);
ZEND_METHOD(QChar, toLower);
ZEND_METHOD(QChar, toUpper);
ZEND_METHOD(QChar, category);
ZEND_METHOD(QChar, direction);
ZEND_METHOD(QChar, joining);
ZEND_METHOD(QChar, hasMirrored);
ZEND_METHOD(QChar, isLower);
ZEND_METHOD(QChar, isUpper);
ZEND_METHOD(QChar, mirroredChar);
ZEND_METHOD(QChar, decomposition);
ZEND_METHOD(QChar, decompositionTag);
ZEND_METHOD(QChar, combiningClass);
ZEND_METHOD(QChar, unicodeVersion);
ZEND_METHOD(QChar, toAscii);
ZEND_METHOD(QChar, toLatin1);
ZEND_METHOD(QChar, unicode);
ZEND_METHOD(QChar, unicode);
ZEND_METHOD(QChar, isNull);
ZEND_METHOD(QChar, isPrint);
ZEND_METHOD(QChar, isPunct);
ZEND_METHOD(QChar, isSpace);
ZEND_METHOD(QChar, isMark);
ZEND_METHOD(QChar, isLetter);
ZEND_METHOD(QChar, isNumber);
ZEND_METHOD(QChar, isLetterOrNumber);
ZEND_METHOD(QChar, isDigit);
ZEND_METHOD(QChar, isSymbol);
ZEND_METHOD(QChar, cell);
ZEND_METHOD(QChar, row);
ZEND_METHOD(QChar, setCell);
ZEND_METHOD(QChar, setRow);
ZEND_METHOD(QChar, fromAscii);
ZEND_METHOD(QChar, fromLatin1);
ZEND_METHOD(QCharRef, isNull);
ZEND_METHOD(QCharRef, isPrint);
ZEND_METHOD(QCharRef, isPunct);
ZEND_METHOD(QCharRef, isSpace);
ZEND_METHOD(QCharRef, isMark);
ZEND_METHOD(QCharRef, isLetter);
ZEND_METHOD(QCharRef, isNumber);
ZEND_METHOD(QCharRef, isLetterOrNumber);
ZEND_METHOD(QCharRef, isDigit);
ZEND_METHOD(QCharRef, digitValue);
ZEND_METHOD(QCharRef, toLower);
ZEND_METHOD(QCharRef, toUpper);
ZEND_METHOD(QCharRef, category);
ZEND_METHOD(QCharRef, direction);
ZEND_METHOD(QCharRef, joining);
ZEND_METHOD(QCharRef, hasMirrored);
ZEND_METHOD(QCharRef, mirroredChar);
ZEND_METHOD(QCharRef, decomposition);
ZEND_METHOD(QCharRef, decompositionTag);
ZEND_METHOD(QCharRef, combiningClass);
ZEND_METHOD(QCharRef, unicodeVersion);
ZEND_METHOD(QCharRef, cell);
ZEND_METHOD(QCharRef, row);
ZEND_METHOD(QCharRef, setCell);
ZEND_METHOD(QCharRef, setRow);
ZEND_METHOD(QCharRef, toAscii);
ZEND_METHOD(QCharRef, toLatin1);
ZEND_METHOD(QCharRef, unicode);

/* QClipboardEvent */
ZEND_METHOD(QClipboardEvent, data);

/* QCloseEvent */

/* QContextMenuEvent */
ZEND_METHOD(QContextMenuEvent, x);
ZEND_METHOD(QContextMenuEvent, y);
ZEND_METHOD(QContextMenuEvent, globalX);
ZEND_METHOD(QContextMenuEvent, globalY);
ZEND_METHOD(QContextMenuEvent, pos);
ZEND_METHOD(QContextMenuEvent, globalPos);
ZEND_METHOD(QContextMenuEvent, reason);

/* QCoreApplication */
ZEND_METHOD(QCoreApplication, QCoreApplication);
ZEND_METHOD(QCoreApplication, bool);
ZEND_METHOD(QCoreApplication, setEventFilter);
ZEND_METHOD(QCoreApplication, staticMetaObject);
ZEND_METHOD(QCoreApplication, tr);
ZEND_METHOD(QCoreApplication, trUtf8);
ZEND_METHOD(QCoreApplication, argc);
ZEND_METHOD(QCoreApplication, argv);
ZEND_METHOD(QCoreApplication, organizationDomain);
ZEND_METHOD(QCoreApplication, organizationName);
ZEND_METHOD(QCoreApplication, applicationName);
ZEND_METHOD(QCoreApplication, instance);
ZEND_METHOD(QCoreApplication, exec);
ZEND_METHOD(QCoreApplication, processEvents);
ZEND_METHOD(QCoreApplication, processEvents);
ZEND_METHOD(QCoreApplication, exit);
ZEND_METHOD(QCoreApplication, sendPostedEvents);
ZEND_METHOD(QCoreApplication, sendPostedEvents);
ZEND_METHOD(QCoreApplication, removePostedEvents);
ZEND_METHOD(QCoreApplication, hasPendingEvents);
ZEND_METHOD(QCoreApplication, startingUp);
ZEND_METHOD(QCoreApplication, closingDown);
ZEND_METHOD(QCoreApplication, applicationDirPath);
ZEND_METHOD(QCoreApplication, applicationFilePath);
ZEND_METHOD(QCoreApplication, setLibraryPaths);
ZEND_METHOD(QCoreApplication, libraryPaths);
ZEND_METHOD(QCoreApplication, addLibraryPath);
ZEND_METHOD(QCoreApplication, removeLibraryPath);
ZEND_METHOD(QCoreApplication, installTranslator);
ZEND_METHOD(QCoreApplication, removeTranslator);
ZEND_METHOD(QCoreApplication, translate);
ZEND_METHOD(QCoreApplication, flush);
ZEND_METHOD(QCoreApplication, watchUnixSignal);
ZEND_METHOD(QCoreApplication, quit);
ZEND_METHOD(QCoreApplication, event);
ZEND_METHOD(QDate, isNull);
ZEND_METHOD(QDate, isValid);
ZEND_METHOD(QDate, year);
ZEND_METHOD(QDate, month);
ZEND_METHOD(QDate, day);
ZEND_METHOD(QDate, dayOfWeek);
ZEND_METHOD(QDate, dayOfYear);
ZEND_METHOD(QDate, daysInMonth);
ZEND_METHOD(QDate, daysInYear);
ZEND_METHOD(QDate, weekNumber);
ZEND_METHOD(QDate, toString);
ZEND_METHOD(QDate, toString);
ZEND_METHOD(QDate, setYMD);
ZEND_METHOD(QDate, addDays);
ZEND_METHOD(QDate, addMonths);
ZEND_METHOD(QDate, addYears);
ZEND_METHOD(QDate, daysTo);
ZEND_METHOD(QDate, toJulianDay);
ZEND_METHOD(QDate, shortMonthName);
ZEND_METHOD(QDate, shortDayName);
ZEND_METHOD(QDate, longMonthName);
ZEND_METHOD(QDate, longDayName);
ZEND_METHOD(QDate, currentDate);
ZEND_METHOD(QDate, fromString);
ZEND_METHOD(QDate, fromString);
ZEND_METHOD(QDate, isValid);
ZEND_METHOD(QDate, isLeapYear);
ZEND_METHOD(QDate, gregorianToJulian);
ZEND_METHOD(QDate, julianToGregorian);
ZEND_METHOD(QDate, fromJulianDay);
ZEND_METHOD(QDateTime, QDateTime);
ZEND_METHOD(QDateTime, isNull);
ZEND_METHOD(QDateTime, isValid);
ZEND_METHOD(QDateTime, date);
ZEND_METHOD(QDateTime, time);
ZEND_METHOD(QDateTime, timeSpec);
ZEND_METHOD(QDateTime, toTime_t);
ZEND_METHOD(QDateTime, setDate);
ZEND_METHOD(QDateTime, setTime);
ZEND_METHOD(QDateTime, setTimeSpec);
ZEND_METHOD(QDateTime, setTime_t);
ZEND_METHOD(QDateTime, toString);
ZEND_METHOD(QDateTime, toString);
ZEND_METHOD(QDateTime, addDays);
ZEND_METHOD(QDateTime, addMonths);
ZEND_METHOD(QDateTime, addYears);
ZEND_METHOD(QDateTime, addSecs);
ZEND_METHOD(QDateTime, toTimeSpec);
ZEND_METHOD(QDateTime, toLocalTime);
ZEND_METHOD(QDateTime, toUTC);
ZEND_METHOD(QDateTime, daysTo);
ZEND_METHOD(QDateTime, secsTo);
ZEND_METHOD(QDateTime, currentDateTime);
ZEND_METHOD(QDateTime, fromString);
ZEND_METHOD(QDateTime, fromString);

/* QDragEnterEvent */

/* QDragLeaveEvent */

/* QDragMoveEvent */
ZEND_METHOD(QDragMoveEvent, answerRect);
ZEND_METHOD(QDragMoveEvent, accept);
ZEND_METHOD(QDragMoveEvent, ignore);
ZEND_METHOD(QDragMoveEvent, accept);
ZEND_METHOD(QDragMoveEvent, ignore);

/* QDragResponseEvent */
ZEND_METHOD(QDragResponseEvent, dragAccepted);

/* QDropEvent */
ZEND_METHOD(QDropEvent, pos);
ZEND_METHOD(QDropEvent, mouseButtons);
ZEND_METHOD(QDropEvent, keyboardModifiers);
ZEND_METHOD(QDropEvent, possibleActions);
ZEND_METHOD(QDropEvent, proposedAction);
ZEND_METHOD(QDropEvent, acceptProposedAction);
ZEND_METHOD(QDropEvent, dropAction);
ZEND_METHOD(QDropEvent, setDropAction);
ZEND_METHOD(QDropEvent, source);
ZEND_METHOD(QDropEvent, mimeData);
ZEND_METHOD(QDropEvent, format);
ZEND_METHOD(QDropEvent, encodedData);
ZEND_METHOD(QDropEvent, provides);

/* QFileOpenEvent */
ZEND_METHOD(QFileOpenEvent, file);

/* QFocusEvent */
ZEND_METHOD(QFocusEvent, gotFocus);
ZEND_METHOD(QFocusEvent, lostFocus);
ZEND_METHOD(QFocusEvent, reason);
ZEND_METHOD(QFont, QFont);
ZEND_METHOD(QFont, family);
ZEND_METHOD(QFont, setFamily);
ZEND_METHOD(QFont, pointSize);
ZEND_METHOD(QFont, setPointSize);
ZEND_METHOD(QFont, pointSizeF);
ZEND_METHOD(QFont, setPointSizeF);
ZEND_METHOD(QFont, pixelSize);
ZEND_METHOD(QFont, setPixelSize);
ZEND_METHOD(QFont, weight);
ZEND_METHOD(QFont, setWeight);
ZEND_METHOD(QFont, bold);
ZEND_METHOD(QFont, setBold);
ZEND_METHOD(QFont, setStyle);
ZEND_METHOD(QFont, style);
ZEND_METHOD(QFont, italic);
ZEND_METHOD(QFont, setItalic);
ZEND_METHOD(QFont, underline);
ZEND_METHOD(QFont, setUnderline);
ZEND_METHOD(QFont, overline);
ZEND_METHOD(QFont, setOverline);
ZEND_METHOD(QFont, strikeOut);
ZEND_METHOD(QFont, setStrikeOut);
ZEND_METHOD(QFont, fixedPitch);
ZEND_METHOD(QFont, setFixedPitch);
ZEND_METHOD(QFont, kerning);
ZEND_METHOD(QFont, setKerning);
ZEND_METHOD(QFont, styleHint);
ZEND_METHOD(QFont, styleStrategy);
ZEND_METHOD(QFont, setStyleHint);
ZEND_METHOD(QFont, setStyleStrategy);
ZEND_METHOD(QFont, stretch);
ZEND_METHOD(QFont, setStretch);
ZEND_METHOD(QFont, rawMode);
ZEND_METHOD(QFont, setRawMode);
ZEND_METHOD(QFont, exactMatch);
ZEND_METHOD(QFont, isCopyOf);
ZEND_METHOD(QFont, handle);
ZEND_METHOD(QFont, setRawName);
ZEND_METHOD(QFont, rawName);
ZEND_METHOD(QFont, key);
ZEND_METHOD(QFont, toString);
ZEND_METHOD(QFont, fromString);
ZEND_METHOD(QFont, defaultFamily);
ZEND_METHOD(QFont, lastResortFamily);
ZEND_METHOD(QFont, lastResortFont);
ZEND_METHOD(QFont, resolve);
ZEND_METHOD(QFont, resolve);
ZEND_METHOD(QFont, resolve);
ZEND_METHOD(QFont, substitute);
ZEND_METHOD(QFont, substitutes);
ZEND_METHOD(QFont, substitutions);
ZEND_METHOD(QFont, insertSubstitution);
ZEND_METHOD(QFont, insertSubstitutions);
ZEND_METHOD(QFont, removeSubstitution);
ZEND_METHOD(QFont, initialize);
ZEND_METHOD(QFont, cleanup);
ZEND_METHOD(QFont, cacheStatistics);

/* QFrame */
ZEND_METHOD(QFrame, QFrame);
ZEND_METHOD(QFrame, frameStyle);
ZEND_METHOD(QFrame, setFrameStyle);
ZEND_METHOD(QFrame, frameWidth);
ZEND_METHOD(QFrame, sizeHint);
ZEND_METHOD(QFrame, frameShape);
ZEND_METHOD(QFrame, frameShadow);
ZEND_METHOD(QFrame, lineWidth);
ZEND_METHOD(QFrame, midLineWidth);
ZEND_METHOD(QFrame, frameRect);
ZEND_METHOD(QFrame, staticMetaObject);
ZEND_METHOD(QFrame, tr);
ZEND_METHOD(QFrame, trUtf8);
ZEND_METHOD(QFrame, drawFrame);

/* QGridLayout */
ZEND_METHOD(QGridLayout, QGridLayout);
ZEND_METHOD(QGridLayout, sizeHint);
ZEND_METHOD(QGridLayout, minimumSize);
ZEND_METHOD(QGridLayout, maximumSize);
ZEND_METHOD(QGridLayout, setRowStretch);
ZEND_METHOD(QGridLayout, setColumnStretch);
ZEND_METHOD(QGridLayout, rowStretch);
ZEND_METHOD(QGridLayout, columnStretch);
ZEND_METHOD(QGridLayout, setRowMinimumHeight);
ZEND_METHOD(QGridLayout, setColumnMinimumWidth);
ZEND_METHOD(QGridLayout, rowMinimumHeight);
ZEND_METHOD(QGridLayout, columnMinimumWidth);
ZEND_METHOD(QGridLayout, columnCount);
ZEND_METHOD(QGridLayout, rowCount);
ZEND_METHOD(QGridLayout, cellRect);
ZEND_METHOD(QGridLayout, hasHeightForWidth);
ZEND_METHOD(QGridLayout, heightForWidth);
ZEND_METHOD(QGridLayout, minimumHeightForWidth);
ZEND_METHOD(QGridLayout, expandingDirections);
ZEND_METHOD(QGridLayout, invalidate);
ZEND_METHOD(QGridLayout, addWidget);
ZEND_METHOD(QGridLayout, addWidget);
ZEND_METHOD(QGridLayout, addWidget);
ZEND_METHOD(QGridLayout, addLayout);
ZEND_METHOD(QGridLayout, addLayout);
ZEND_METHOD(QGridLayout, setOriginCorner);
ZEND_METHOD(QGridLayout, originCorner);
ZEND_METHOD(QGridLayout, itemAt);
ZEND_METHOD(QGridLayout, takeAt);
ZEND_METHOD(QGridLayout, count);
ZEND_METHOD(QGridLayout, setGeometry);
ZEND_METHOD(QGridLayout, addItem);
ZEND_METHOD(QGridLayout, setDefaultPositioning);
ZEND_METHOD(QGridLayout, getItemPosition);
ZEND_METHOD(QGridLayout, staticMetaObject);
ZEND_METHOD(QGridLayout, tr);
ZEND_METHOD(QGridLayout, trUtf8);
ZEND_METHOD(QGridLayout, addItem);

/* QHBoxLayout */
ZEND_METHOD(QHBoxLayout, QHBoxLayout);
ZEND_METHOD(QHBoxLayout, staticMetaObject);
ZEND_METHOD(QHBoxLayout, tr);
ZEND_METHOD(QHBoxLayout, trUtf8);

/* QHelpEvent */
ZEND_METHOD(QHelpEvent, x);
ZEND_METHOD(QHelpEvent, y);
ZEND_METHOD(QHelpEvent, globalX);
ZEND_METHOD(QHelpEvent, globalY);
ZEND_METHOD(QHelpEvent, pos);
ZEND_METHOD(QHelpEvent, globalPos);

/* QHideEvent */

/* QHoverEvent */
ZEND_METHOD(QHoverEvent, pos);
ZEND_METHOD(QHoverEvent, oldPos);

/* QIconDragEvent */

/* QInputEvent */
ZEND_METHOD(QInputEvent, modifiers);

/* QInputMethodEvent */
ZEND_METHOD(QInputMethodEvent, setCommitString);
ZEND_METHOD(QInputMethodEvent, preeditString);
ZEND_METHOD(QInputMethodEvent, commitString);
ZEND_METHOD(QInputMethodEvent, replacementStart);
ZEND_METHOD(QInputMethodEvent, replacementLength);

/* QKeyEvent */
ZEND_METHOD(QKeyEvent, key);
ZEND_METHOD(QKeyEvent, modifiers);
ZEND_METHOD(QKeyEvent, text);
ZEND_METHOD(QKeyEvent, isAutoRepeat);
ZEND_METHOD(QKeyEvent, count);

/* QLCDNumber */
ZEND_METHOD(QLCDNumber, QLCDNumber);
ZEND_METHOD(QLCDNumber, smallDecimalPoint);
ZEND_METHOD(QLCDNumber, numDigits);
ZEND_METHOD(QLCDNumber, checkOverflow);
ZEND_METHOD(QLCDNumber, checkOverflow);
ZEND_METHOD(QLCDNumber, mode);
ZEND_METHOD(QLCDNumber, segmentStyle);
ZEND_METHOD(QLCDNumber, value);
ZEND_METHOD(QLCDNumber, intValue);
ZEND_METHOD(QLCDNumber, sizeHint);
ZEND_METHOD(QLCDNumber, setHexMode);
ZEND_METHOD(QLCDNumber, setDecMode);
ZEND_METHOD(QLCDNumber, setOctMode);
ZEND_METHOD(QLCDNumber, setBinMode);
ZEND_METHOD(QLCDNumber, staticMetaObject);
ZEND_METHOD(QLCDNumber, tr);
ZEND_METHOD(QLCDNumber, trUtf8);

/* QLabel */
ZEND_METHOD(QLabel, QLabel);
ZEND_METHOD(QLabel, text);
ZEND_METHOD(QLabel, pixmap);
ZEND_METHOD(QLabel, picture);
ZEND_METHOD(QLabel, movie);
ZEND_METHOD(QLabel, textFormat);
ZEND_METHOD(QLabel, alignment);
ZEND_METHOD(QLabel, wordWrap);
ZEND_METHOD(QLabel, indent);
ZEND_METHOD(QLabel, margin);
ZEND_METHOD(QLabel, hasScaledContents);
ZEND_METHOD(QLabel, sizeHint);
ZEND_METHOD(QLabel, minimumSizeHint);
ZEND_METHOD(QLabel, setBuddy);
ZEND_METHOD(QLabel, buddy);
ZEND_METHOD(QLabel, heightForWidth);
ZEND_METHOD(QLabel, setPicture);
ZEND_METHOD(QLabel, setMovie);
ZEND_METHOD(QLabel, setNum);
ZEND_METHOD(QLabel, setNum);
ZEND_METHOD(QLabel, clear);
ZEND_METHOD(QLabel, staticMetaObject);
ZEND_METHOD(QLabel, tr);
ZEND_METHOD(QLabel, trUtf8);
ZEND_METHOD(QLabel, event);
ZEND_METHOD(QLatin1Char, toLatin1);
ZEND_METHOD(QLatin1Char, unicode);
ZEND_METHOD(QLatin1String, latin1);

/* QLayout */
ZEND_METHOD(QLayout, QLayout);
ZEND_METHOD(QLayout, margin);
ZEND_METHOD(QLayout, spacing);
ZEND_METHOD(QLayout, setAlignment);
ZEND_METHOD(QLayout, setAlignment);
ZEND_METHOD(QLayout, setAlignment);
ZEND_METHOD(QLayout, sizeConstraint);
ZEND_METHOD(QLayout, setMenuBar);
ZEND_METHOD(QLayout, menuBar);
ZEND_METHOD(QLayout, parentWidget);
ZEND_METHOD(QLayout, invalidate);
ZEND_METHOD(QLayout, geometry);
ZEND_METHOD(QLayout, activate);
ZEND_METHOD(QLayout, update);
ZEND_METHOD(QLayout, addWidget);
ZEND_METHOD(QLayout, removeWidget);
ZEND_METHOD(QLayout, removeItem);
ZEND_METHOD(QLayout, expandingDirections);
ZEND_METHOD(QLayout, minimumSize);
ZEND_METHOD(QLayout, maximumSize);
ZEND_METHOD(QLayout, setGeometry);
ZEND_METHOD(QLayout, isEmpty);
ZEND_METHOD(QLayout, totalHeightForWidth);
ZEND_METHOD(QLayout, totalMinimumSize);
ZEND_METHOD(QLayout, totalMaximumSize);
ZEND_METHOD(QLayout, totalSizeHint);
ZEND_METHOD(QLayout, layout);
ZEND_METHOD(QLayout, setEnabled);
ZEND_METHOD(QLayout, isEnabled);
ZEND_METHOD(QLayout, staticMetaObject);
ZEND_METHOD(QLayout, trUtf8);
ZEND_METHOD(QLayout, closestAcceptableSize);
ZEND_METHOD(QLayoutItem, alignment);
ZEND_METHOD(QLayoutItem, setAlignment);

/* QLineEdit */
ZEND_METHOD(QLineEdit, QLineEdit);
ZEND_METHOD(QLineEdit, text);
ZEND_METHOD(QLineEdit, displayText);
ZEND_METHOD(QLineEdit, maxLength);
ZEND_METHOD(QLineEdit, hasFrame);
ZEND_METHOD(QLineEdit, echoMode);
ZEND_METHOD(QLineEdit, isReadOnly);
ZEND_METHOD(QLineEdit, setValidator);
ZEND_METHOD(QLineEdit, validator);
ZEND_METHOD(QLineEdit, sizeHint);
ZEND_METHOD(QLineEdit, minimumSizeHint);
ZEND_METHOD(QLineEdit, cursorPosition);
ZEND_METHOD(QLineEdit, cursorPositionAt);
ZEND_METHOD(QLineEdit, alignment);
ZEND_METHOD(QLineEdit, cursorForward);
ZEND_METHOD(QLineEdit, cursorBackward);
ZEND_METHOD(QLineEdit, cursorWordForward);
ZEND_METHOD(QLineEdit, cursorWordBackward);
ZEND_METHOD(QLineEdit, backspace);
ZEND_METHOD(QLineEdit, del);
ZEND_METHOD(QLineEdit, home);
ZEND_METHOD(QLineEdit, end);
ZEND_METHOD(QLineEdit, isModified);
ZEND_METHOD(QLineEdit, setSelection);
ZEND_METHOD(QLineEdit, hasSelectedText);
ZEND_METHOD(QLineEdit, selectedText);
ZEND_METHOD(QLineEdit, selectionStart);
ZEND_METHOD(QLineEdit, isUndoAvailable);
ZEND_METHOD(QLineEdit, isRedoAvailable);
ZEND_METHOD(QLineEdit, dragEnabled);
ZEND_METHOD(QLineEdit, inputMask);
ZEND_METHOD(QLineEdit, hasAcceptableInput);
ZEND_METHOD(QLineEdit, deselect);
ZEND_METHOD(QLineEdit, insert);
ZEND_METHOD(QLineEdit, createStandardContextMenu);
ZEND_METHOD(QLineEdit, inputMethodQuery);
ZEND_METHOD(QLineEdit, event);
ZEND_METHOD(QLineEdit, clear);
ZEND_METHOD(QLineEdit, selectAll);
ZEND_METHOD(QLineEdit, undo);
ZEND_METHOD(QLineEdit, redo);
ZEND_METHOD(QLineEdit, cut);
ZEND_METHOD(QLineEdit, copy);
ZEND_METHOD(QLineEdit, paste);
ZEND_METHOD(QLineEdit, staticMetaObject);
ZEND_METHOD(QLineEdit, tr);
ZEND_METHOD(QLineEdit, trUtf8);

/* QMouseEvent */
ZEND_METHOD(QMouseEvent, pos);
ZEND_METHOD(QMouseEvent, globalPos);
ZEND_METHOD(QMouseEvent, x);
ZEND_METHOD(QMouseEvent, y);
ZEND_METHOD(QMouseEvent, globalX);
ZEND_METHOD(QMouseEvent, globalY);
ZEND_METHOD(QMouseEvent, button);
ZEND_METHOD(QMouseEvent, buttons);

/* QMoveEvent */
ZEND_METHOD(QMoveEvent, pos);
ZEND_METHOD(QMoveEvent, oldPos);
ZEND_METHOD(QObject, objectName);
ZEND_METHOD(QObject, isWidgetType);
ZEND_METHOD(QObject, signalsBlocked);
ZEND_METHOD(QObject, blockSignals);
ZEND_METHOD(QObject, thread);
ZEND_METHOD(QObject, moveToThread);
ZEND_METHOD(QObject, startTimer);
ZEND_METHOD(QObject, killTimer);
ZEND_METHOD(QObject, children);
ZEND_METHOD(QObject, setParent);
ZEND_METHOD(QObject, installEventFilter);
ZEND_METHOD(QObject, removeEventFilter);
ZEND_METHOD(QObject, connect);
ZEND_METHOD(QObject, disconnect);
ZEND_METHOD(QObject, disconnect);
ZEND_METHOD(QObject, dumpObjectTree);
ZEND_METHOD(QObject, dumpObjectInfo);
ZEND_METHOD(QObject, setProperty);
ZEND_METHOD(QObject, property);
ZEND_METHOD(QObject, setUserData);
ZEND_METHOD(QObject, userData);
ZEND_METHOD(QObject, parent);
ZEND_METHOD(QObject, inherits);
ZEND_METHOD(QObject, deleteLater);
ZEND_METHOD(QObject, staticMetaObject);
ZEND_METHOD(QObject, tr);
ZEND_METHOD(QObject, trUtf8);
ZEND_METHOD(QObject, tr);
ZEND_METHOD(QObject, trUtf8);
ZEND_METHOD(QObject, tr);
ZEND_METHOD(QObject, trUtf8);
ZEND_METHOD(QObject, connect);
ZEND_METHOD(QObject, disconnect);
ZEND_METHOD(QObject, registerUserData);
ZEND_METHOD(QObject, sender);
ZEND_METHOD(QObject, receivers);

/* QPaintEvent */
ZEND_METHOD(QPaintEvent, rect);
ZEND_METHOD(QPaintEvent, region);
ZEND_METHOD(QPainter, QPainter);
ZEND_METHOD(QPainter, device);
ZEND_METHOD(QPainter, begin);
ZEND_METHOD(QPainter, end);
ZEND_METHOD(QPainter, isActive);
ZEND_METHOD(QPainter, initFrom);
ZEND_METHOD(QPainter, setCompositionMode);
ZEND_METHOD(QPainter, compositionMode);
ZEND_METHOD(QPainter, font);
ZEND_METHOD(QPainter, setFont);
ZEND_METHOD(QPainter, fontMetrics);
ZEND_METHOD(QPainter, fontInfo);
ZEND_METHOD(QPainter, setPen);
ZEND_METHOD(QPainter, setPen);
ZEND_METHOD(QPainter, setPen);
ZEND_METHOD(QPainter, pen);
ZEND_METHOD(QPainter, setBrush);
ZEND_METHOD(QPainter, setBrush);
ZEND_METHOD(QPainter, brush);
ZEND_METHOD(QPainter, setBackgroundMode);
ZEND_METHOD(QPainter, backgroundMode);
ZEND_METHOD(QPainter, brushOrigin);
ZEND_METHOD(QPainter, setBrushOrigin);
ZEND_METHOD(QPainter, setBrushOrigin);
ZEND_METHOD(QPainter, setBrushOrigin);
ZEND_METHOD(QPainter, setBackground);
ZEND_METHOD(QPainter, background);
ZEND_METHOD(QPainter, clipRegion);
ZEND_METHOD(QPainter, clipPath);
ZEND_METHOD(QPainter, setClipRect);
ZEND_METHOD(QPainter, setClipRect);
ZEND_METHOD(QPainter, setClipRegion);
ZEND_METHOD(QPainter, setClipPath);
ZEND_METHOD(QPainter, setClipping);
ZEND_METHOD(QPainter, hasClipping);
ZEND_METHOD(QPainter, save);
ZEND_METHOD(QPainter, restore);
ZEND_METHOD(QPainter, setMatrix);
ZEND_METHOD(QPainter, matrix);
ZEND_METHOD(QPainter, deviceMatrix);
ZEND_METHOD(QPainter, resetMatrix);
ZEND_METHOD(QPainter, setMatrixEnabled);
ZEND_METHOD(QPainter, matrixEnabled);
ZEND_METHOD(QPainter, scale);
ZEND_METHOD(QPainter, shear);
ZEND_METHOD(QPainter, rotate);
ZEND_METHOD(QPainter, translate);
ZEND_METHOD(QPainter, translate);
ZEND_METHOD(QPainter, translate);
ZEND_METHOD(QPainter, window);
ZEND_METHOD(QPainter, setWindow);
ZEND_METHOD(QPainter, setWindow);
ZEND_METHOD(QPainter, viewport);
ZEND_METHOD(QPainter, setViewport);
ZEND_METHOD(QPainter, setViewport);
ZEND_METHOD(QPainter, setViewTransformEnabled);
ZEND_METHOD(QPainter, viewTransformEnabled);
ZEND_METHOD(QPainter, strokePath);
ZEND_METHOD(QPainter, fillPath);
ZEND_METHOD(QPainter, drawPath);
ZEND_METHOD(QPainter, drawPoint);
ZEND_METHOD(QPainter, drawPoint);
ZEND_METHOD(QPainter, drawPoint);
ZEND_METHOD(QPainter, drawPoints);
ZEND_METHOD(QPainter, drawPoints);
ZEND_METHOD(QPainter, drawPoints);
ZEND_METHOD(QPainter, drawPoints);
ZEND_METHOD(QPainter, drawLine);
ZEND_METHOD(QPainter, drawLine);
ZEND_METHOD(QPainter, drawLine);
ZEND_METHOD(QPainter, drawLine);
ZEND_METHOD(QPainter, drawLines);
ZEND_METHOD(QPainter, drawLines);
ZEND_METHOD(QPainter, drawLines);
ZEND_METHOD(QPainter, drawLines);
ZEND_METHOD(QPainter, drawRect);
ZEND_METHOD(QPainter, drawRect);
ZEND_METHOD(QPainter, drawRect);
ZEND_METHOD(QPainter, drawRects);
ZEND_METHOD(QPainter, drawEllipse);
ZEND_METHOD(QPainter, drawEllipse);
ZEND_METHOD(QPainter, drawPolyline);
ZEND_METHOD(QPainter, drawPolyline);
ZEND_METHOD(QPainter, drawPolyline);
ZEND_METHOD(QPainter, drawPolyline);
ZEND_METHOD(QPainter, drawPolygon);
ZEND_METHOD(QPainter, drawPolygon);
ZEND_METHOD(QPainter, drawPolygon);
ZEND_METHOD(QPainter, drawPolygon);
ZEND_METHOD(QPainter, drawConvexPolygon);
ZEND_METHOD(QPainter, drawConvexPolygon);
ZEND_METHOD(QPainter, drawConvexPolygon);
ZEND_METHOD(QPainter, drawConvexPolygon);
ZEND_METHOD(QPainter, drawArc);
ZEND_METHOD(QPainter, drawArc);
ZEND_METHOD(QPainter, drawArc);
ZEND_METHOD(QPainter, drawPie);
ZEND_METHOD(QPainter, drawPie);
ZEND_METHOD(QPainter, drawPie);
ZEND_METHOD(QPainter, drawChord);
ZEND_METHOD(QPainter, drawChord);
ZEND_METHOD(QPainter, drawChord);
ZEND_METHOD(QPainter, drawRoundRect);
ZEND_METHOD(QPainter, drawRoundRect);
ZEND_METHOD(QPainter, drawRoundRect);
ZEND_METHOD(QPainter, drawTiledPixmap);
ZEND_METHOD(QPainter, drawTiledPixmap);
ZEND_METHOD(QPainter, drawTiledPixmap);
ZEND_METHOD(QPainter, drawPicture);
ZEND_METHOD(QPainter, drawPicture);
ZEND_METHOD(QPainter, drawPicture);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawPixmap);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, drawImage);
ZEND_METHOD(QPainter, setLayoutDirection);
ZEND_METHOD(QPainter, layoutDirection);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, drawText);
ZEND_METHOD(QPainter, boundingRect);
ZEND_METHOD(QPainter, boundingRect);
ZEND_METHOD(QPainter, boundingRect);
ZEND_METHOD(QPainter, boundingRect);
ZEND_METHOD(QPainter, drawTextItem);
ZEND_METHOD(QPainter, drawTextItem);
ZEND_METHOD(QPainter, drawTextItem);
ZEND_METHOD(QPainter, fillRect);
ZEND_METHOD(QPainter, fillRect);
ZEND_METHOD(QPainter, fillRect);
ZEND_METHOD(QPainter, eraseRect);
ZEND_METHOD(QPainter, eraseRect);
ZEND_METHOD(QPainter, eraseRect);
ZEND_METHOD(QPainter, setRenderHint);
ZEND_METHOD(QPainter, renderHints);
ZEND_METHOD(QPainter, paintEngine);
ZEND_METHOD(QPainter, setRedirected);
ZEND_METHOD(QPainter, redirected);
ZEND_METHOD(QPainter, restoreRedirected);

/* QPushButton */
ZEND_METHOD(QPushButton, QPushButton);
ZEND_METHOD(QPushButton, sizeHint);
ZEND_METHOD(QPushButton, autoDefault);
ZEND_METHOD(QPushButton, isDefault);
ZEND_METHOD(QPushButton, setMenu);
ZEND_METHOD(QPushButton, menu);
ZEND_METHOD(QPushButton, isFlat);
ZEND_METHOD(QPushButton, showMenu);
ZEND_METHOD(QPushButton, staticMetaObject);
ZEND_METHOD(QPushButton, tr);
ZEND_METHOD(QPushButton, trUtf8);

/* QResizeEvent */
ZEND_METHOD(QResizeEvent, size);
ZEND_METHOD(QResizeEvent, oldSize);

/* QShortcutEvent */
ZEND_METHOD(QShortcutEvent, key);
ZEND_METHOD(QShortcutEvent, shortcutId);
ZEND_METHOD(QShortcutEvent, isAmbiguous);

/* QShowEvent */

/* QSlider */
ZEND_METHOD(QSlider, QSlider);
ZEND_METHOD(QSlider, sizeHint);
ZEND_METHOD(QSlider, minimumSizeHint);
ZEND_METHOD(QSlider, tickPosition);
ZEND_METHOD(QSlider, tickInterval);
ZEND_METHOD(QSlider, event);
ZEND_METHOD(QSlider, staticMetaObject);
ZEND_METHOD(QSlider, tr);
ZEND_METHOD(QSlider, trUtf8);

/* QSpacerItem */
ZEND_METHOD(QSpacerItem, changeSize);
ZEND_METHOD(QSpacerItem, sizeHint);
ZEND_METHOD(QSpacerItem, minimumSize);
ZEND_METHOD(QSpacerItem, maximumSize);
ZEND_METHOD(QSpacerItem, expandingDirections);
ZEND_METHOD(QSpacerItem, isEmpty);
ZEND_METHOD(QSpacerItem, setGeometry);
ZEND_METHOD(QSpacerItem, geometry);
ZEND_METHOD(QSpacerItem, spacerItem);

/* QStatusTipEvent */
ZEND_METHOD(QStatusTipEvent, tip);
ZEND_METHOD(QString, QString);
ZEND_METHOD(QString, size);
ZEND_METHOD(QString, count);
ZEND_METHOD(QString, length);
ZEND_METHOD(QString, isEmpty);
ZEND_METHOD(QString, resize);
ZEND_METHOD(QString, fill);
ZEND_METHOD(QString, truncate);
ZEND_METHOD(QString, chop);
ZEND_METHOD(QString, capacity);
ZEND_METHOD(QString, reserve);
ZEND_METHOD(QString, squeeze);
ZEND_METHOD(QString, unicode);
ZEND_METHOD(QString, data);
ZEND_METHOD(QString, constData);
ZEND_METHOD(QString, detach);
ZEND_METHOD(QString, isDetached);
ZEND_METHOD(QString, clear);
ZEND_METHOD(QString, at);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, arg);
ZEND_METHOD(QString, vsprintf);
ZEND_METHOD(QString, indexOf);
ZEND_METHOD(QString, indexOf);
ZEND_METHOD(QString, lastIndexOf);
ZEND_METHOD(QString, lastIndexOf);
ZEND_METHOD(QString, contains);
ZEND_METHOD(QString, contains);
ZEND_METHOD(QString, count);
ZEND_METHOD(QString, count);
ZEND_METHOD(QString, indexOf);
ZEND_METHOD(QString, lastIndexOf);
ZEND_METHOD(QString, contains);
ZEND_METHOD(QString, count);
ZEND_METHOD(QString, section);
ZEND_METHOD(QString, section);
ZEND_METHOD(QString, section);
ZEND_METHOD(QString, left);
ZEND_METHOD(QString, right);
ZEND_METHOD(QString, mid);
ZEND_METHOD(QString, startsWith);
ZEND_METHOD(QString, startsWith);
ZEND_METHOD(QString, endsWith);
ZEND_METHOD(QString, endsWith);
ZEND_METHOD(QString, leftJustified);
ZEND_METHOD(QString, rightJustified);
ZEND_METHOD(QString, toLower);
ZEND_METHOD(QString, toUpper);
ZEND_METHOD(QString, trimmed);
ZEND_METHOD(QString, simplified);
ZEND_METHOD(QString, insert);
ZEND_METHOD(QString, insert);
ZEND_METHOD(QString, insert);
ZEND_METHOD(QString, append);
ZEND_METHOD(QString, append);
ZEND_METHOD(QString, prepend);
ZEND_METHOD(QString, prepend);
ZEND_METHOD(QString, remove);
ZEND_METHOD(QString, remove);
ZEND_METHOD(QString, remove);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, replace);
ZEND_METHOD(QString, remove);
ZEND_METHOD(QString, split);
ZEND_METHOD(QString, split);
ZEND_METHOD(QString, normalized);
ZEND_METHOD(QString, normalized);
ZEND_METHOD(QString, utf16);
ZEND_METHOD(QString, toAscii);
ZEND_METHOD(QString, toLatin1);
ZEND_METHOD(QString, toUtf8);
ZEND_METHOD(QString, toLocal8Bit);
ZEND_METHOD(QString, setUnicode);
ZEND_METHOD(QString, setUtf16);
ZEND_METHOD(QString, compare);
ZEND_METHOD(QString, localeAwareCompare);
ZEND_METHOD(QString, toShort);
ZEND_METHOD(QString, toUShort);
ZEND_METHOD(QString, toInt);
ZEND_METHOD(QString, toUInt);
ZEND_METHOD(QString, toLong);
ZEND_METHOD(QString, toULong);
ZEND_METHOD(QString, toLongLong);
ZEND_METHOD(QString, toULongLong);
ZEND_METHOD(QString, toFloat);
ZEND_METHOD(QString, toDouble);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, setNum);
ZEND_METHOD(QString, prepend);
ZEND_METHOD(QString, prepend);
ZEND_METHOD(QString, append);
ZEND_METHOD(QString, append);
ZEND_METHOD(QString, begin);
ZEND_METHOD(QString, constBegin);
ZEND_METHOD(QString, end);
ZEND_METHOD(QString, constEnd);
ZEND_METHOD(QString, push_back);
ZEND_METHOD(QString, push_back);
ZEND_METHOD(QString, push_front);
ZEND_METHOD(QString, push_front);
ZEND_METHOD(QString, isNull);
ZEND_METHOD(QString, isSimpleText);
ZEND_METHOD(QString, isRightToLeft);
ZEND_METHOD(QString, fromAscii);
ZEND_METHOD(QString, fromLatin1);
ZEND_METHOD(QString, fromUtf8);
ZEND_METHOD(QString, fromLocal8Bit);
ZEND_METHOD(QString, fromUtf16);
ZEND_METHOD(QString, fromRawData);
ZEND_METHOD(QString, compare);
ZEND_METHOD(QString, localeAwareCompare);
ZEND_METHOD(QString, number);
ZEND_METHOD(QString, number);
ZEND_METHOD(QString, number);
ZEND_METHOD(QString, number);
ZEND_METHOD(QString, number);

/* QTabletEvent */
ZEND_METHOD(QTabletEvent, pos);
ZEND_METHOD(QTabletEvent, globalPos);
ZEND_METHOD(QTabletEvent, hiResGlobalPos);
ZEND_METHOD(QTabletEvent, x);
ZEND_METHOD(QTabletEvent, y);
ZEND_METHOD(QTabletEvent, globalX);
ZEND_METHOD(QTabletEvent, globalY);
ZEND_METHOD(QTabletEvent, hiResGlobalX);
ZEND_METHOD(QTabletEvent, hiResGlobalY);
ZEND_METHOD(QTabletEvent, device);
ZEND_METHOD(QTabletEvent, pointerType);
ZEND_METHOD(QTabletEvent, uniqueId);
ZEND_METHOD(QTabletEvent, pressure);
ZEND_METHOD(QTabletEvent, z);
ZEND_METHOD(QTabletEvent, tangentialPressure);
ZEND_METHOD(QTabletEvent, rotation);
ZEND_METHOD(QTabletEvent, xTilt);
ZEND_METHOD(QTabletEvent, yTilt);
ZEND_METHOD(QTime, isNull);
ZEND_METHOD(QTime, isValid);
ZEND_METHOD(QTime, hour);
ZEND_METHOD(QTime, minute);
ZEND_METHOD(QTime, second);
ZEND_METHOD(QTime, msec);
ZEND_METHOD(QTime, toString);
ZEND_METHOD(QTime, toString);
ZEND_METHOD(QTime, setHMS);
ZEND_METHOD(QTime, addSecs);
ZEND_METHOD(QTime, secsTo);
ZEND_METHOD(QTime, addMSecs);
ZEND_METHOD(QTime, msecsTo);
ZEND_METHOD(QTime, start);
ZEND_METHOD(QTime, restart);
ZEND_METHOD(QTime, elapsed);
ZEND_METHOD(QTime, currentTime);
ZEND_METHOD(QTime, fromString);
ZEND_METHOD(QTime, fromString);
ZEND_METHOD(QTime, isValid);

/* QTimer */
ZEND_METHOD(QTimer, QTimer);
ZEND_METHOD(QTimer, isActive);
ZEND_METHOD(QTimer, timerId);
ZEND_METHOD(QTimer, interval);
ZEND_METHOD(QTimer, isSingleShot);
ZEND_METHOD(QTimer, start);
ZEND_METHOD(QTimer, start);
ZEND_METHOD(QTimer, stop);
ZEND_METHOD(QTimer, staticMetaObject);
ZEND_METHOD(QTimer, tr);
ZEND_METHOD(QTimer, trUtf8);
ZEND_METHOD(QTimer, singleShot);

/* QToolBarChangeEvent */
ZEND_METHOD(QToolBarChangeEvent, toggle);

/* QVBoxLayout */
ZEND_METHOD(QVBoxLayout, QVBoxLayout);
ZEND_METHOD(QVBoxLayout, staticMetaObject);
ZEND_METHOD(QVBoxLayout, tr);
ZEND_METHOD(QVBoxLayout, trUtf8);

/* QWhatsThisClickedEvent */
ZEND_METHOD(QWhatsThisClickedEvent, href);

/* QWheelEvent */
ZEND_METHOD(QWheelEvent, delta);
ZEND_METHOD(QWheelEvent, pos);
ZEND_METHOD(QWheelEvent, globalPos);
ZEND_METHOD(QWheelEvent, x);
ZEND_METHOD(QWheelEvent, y);
ZEND_METHOD(QWheelEvent, globalX);
ZEND_METHOD(QWheelEvent, globalY);
ZEND_METHOD(QWheelEvent, buttons);
ZEND_METHOD(QWheelEvent, orientation);

/* QWidget */
ZEND_METHOD(QWidget, QWidget);
ZEND_METHOD(QWidget, devType);
ZEND_METHOD(QWidget, winId);
ZEND_METHOD(QWidget, style);
ZEND_METHOD(QWidget, setStyle);
ZEND_METHOD(QWidget, isTopLevel);
ZEND_METHOD(QWidget, isWindow);
ZEND_METHOD(QWidget, isModal);
ZEND_METHOD(QWidget, isEnabled);
ZEND_METHOD(QWidget, isEnabledTo);
ZEND_METHOD(QWidget, isEnabledToTLW);
ZEND_METHOD(QWidget, frameGeometry);
ZEND_METHOD(QWidget, geometry);
ZEND_METHOD(QWidget, normalGeometry);
ZEND_METHOD(QWidget, pos);
ZEND_METHOD(QWidget, frameSize);
ZEND_METHOD(QWidget, width);
ZEND_METHOD(QWidget, height);
ZEND_METHOD(QWidget, childrenRect);
ZEND_METHOD(QWidget, childrenRegion);
ZEND_METHOD(QWidget, minimumSize);
ZEND_METHOD(QWidget, maximumSize);
ZEND_METHOD(QWidget, minimumWidth);
ZEND_METHOD(QWidget, minimumHeight);
ZEND_METHOD(QWidget, maximumWidth);
ZEND_METHOD(QWidget, maximumHeight);
ZEND_METHOD(QWidget, sizeIncrement);
ZEND_METHOD(QWidget, baseSize);
ZEND_METHOD(QWidget, setFixedSize);
ZEND_METHOD(QWidget, setFixedSize);
ZEND_METHOD(QWidget, setFixedWidth);
ZEND_METHOD(QWidget, setFixedHeight);
ZEND_METHOD(QWidget, mapToGlobal);
ZEND_METHOD(QWidget, mapFromGlobal);
ZEND_METHOD(QWidget, mapToParent);
ZEND_METHOD(QWidget, mapFromParent);
ZEND_METHOD(QWidget, mapTo);
ZEND_METHOD(QWidget, mapFrom);
ZEND_METHOD(QWidget, window);
ZEND_METHOD(QWidget, topLevelWidget);
ZEND_METHOD(QWidget, palette);
ZEND_METHOD(QWidget, setBackgroundRole);
ZEND_METHOD(QWidget, backgroundRole);
ZEND_METHOD(QWidget, setForegroundRole);
ZEND_METHOD(QWidget, foregroundRole);
ZEND_METHOD(QWidget, font);
ZEND_METHOD(QWidget, fontMetrics);
ZEND_METHOD(QWidget, fontInfo);
ZEND_METHOD(QWidget, cursor);
ZEND_METHOD(QWidget, unsetCursor);
ZEND_METHOD(QWidget, hasMouseTracking);
ZEND_METHOD(QWidget, underMouse);
ZEND_METHOD(QWidget, setMask);
ZEND_METHOD(QWidget, mask);
ZEND_METHOD(QWidget, clearMask);
ZEND_METHOD(QWidget, windowTitle);
ZEND_METHOD(QWidget, windowIcon);
ZEND_METHOD(QWidget, windowIconText);
ZEND_METHOD(QWidget, setWindowRole);
ZEND_METHOD(QWidget, windowRole);
ZEND_METHOD(QWidget, windowOpacity);
ZEND_METHOD(QWidget, isWindowModified);
ZEND_METHOD(QWidget, toolTip);
ZEND_METHOD(QWidget, statusTip);
ZEND_METHOD(QWidget, whatsThis);
ZEND_METHOD(QWidget, accessibleName);
ZEND_METHOD(QWidget, accessibleDescription);
ZEND_METHOD(QWidget, layoutDirection);
ZEND_METHOD(QWidget, unsetLayoutDirection);
ZEND_METHOD(QWidget, isRightToLeft);
ZEND_METHOD(QWidget, isLeftToRight);
ZEND_METHOD(QWidget, isActiveWindow);
ZEND_METHOD(QWidget, activateWindow);
ZEND_METHOD(QWidget, clearFocus);
ZEND_METHOD(QWidget, focusPolicy);
ZEND_METHOD(QWidget, hasFocus);
ZEND_METHOD(QWidget, setFocusProxy);
ZEND_METHOD(QWidget, focusProxy);
ZEND_METHOD(QWidget, contextMenuPolicy);
ZEND_METHOD(QWidget, grabMouse);
ZEND_METHOD(QWidget, grabMouse);
ZEND_METHOD(QWidget, releaseMouse);
ZEND_METHOD(QWidget, grabKeyboard);
ZEND_METHOD(QWidget, releaseKeyboard);
ZEND_METHOD(QWidget, grabShortcut);
ZEND_METHOD(QWidget, releaseShortcut);
ZEND_METHOD(QWidget, setShortcutEnabled);
ZEND_METHOD(QWidget, updatesEnabled);
ZEND_METHOD(QWidget, update);
ZEND_METHOD(QWidget, update);
ZEND_METHOD(QWidget, repaint);
ZEND_METHOD(QWidget, repaint);
ZEND_METHOD(QWidget, stackUnder);
ZEND_METHOD(QWidget, adjustSize);
ZEND_METHOD(QWidget, isVisible);
ZEND_METHOD(QWidget, isVisibleTo);
ZEND_METHOD(QWidget, isHidden);
ZEND_METHOD(QWidget, isMinimized);
ZEND_METHOD(QWidget, isMaximized);
ZEND_METHOD(QWidget, isFullScreen);
ZEND_METHOD(QWidget, windowState);
ZEND_METHOD(QWidget, setWindowState);
ZEND_METHOD(QWidget, overrideWindowState);
ZEND_METHOD(QWidget, sizePolicy);
ZEND_METHOD(QWidget, visibleRegion);
ZEND_METHOD(QWidget, setContentsMargins);
ZEND_METHOD(QWidget, getContentsMargins);
ZEND_METHOD(QWidget, contentsRect);
ZEND_METHOD(QWidget, layout);
ZEND_METHOD(QWidget, updateGeometry);
ZEND_METHOD(QWidget, setParent);
ZEND_METHOD(QWidget, setParent);
ZEND_METHOD(QWidget, scroll);
ZEND_METHOD(QWidget, scroll);
ZEND_METHOD(QWidget, focusWidget);
ZEND_METHOD(QWidget, nextInFocusChain);
ZEND_METHOD(QWidget, acceptDrops);
ZEND_METHOD(QWidget, addAction);
ZEND_METHOD(QWidget, insertAction);
ZEND_METHOD(QWidget, removeAction);
ZEND_METHOD(QWidget, parentWidget);
ZEND_METHOD(QWidget, setWindowFlags);
ZEND_METHOD(QWidget, windowFlags);
ZEND_METHOD(QWidget, overrideWindowFlags);
ZEND_METHOD(QWidget, windowType);
ZEND_METHOD(QWidget, childAt);
ZEND_METHOD(QWidget, childAt);
ZEND_METHOD(QWidget, handle);
ZEND_METHOD(QWidget, setAttribute);
ZEND_METHOD(QWidget, testAttribute);
ZEND_METHOD(QWidget, paintEngine);
ZEND_METHOD(QWidget, ensurePolished);
ZEND_METHOD(QWidget, inputContext);
ZEND_METHOD(QWidget, setInputContext);
ZEND_METHOD(QWidget, isAncestorOf);
ZEND_METHOD(QWidget, setDisabled);
ZEND_METHOD(QWidget, update);
ZEND_METHOD(QWidget, repaint);
ZEND_METHOD(QWidget, setHidden);
ZEND_METHOD(QWidget, show);
ZEND_METHOD(QWidget, hide);
ZEND_METHOD(QWidget, setShown);
ZEND_METHOD(QWidget, showMinimized);
ZEND_METHOD(QWidget, showMaximized);
ZEND_METHOD(QWidget, showFullScreen);
ZEND_METHOD(QWidget, showNormal);
ZEND_METHOD(QWidget, close);
ZEND_METHOD(QWidget, raise);
ZEND_METHOD(QWidget, lower);
ZEND_METHOD(QWidget, staticMetaObject);
ZEND_METHOD(QWidget, trUtf8);
ZEND_METHOD(QWidget, setTabOrder);
ZEND_METHOD(QWidget, mouseGrabber);
ZEND_METHOD(QWidget, keyboardGrabber);
ZEND_METHOD(QWidget, find);
ZEND_METHOD(QWidget, event);
ZEND_METHOD(QWidget, metric);
ZEND_METHOD(QWidget, resetInputContext);
ZEND_METHOD(QWidget, updateMicroFocus);
ZEND_METHOD(QWidget, create);
ZEND_METHOD(QWidget, destroy);
ZEND_METHOD(QWidget, focusNextChild);
ZEND_METHOD(QWidget, focusPreviousChild);

/* QWidgetItem */
ZEND_METHOD(QWidgetItem, sizeHint);
ZEND_METHOD(QWidgetItem, minimumSize);
ZEND_METHOD(QWidgetItem, maximumSize);
ZEND_METHOD(QWidgetItem, expandingDirections);
ZEND_METHOD(QWidgetItem, isEmpty);
ZEND_METHOD(QWidgetItem, setGeometry);
ZEND_METHOD(QWidgetItem, geometry);
ZEND_METHOD(QWidgetItem, hasHeightForWidth);
ZEND_METHOD(QWidgetItem, heightForWidth);

/* QWindowStateChangeEvent */
ZEND_METHOD(QWindowStateChangeEvent, oldState);
/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(php_qt)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(php_qt)
*/

/* In every utility function you add that needs to use variables
   in php_php_qt_globals, call TSRMLS_FETCH(); after declaring other
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PHP_QT_G(variable).  You are
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PHP_QT_G(v) TSRMG(php_qt_globals_id, zend_php_qt_globals *, v)
#else
#define PHP_QT_G(v) (php_qt_globals.v)
#endif

#endif	/* PHP_PHP_QT_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

    