@echo off
echo Compilando proyecto...

REM Crear directorio bin si no existe
if not exist bin mkdir bin

g++ -std=c++17 -I./include -o bin/main.exe ^
    src/main.cpp ^
    src/Messager.cpp ^
    src/Customer.cpp ^
    src/Cubicle.cpp ^
    src/Reservation.cpp ^
    src/ReservationManager.cpp ^
    src/ReservationManagerUI.cpp

if %ERRORLEVEL% neq 0 (
    echo Error en la compilacion!
    pause
    exit /b 1
)

echo Compilacion exitosa! Ejecutando...
echo.
bin\main.exe

pause