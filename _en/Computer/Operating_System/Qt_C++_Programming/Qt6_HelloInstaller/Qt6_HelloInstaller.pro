# Qt6_HelloInstaller.pro
# Author: bss9395
# Update: 2025-08-02T10:11:00+08@China-GuangDong-ZhanJiang+08


TEMPLATE  = aux
INSTALLER = HelloWorld_installer    #生成的安装文件名，MusicPlayer_installer.exe

INPUT = $$PWD/config/config.xml $$PWD/packages
demo.input = INPUT
demo.output = $$INSTALLER
demo.commands = binarycreator -c $$PWD/config/config.xml -p $$PWD/packages ${QMAKE_FILE_OUT}
demo.CONFIG += target_predeps no_link combine
QMAKE_EXTRA_COMPILERS += demo
