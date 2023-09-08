
### 导出动态库

在Visual Studio项目》Properties》General》Configuration Type》Dynamic Library(.dll)。
在Visual Studio项目》Properties》Preprocessor Definitions》添加LIBRARY_EXPORT。

### 导入动态库

创建文件夹Library，将Library_Export.lib放入其中。
在Visual Studio项目》Properties》VC++ Directories》Library Directories》添加Library目录。
在Visual Studio项目》Properties》Linker》Input》Additional Dependencies》添加Library_Export.lib。
将Library_Export.dll放在.exe运行目录。
