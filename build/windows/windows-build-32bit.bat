@echo off
setlocal enableextensions enabledelayedexpansion

set mingw_directory=C:\Qt\Qt5.0.2\Tools\MinGW\bin
set qt_directory=C:\Qt\Qt5.0.2\5.0.2\mingw47_32
set source_directory=C:\QRealFourier\code

set build_directory=%source_directory%\..\..\build
set install_directory=%source_directory%\..\..\install

set PATH=%PATH%;%mingw_directory%;%qt_directory%\include\QtCore

set configure=false;
set build=false;
set install=false;

:loop
if "%1"=="" goto continue
	if "%1" == "configure" set configure=true;
	if "%1" == "build" set build=true;
	if "%1" == "install" set install=true;
shift
goto loop
:continue

if %configure%==true (
	rmdir /S /Q %build_directory%
	mkdir %build_directory%
	cd %build_directory%

	rmdir /S /Q %install_directory%
	mkdir %install_directory%

	cmake -G "MinGW Makefiles" --build %build_directory% -DCMAKE_INSTALL_PREFIX=%install_directory% -DCMAKE_BUILD_TYPE=Release -DQT_DIRECTORY=%qt_directory% %source_directory%
)

if %build%==true (
	cd %build_directory%
	mingw32-make.exe -j 4
)

if %install%==true (
	cd %build_directory%
	mingw32-make.exe -j 4 install -j 4

	copy %mingw_directory%\mingwm10.dll %install_directory%
	copy %mingw_directory%\libgcc_s_dw2-1.dll %install_directory%
	copy %qt_directory%\bin\Qt5Core.dll %install_directory%
)
