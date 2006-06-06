

#include "php_qt.h"
bool
inherits(zend_class_entry * ace, uint objectId, int recursion)
{

/// QAbstractButton, ID: 1 
  if (ace == QAbstractButton_ce_ptr) {
    switch (objectId) {
    case 1:                    //QAbstractButton
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QAbstractSlider, ID: 2 
  if (ace == QAbstractSlider_ce_ptr) {
    switch (objectId) {
    case 2:                    //QAbstractSlider
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QActionEvent, ID: 3 
  if (ace == QActionEvent_ce_ptr) {
    switch (objectId) {
    case 3:                    //QActionEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QApplication, ID: 4 
  if (ace == QApplication_ce_ptr) {
    switch (objectId) {
    case 4:                    //QApplication
      return true;
    case 12:                   //QCoreApplication
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QBoxLayout, ID: 5 
  if (ace == QBoxLayout_ce_ptr) {
    switch (objectId) {
    case 5:                    //QBoxLayout
      return true;
    case 41:                   //QLayout
      return true;
    case 42:                   //QLayoutItem
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QChar, ID: 6 
  if (ace == QChar_ce_ptr) {
    switch (objectId) {
    case 6:                    //QChar
      return true;
    default:
      return false;
    }
  }
/// QCharRef, ID: 7 
  if (ace == QCharRef_ce_ptr) {
    switch (objectId) {
    case 7:                    //QCharRef
      return true;
    default:
      return false;
    }
  }
/// QChildEvent, ID: 8 
  if (ace == QChildEvent_ce_ptr) {
    switch (objectId) {
    case 8:                    //QChildEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QClipboardEvent, ID: 9 
  if (ace == QClipboardEvent_ce_ptr) {
    switch (objectId) {
    case 9:                    //QClipboardEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QCloseEvent, ID: 10 
  if (ace == QCloseEvent_ce_ptr) {
    switch (objectId) {
    case 10:                   //QCloseEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QContextMenuEvent, ID: 11 
  if (ace == QContextMenuEvent_ce_ptr) {
    switch (objectId) {
    case 11:                   //QContextMenuEvent
      return true;
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QCoreApplication, ID: 12 
  if (ace == QCoreApplication_ce_ptr) {
    switch (objectId) {
    case 12:                   //QCoreApplication
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QDate, ID: 13 
  if (ace == QDate_ce_ptr) {
    switch (objectId) {
    case 13:                   //QDate
      return true;
    default:
      return false;
    }
  }
/// QDateTime, ID: 14 
  if (ace == QDateTime_ce_ptr) {
    switch (objectId) {
    case 14:                   //QDateTime
      return true;
    default:
      return false;
    }
  }
/// QDialog, ID: 15 
  if (ace == QDialog_ce_ptr) {
  
    switch (objectId) {
    case 15:                   //QDialog
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QDragEnterEvent, ID: 16 
  if (ace == QDragEnterEvent_ce_ptr) {
    switch (objectId) {
    case 16:                   //QDragEnterEvent
      return true;
    case 18:                   //QDragMoveEvent
      return true;
    case 20:                   //QDropEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QDragLeaveEvent, ID: 17 
  if (ace == QDragLeaveEvent_ce_ptr) {
    switch (objectId) {
    case 17:                   //QDragLeaveEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QDragMoveEvent, ID: 18 
  if (ace == QDragMoveEvent_ce_ptr) {
    switch (objectId) {
    case 18:                   //QDragMoveEvent
      return true;
    case 20:                   //QDropEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QDragResponseEvent, ID: 19 
  if (ace == QDragResponseEvent_ce_ptr) {
    switch (objectId) {
    case 19:                   //QDragResponseEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QDropEvent, ID: 20 
  if (ace == QDropEvent_ce_ptr) {
    switch (objectId) {
    case 20:                   //QDropEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QEvent, ID: 21 
  if (ace == QEvent_ce_ptr) {
    switch (objectId) {
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QFileOpenEvent, ID: 22 
  if (ace == QFileOpenEvent_ce_ptr) {
    switch (objectId) {
    case 22:                   //QFileOpenEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QFocusEvent, ID: 23 
  if (ace == QFocusEvent_ce_ptr) {
    switch (objectId) {
    case 23:                   //QFocusEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QFont, ID: 24 
  if (ace == QFont_ce_ptr) {
    switch (objectId) {
    case 24:                   //QFont
      return true;
    default:
      return false;
    }
  }
/// QFrame, ID: 25 
  if (ace == QFrame_ce_ptr) {
    switch (objectId) {
    case 25:                   //QFrame
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QGridLayout, ID: 26 
  if (ace == QGridLayout_ce_ptr) {
    switch (objectId) {
    case 26:                   //QGridLayout
      return true;
    case 41:                   //QLayout
      return true;
    case 42:                   //QLayoutItem
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QHBoxLayout, ID: 27 
  if (ace == QHBoxLayout_ce_ptr) {
    switch (objectId) {
    case 27:                   //QHBoxLayout
      return true;
    case 5:                    //QBoxLayout
      return true;
    case 41:                   //QLayout
      return true;
    case 42:                   //QLayoutItem
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QHelpEvent, ID: 28 
  if (ace == QHelpEvent_ce_ptr) {
    switch (objectId) {
    case 28:                   //QHelpEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QHideEvent, ID: 29 
  if (ace == QHideEvent_ce_ptr) {
    switch (objectId) {
    case 29:                   //QHideEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QHoverEvent, ID: 30 
  if (ace == QHoverEvent_ce_ptr) {
    switch (objectId) {
    case 30:                   //QHoverEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QIconDragEvent, ID: 31 
  if (ace == QIconDragEvent_ce_ptr) {
    switch (objectId) {
    case 31:                   //QIconDragEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QInputEvent, ID: 32 
  if (ace == QInputEvent_ce_ptr) {
    switch (objectId) {
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QInputMethodEvent, ID: 33 
  if (ace == QInputMethodEvent_ce_ptr) {
    switch (objectId) {
    case 33:                   //QInputMethodEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// Attribute, ID: 34 
  if (ace == Attribute_ce_ptr) {
    switch (objectId) {
    case 34:                   //Attribute
      return true;
    default:
      return false;
    }
  }
/// QInternal, ID: 35 
  if (ace == QInternal_ce_ptr) {
    switch (objectId) {
    case 35:                   //QInternal
      return true;
    default:
      return false;
    }
  }
/// QKeyEvent, ID: 36 
  if (ace == QKeyEvent_ce_ptr) {
    switch (objectId) {
    case 36:                   //QKeyEvent
      return true;
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QLCDNumber, ID: 37 
  if (ace == QLCDNumber_ce_ptr) {
    switch (objectId) {
    case 37:                   //QLCDNumber
      return true;
    case 25:                   //QFrame
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QLabel, ID: 38 
  if (ace == QLabel_ce_ptr) {
    switch (objectId) {
    case 38:                   //QLabel
      return true;
    case 25:                   //QFrame
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QLatin1Char, ID: 39 
  if (ace == QLatin1Char_ce_ptr) {
    switch (objectId) {
    case 39:                   //QLatin1Char
      return true;
    default:
      return false;
    }
  }
/// QLatin1String, ID: 40 
  if (ace == QLatin1String_ce_ptr) {
    switch (objectId) {
    case 40:                   //QLatin1String
      return true;
    default:
      return false;
    }
  }
/// QLayout, ID: 41 
  if (ace == QLayout_ce_ptr) {
    switch (objectId) {
    case 41:                   //QLayout
      return true;
    case 42:                   //QLayoutItem
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QLayoutItem, ID: 42 
  if (ace == QLayoutItem_ce_ptr) {
    switch (objectId) {
    case 42:                   //QLayoutItem
      return true;
    default:
      return false;
    }
  }
/// QLineEdit, ID: 43 
  if (ace == QLineEdit_ce_ptr) {
    switch (objectId) {
    case 43:                   //QLineEdit
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QMouseEvent, ID: 44 
  if (ace == QMouseEvent_ce_ptr) {
    switch (objectId) {
    case 44:                   //QMouseEvent
      return true;
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QMoveEvent, ID: 45 
  if (ace == QMoveEvent_ce_ptr) {
    switch (objectId) {
    case 45:                   //QMoveEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QObject, ID: 46 
  if (ace == QObject_ce_ptr) {
    switch (objectId) {
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QObjectData, ID: 47 
  if (ace == QObjectData_ce_ptr) {
    switch (objectId) {
    case 47:                   //QObjectData
      return true;
    default:
      return false;
    }
  }
/// QObjectUserData, ID: 48 
  if (ace == QObjectUserData_ce_ptr) {
    switch (objectId) {
    case 48:                   //QObjectUserData
      return true;
    default:
      return false;
    }
  }
/// QPaintDevice, ID: 49 
  if (ace == QPaintDevice_ce_ptr) {
    switch (objectId) {
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QPaintEvent, ID: 50 
  if (ace == QPaintEvent_ce_ptr) {
    switch (objectId) {
    case 50:                   //QPaintEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QPainter, ID: 51 
  if (ace == QPainter_ce_ptr) {
    switch (objectId) {
    case 51:                   //QPainter
      return true;
    default:
      return false;
    }
  }
/// QPushButton, ID: 52 
  if (ace == QPushButton_ce_ptr) {
    switch (objectId) {
    case 52:                   //QPushButton
      return true;
    case 1:                    //QAbstractButton
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QResizeEvent, ID: 53 
  if (ace == QResizeEvent_ce_ptr) {
    switch (objectId) {
    case 53:                   //QResizeEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QShortcutEvent, ID: 54 
  if (ace == QShortcutEvent_ce_ptr) {
    switch (objectId) {
    case 54:                   //QShortcutEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QShowEvent, ID: 55 
  if (ace == QShowEvent_ce_ptr) {
    switch (objectId) {
    case 55:                   //QShowEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QSlider, ID: 56 
  if (ace == QSlider_ce_ptr) {
    switch (objectId) {
    case 56:                   //QSlider
      return true;
    case 2:                    //QAbstractSlider
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QSpacerItem, ID: 57 
  if (ace == QSpacerItem_ce_ptr) {
    switch (objectId) {
    case 57:                   //QSpacerItem
      return true;
    case 42:                   //QLayoutItem
      return true;
    default:
      return false;
    }
  }
/// QStatusTipEvent, ID: 58 
  if (ace == QStatusTipEvent_ce_ptr) {
    switch (objectId) {
    case 58:                   //QStatusTipEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QString, ID: 59 
  if (ace == QString_ce_ptr) {
    switch (objectId) {
    case 59:                   //QString
      return true;
    default:
      return false;
    }
  }
/// Data, ID: 60 
  if (ace == Data_ce_ptr) {
    switch (objectId) {
    case 60:                   //Data
      return true;
    default:
      return false;
    }
  }
/// Null, ID: 61 
  if (ace == Null_ce_ptr) {
    switch (objectId) {
    case 61:                   //Null
      return true;
    default:
      return false;
    }
  }
/// QTabletEvent, ID: 62 
  if (ace == QTabletEvent_ce_ptr) {
    switch (objectId) {
    case 62:                   //QTabletEvent
      return true;
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QTime, ID: 63 
  if (ace == QTime_ce_ptr) {
    switch (objectId) {
    case 63:                   //QTime
      return true;
    default:
      return false;
    }
  }
/// QTimer, ID: 64 
  if (ace == QTimer_ce_ptr) {
    switch (objectId) {
    case 64:                   //QTimer
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QTimerEvent, ID: 65 
  if (ace == QTimerEvent_ce_ptr) {
    switch (objectId) {
    case 65:                   //QTimerEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QToolBarChangeEvent, ID: 66 
  if (ace == QToolBarChangeEvent_ce_ptr) {
    switch (objectId) {
    case 66:                   //QToolBarChangeEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QToolButton, ID: 67 
  if (ace == QToolButton_ce_ptr) {
    switch (objectId) {
    case 67:                   //QToolButton
      return true;
    case 1:                    //QAbstractButton
      return true;
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QVBoxLayout, ID: 68 
  if (ace == QVBoxLayout_ce_ptr) {
    switch (objectId) {
    case 68:                   //QVBoxLayout
      return true;
    case 5:                    //QBoxLayout
      return true;
    case 41:                   //QLayout
      return true;
    case 42:                   //QLayoutItem
      return true;
    case 46:                   //QObject
      return true;
    default:
      return false;
    }
  }
/// QWhatsThisClickedEvent, ID: 69 
  if (ace == QWhatsThisClickedEvent_ce_ptr) {
    switch (objectId) {
    case 69:                   //QWhatsThisClickedEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QWheelEvent, ID: 70 
  if (ace == QWheelEvent_ce_ptr) {
    switch (objectId) {
    case 70:                   //QWheelEvent
      return true;
    case 32:                   //QInputEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// QWidget, ID: 71 
  if (ace == QWidget_ce_ptr) {
    switch (objectId) {
    case 71:                   //QWidget
      return true;
    case 46:                   //QObject
      return true;
    case 49:                   //QPaintDevice
      return true;
    default:
      return false;
    }
  }
/// QWidgetData, ID: 72 
  if (ace == QWidgetData_ce_ptr) {
    switch (objectId) {
    case 72:                   //QWidgetData
      return true;
    default:
      return false;
    }
  }
/// QWidgetItem, ID: 73 
  if (ace == QWidgetItem_ce_ptr) {
    switch (objectId) {
    case 73:                   //QWidgetItem
      return true;
    case 42:                   //QLayoutItem
      return true;
    default:
      return false;
    }
  }
/// QWindowStateChangeEvent, ID: 74 
  if (ace == QWindowStateChangeEvent_ce_ptr) {
    switch (objectId) {
    case 74:                   //QWindowStateChangeEvent
      return true;
    case 21:                   //QEvent
      return true;
    default:
      return false;
    }
  }
/// Qt, ID: 75 
  if (ace == Qt_ce_ptr) {
    switch (objectId) {
    case 75:                   //Qt
      return true;
    default:
      return false;
    }
  }
  
  // break recursion
  if(recursion == 10){
    return false;
  }
  inherits(ace->parent, objectId,recursion++);
// final: 
  
}
