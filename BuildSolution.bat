@echo off
setlocal

rem Get current directory
set "currentDir=%CD%"

rem Get the solution file name (assuming there's only one .sln file in the directory)
for %%F in ("%currentDir%\*.sln") do set "solutionFileName=%%~nxF"

rem Check if a solution file exists in the current directory
if "%solutionFileName%"=="" (
    echo "No solution file (.sln) found in the current directory."
    echo %currentDir%
    exit /b 1
)

rem Load VC
if exist "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\" (
    echo Loading x64 Professional
    call "C:\Program Files\Microsoft Visual Studio\2022\Professional\VC\Auxiliary\Build\vcvars64.bat"
) else (
    if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\" (
        echo Loading x64 Community
        call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
    )
)

rem Check if an argument was passed
if "%~1"=="" (
    echo Please specify a configuration argument:
    echo - Debug
    echo - Release
    echo - Shipping
    echo - AllConfigs
    echo You can also pass in -v as the second argument to get a more detailed build output
    exit /b 1
)

rem Check if the second argument is '-v' for verbose output
if "%~2"=="-v" (
    set "verbosityFlag=-verbosity:normal"
) else (
    set "verbosityFlag=-verbosity:minimal"
)

rem Check if the argument is "AllConfigs"
if "%~1"=="AllConfigs" (
    echo Building All Configurations
    rem Invoke MSBuild for Debug, Release, and Shipping configurations
    msbuild "%solutionFileName%" %verbosityFlag% /p:Configuration=Debug
    msbuild "%solutionFileName%" %verbosityFlag% /p:Configuration=Release
    msbuild "%solutionFileName%" %verbosityFlag% /p:Configuration=Shipping
) else (
    rem Check if the argument is one of the specified configurations
    if "%~1"=="Debug" (
        echo Building Debug Configuration
    ) else if "%~1"=="Release" (
        echo Building Release Configuration
    ) else if "%~1"=="Shipping" (
        echo Building Shipping Configuration
    ) else (
        echo Invalid configuration specified. Please specify one of the following:
        echo - Debug
        echo - Release
        echo - Shipping
        echo - AllConfigs
        exit /b 1
    )

    rem Invoke MSBuild with the specified configuration
    msbuild "%solutionFileName%" %verbosityFlag% /p:Configuration=%~1
)
