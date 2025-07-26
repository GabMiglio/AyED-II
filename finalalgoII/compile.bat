@echo off
echo Compilando Weather Control System...
echo.


:: Compilar archivos fuente
g++ -Wall -std=c++11 -I.\Include -c .\SRC\Forecast.cpp
if errorlevel 1 (
    echo Error compilando Forecast.cpp
    pause
    exit /b 1
)

g++ -Wall -std=c++11 -I.\Include -c .\SRC\WeatherLog.cpp
if errorlevel 1 (
    echo Error compilando WeatherLog.cpp
    pause
    exit /b 1
)

g++ -Wall -std=c++11 -I.\Include -c .\SRC\WeatherControl.cpp
if errorlevel 1 (
    echo Error compilando WeatherControl.cpp
    pause
    exit /b 1
)

g++ -Wall -std=c++11 -I.\Include -c .\SRC\WeatherControlUI.cpp
if errorlevel 1 (
    echo Error compilando WeatherControlUI.cpp
    pause
    exit /b 1
)

g++ -Wall -std=c++11 -I.\Include -c .\bd.cpp
if errorlevel 1 (
    echo Error compilando bd.cpp
    pause
    exit /b 1
)

:: Enlazar archivos objeto
echo Enlazando archivos...
g++ Forecast.o WeatherLog.o WeatherControl.o WeatherControlUI.o bd.o -o weather_app.exe
if errorlevel 1 (
    echo Error en el enlazado
    pause
    exit /b 1
)

echo.
echo Compilacion exitosa!
echo Ejecutable generado: weather_app.exe
echo.

:: Limpiar archivos objeto
echo Limpiando archivos objeto...
del *.o
echo Archivos .o eliminados.
echo.

echo Presiona cualquier tecla para ejecutar el programa...
pause >nul
weather_app.exe 