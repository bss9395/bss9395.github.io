@echo off
set PATH=D:\Qt\Qt5.12.11\Tools\mingw730_64\bin;D:\Qt\Qt5.12.11\5.12.11\mingw73_64\bin;%PATH%
set QTDIR=D:\Qt\Qt5.12.11\5.12.11\mingw73_64;%QTDIR%

:: 打印PATH
echo PATH=%PATH%   
:: 打印QTDIR
echo QTDIR=%QTDIR%  

echo ================================================================================
"./Qt_QLocalServer.exe"
pause
