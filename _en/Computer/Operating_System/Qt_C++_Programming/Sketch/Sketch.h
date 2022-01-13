/* Common.h
Author: BSS9395
Update: 2022-01-11T21:16:00+08@China-Guangdong-Shenzhen+08
Design: Sketch
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Sketch_h
#define Sketch_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Sketch.h"

class Sketch : public QMainWindow {
    Q_OBJECT

public:
    static inline iptr _Enum_Folder = 1000;
    static inline iptr _Enum_File = 1001;
    static inline iptr _Enum_Path = 0;
    static inline iptr _Enum_Type = 1;
    static inline iptr _Enum_Absolute = -1;
    static inline iptr _Enum_Relative = -2;
    static inline iptr _hitted = false;

public:
    static inline QString _type = QString(R"(
*.APNG;;*.BMP;;*.CDR;;*.CMX;;*.DIB;;*.DICOM;;*.DJVU;;*.DNG;;*.EMF;;*.EMZ;;*.EPS;;
*.GIF;;*.J2K;;*.JP2;;*.JPG;;*.ODG;;*.OTG;;*.PNG;;*.SVG;;*.SVGZ;;*.TGA;;*.TIFF;;*.WEBP;;*.WMF;;*.WMZ
)");

public:
    Ui::Sketch *_ui = nullptr;
    QIcon _Icon_Folder = QIcon(":/images/folder.png"); // note: initialize after QGuiApplication.
    QIcon _Icon_Image = QIcon(":/images/image.png");   // note: initialize after QGuiApplication.
    QPixmap _pixmap = QPixmap(":/images/M31.png");
    double _scale = 1.0;

public:
    Sketch(QWidget *parent = nullptr);
    ~Sketch();

public:
    QTreeWidgetItem *Traverse(QTreeWidget *widget, QTreeWidgetItem *tree, const QChar *directory, iptr &hitted = _hitted);
    QTreeWidgetItem *Attach_Folder(QTreeWidget *widget, const QString &directory, iptr &hitted = _hitted);
    iptr Attach_Files(QTreeWidgetItem *folder, const QString &directory, const QStringList &filenames, iptr &hitted = _hitted);
};
#endif // Sketch_h
