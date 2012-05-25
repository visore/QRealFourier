@echo off
setlocal enableextensions enabledelayedexpansion

set mingw_directory=C:\QtSDK\mingw\bin
set qt_directory=C:\QtSDK\Desktop\Qt\4.7.4\mingw
set setup_factory_directory="C:\Program Files (x86)\Setup Factory 9"

set source_directory=C:\Users\GOOmuckel\Documents\Uni\Masters\code\Visore\code
set build_directory=%source_directory%\..\..\build
set install_directory=%source_directory%\..\..\install

set PATH=%PATH%;%mingw_directory%;%qt_directory%\include\QtCore;%source_directory%\external\bass\libraries\32bit

set cmake=false;
set build=false;
set run=false;
set package=false;

:loop
if "%1"=="" goto continue
	if "%1" == "cmake" set cmake=true;
	if "%1" == "build" set build=true;
	if "%1" == "run" set run=true;
	if "%1" == "package" set package=true;
shift
goto loop
:continue

if %cmake%==true (
	rmdir /S /Q %build_directory%
	mkdir %build_directory%
	cd %build_directory%

	rmdir /S /Q %install_directory%
	mkdir %install_directory%

	cmake -G "MinGW Makefiles" --build %build_directory% -D ARCHITECTURE=32bit -D CMAKE_INSTALL_PREFIX=%install_directory% -DCMAKE_BUILD_TYPE=Release %source_directory%
)

if %build%==true (
	cd %build_directory%
	mingw32-make.exe -j 4 install -j 4
	cd %install_directory%
	del /S lib*.a

	mkdir %install_directory%\external\qt
	mkdir %install_directory%\external\mingw

	copy %mingw_directory%\mingwm10.dll %install_directory%\external\mingw
	copy %mingw_directory%\libgcc_s_dw2-1.dll %install_directory%\external\mingw

	copy %qt_directory%\bin\QtCore4.dll %install_directory%\external\qt
	copy %qt_directory%\bin\QtGui4.dll %install_directory%\external\qt
)

if %run%==true (
	cd %install_directory%
	start launcher.exe
)

if %package%==true (
	cd %setup_factory_directory%
	SUFDesign.exe %source_directory%\..\installer\windows\Visore.suf
)