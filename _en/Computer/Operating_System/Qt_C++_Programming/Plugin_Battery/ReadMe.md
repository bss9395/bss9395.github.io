/* ReadME.md
Author: BSS9395
Update: 2022-07-24T00:17:00+08@China-Shanghai+08
Design: Plugin_Battery
Encode: UTF-8
System: Qt 5.14.2
*/

### Setups to Rebuild

1. Compile this project in Release Mode with MSVC2017_32.
2. Copy plugin_battery.dll and plugin_battery.lib to folders:
    D:/Qt/Qt5.14.2/5.14.2/msvc2017_32/plugins/designer/
    D:/Qt/Qt5.14.2/Tools/QtCreator/bin/plugins/designer/
3. Restart Qt Creator, and create a new project.
4. Copy plugin_battery.dll and plugin_battery.lib and Widget_Battery.h to a new folder named `include` under the new project.
5. Right click the new project, then add plugin_battery.lib to the new project by `Add Library`.
6. Compile the new project in Release Mode with MSVC2017_32.
