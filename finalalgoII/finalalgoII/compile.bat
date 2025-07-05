@echo off
echo Compilando Weather Control System...
echo.

:: Compilar archivos fuente
g++ -c Forecast.cpp -o Forecast.o
if errorlevel 1 (
    echo Error compilando Forecast.cpp
    pause
    exit /b 1
)

g++ -c WeatherLog.cpp -o WeatherLog.o
if errorlevel 1 (
    echo Error compilando WeatherLog.cpp
    pause
    exit /b 1
)

g++ -c WeatherControl.cpp -o WeatherControl.o
if errorlevel 1 (
    echo Error compilando WeatherControl.cpp
    pause
    exit /b 1
)

g++ -c WeatherControlUI.cpp -o WeatherControlUI.o
if errorlevel 1 (
    echo Error compilando WeatherControlUI.cpp
    pause
    exit /b 1
)

g++ -c main_new.cpp -o main_new.o
if errorlevel 1 (
    echo Error compilando main_new.cpp
    pause
    exit /b 1
)

:: Enlazar archivos objeto
echo Enlazando archivos...
g++ Forecast.o WeatherLog.o WeatherControl.o WeatherControlUI.o main_new.o -o weather_app.exe
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