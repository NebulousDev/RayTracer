@echo off

:: Setup Environemnt
if not defined DevEnvDir (
    pushd "B:\Program Files (x86)\Microsoft Visual Studio 14.0\VC"
    call vcvarsall.bat
    popd
)

devenv /debugexe "./build/ray.exe"