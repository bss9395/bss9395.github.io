echo off

echo ================================================================================
xcopy /S /Y "%cd%\Working\Depend\*.dll"   "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Depend\*.so"    "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Common\*.dll"   "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Common\*.so"    "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Shared\*.dll"   "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Shared\*.so"    "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Plugin\*.dll"   "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Plugin\*.so"    "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Employ\*.exe"   "%cd%\Deploy\"
xcopy /S /Y "%cd%\Working\Employ\Employ"  "%cd%\Deploy\"

echo ================================================================================
set PATH=D:\Qt\Qt5.12.11\5.12.11\msvc2017_64\bin;D:\Qt\Qt5.12.11\Tools\msvc2017_64\bin;%PATH%
:: 打印PATH
echo PATH=%PATH%   

echo ================================================================================
cd "%cd%\Deploy\"
".\Employ.exe"
pause
