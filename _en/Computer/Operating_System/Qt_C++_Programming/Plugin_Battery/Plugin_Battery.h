/* Plugin_Battery.h
Author: BSS9395
Update: 2022-07-24T00:17:00+08@China-Shanghai+08
Design: Plugin_Battery
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef   Plugin_Battery_h
#define   Plugin_Battery_h

#define   Header_h
#include "Common.h"
#include "Widget_Battery.h"

class Plugin_Battery : public QObject, public QDesignerCustomWidgetInterface {
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")

public:
    bool _initialized = false;

public:
    Plugin_Battery(QObject *parent = nullptr)
        : QObject(parent) {
        System::Logging(__FUNCTION__);
        _initialized = false;
    }

    void initialize(QDesignerFormEditorInterface *core) {
        System::Logging(__FUNCTION__);
        if (_initialized) {
            return;
        }

        // Add extension registrations, etc. here

        _initialized = true;
    }

    bool isInitialized() const {
        System::Logging(__FUNCTION__);
        return _initialized;
    }

    QWidget *createWidget(QWidget *parent) {
        System::Logging(__FUNCTION__);
        return new Widget_Battery(parent);
    }

    QString name() const {
        System::Logging(__FUNCTION__);
        return QLatin1String("Widget_Battery");
    }

    QString group() const {
        System::Logging(__FUNCTION__);
        return QLatin1String("Custom");
    }

    QIcon icon() const {
        System::Logging(__FUNCTION__);
        return QIcon(":/images/battery_0_bar.png");
    }

    QString toolTip() const {
        System::Logging(__FUNCTION__);
        return QLatin1String("");
    }

    QString whatsThis() const {
        System::Logging(__FUNCTION__);
        return QLatin1String("");
    }

    bool isContainer() const {
        System::Logging(__FUNCTION__);
        return false;
    }

    QString domXml() const {
        System::Logging(__FUNCTION__);
        return QLatin1String(R"(
                                <widget class="Widget_Battery" name="widget_Battery">
                                </widget>
                             )");
    }

    QString includeFile() const {
        System::Logging(__FUNCTION__);
        return QLatin1String("Widget_Battery.h");
    }
};

#endif // Plugin_Battery_h
