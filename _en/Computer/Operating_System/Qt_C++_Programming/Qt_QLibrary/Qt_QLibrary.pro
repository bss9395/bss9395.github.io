################################################################################
Root         = $$PWD/
Root_Working = $$Root/Working/
Root_Deploy  = $$Root/Deploy/
cache(Root        , set)
cache(Root_Working, set)
cache(Root_Deploy , set)
message([Qt_QLibrary:Root        ] $$Root        )
message([Qt_QLibrary:Root_Working] $$Root_Working)
message([Qt_QLibrary:Root_Deploy ] $$Root_Deploy )
message([Qt_QLibrary:QMAKE_HOST.arch] $${QMAKE_HOST.arch})
message([Qt_QLibrary:QT_ARCH        ] $$QT_ARCH          )

################################################################################
## pro文件名即项目名
## pro文件名应当与其文件夹名保持相同
TEMPLATE = subdirs
SUBDIRS += Depend
SUBDIRS += Common
SUBDIRS += Shared
SUBDIRS += Plugin
SUBDIRS += Employ
Shared.depends = Depend Common
Plugin.depends = Depend Common
Employ.depends = Shared Plugin

Depend.file = Depend/Depend.pro
Common.file = Common/Common.pro
Shared.file = Shared/Shared.pro
Plugin.file = Plugin/Plugin.pro
Employ.file = Employ/Employ.pro

################################################################################
## 项目通用目录结构
## Qt_QLibrary/
## |- Depend/
##    |- Section/
##       |- Section.h
##       |- Section.cpp
##    |- Depend.h
##    |- Depend.cpp
## |- Common/
##    |- Common.h
##    |- Common.cpp
## |- Shared/
##    |- Shared.h
##    |- Shared.cpp
## |- Plugin/
##    |- Plugin.h
##    |- Plugin.cpp
## |- Employ/
##    |- Main.cpp
## |- Working/
##    |- Depend/
##       |- Section/
##          |- Section.h
##       |- Depend.h
##       |- Depend.lib
##       |- Depend.pdb
##       |- Depend.dll
##    |- Common/
##       |- Common.h
##       |- Common.lib
##       |- Common.pdb
##       |- Common.dll
##    |- Shared/
##       |- Shared.h
##       |- Shared.lib
##       |- Shared.pdb
##       |- Shared.dll
##    |- Plugin/
##       |- Plugin.h
##       |- Plugin.lib
##       |- Plugin.pdb
##       |- Plugin.dll
##    |- Employ/
##       |- Employ.exe
## |- Deploy/
##    |- Depend.dll
##    |- Common.dll
##    |- Shared.dll
##    |- Plugin.dll
##    |- Employ.exe
