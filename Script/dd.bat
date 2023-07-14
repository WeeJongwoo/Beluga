call "%~dp0_SetEnv.bat"

if ERRORLEVEL neq 0 (
    exit /B ERRORLEVEL
)

echo %PROJECT_NAME%