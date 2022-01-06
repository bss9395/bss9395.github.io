/* Common.h
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#ifndef Common_h
#define Common_h

#define CRT_SECURE_NO_WARNINGS
#include <QtGlobal>
#include <QDebug>
#include <QString>
#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QFontDialog>
#include <QTextCodec>
#include <QAudioDeviceInfo>

#include <iostream>
#include <fstream>
#include <string>
#include <list>

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef wchar_t wide;

#ifdef QT_VERSION_STR
typedef QString String;
#else
typedef std::string String;
#endif

#include "ui_Notebook.h"
#include "Format.h"
#include "System.h"
#include "Notebook.h"

#endif // Common_h
