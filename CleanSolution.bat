@echo off
setlocal

rem Clean the project
msbuild Project.sln /t:"Project":clean /p:Configuration=Debug
msbuild Project.sln /t:"Project":clean /p:Configuration=Release
msbuild Project.sln /t:"Project":clean /p:Configuration=Shipping

rem Get the directory of the batch script
set "scriptDir=%~dp0"

rem Define the relative path to the directory to delete
set "relativeBuildDir=Build\"
set "relativePackageDir=packages\"

rem Combine the script directory and relative path to get the absolute path
set "buildDir=%scriptDir%%relativeBuildDir%"

rem Check if the directory exists
if exist "%buildDir%" (
    rem Delete all files and subdirectories in the target directory
    del /s /q "%buildDir%\*.*" > nul 2>&1
    rd /s /q "%buildDir%" > nul 2>&1
)

rem Remove local packages as well
set "packageDir=%scriptDir%%relativePackageDir%"
if exist "%packageDir%" (
    rem Delete all files and subdirectories in the target directory
    del /s /q "%packageDir%\*.*" > nul 2>&1
    rd /s /q "%packageDir%" > nul 2>&1
)
