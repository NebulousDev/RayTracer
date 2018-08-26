@echo off

:: Variables
set OutputDir           = "./bin/ray.exe"
set IntermediateDir     = "./build/"
set MainClass           = "./src/ray.cpp"

:: Setup Environemnt
if not defined DevEnvDir (
    pushd "B:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
    call vcvarsall.bat
    popd
)

if not exist "build" mkdir "build"
if not exist "bin" mkdir "bin"

:: Compile
echo Building...

cl -Zi -Od -MTd -nologo -fp:fast -Fe"./build/ray.exe" -Fo"./build/" -Fd"./build/" "./src/ray.cpp"

copy "build/ray.exe" "bin"

echo Complete.

PAUSE