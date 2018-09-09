@echo off

:: Variables
set OutputDir           = "./build/ray.exe"
set IntermediateDir     = "./build/"

:: Setup Environemnt
if not defined DevEnvDir (
    pushd "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
    call vcvarsall.bat
    popd
)

if not exist "build" mkdir "build"
if not exist "bin" mkdir "bin"

:: Compile
echo Building...

cl -Zi -Od -MTd -nologo -fp:fast -Fe"./build/ray.exe" -Fo"./build/" -Fd"./build/" "./src/*.cpp"

copy "build/ray.exe" "bin"

echo Complete.

PAUSE