@echo off
echo Compilando Weather Control System...
echo.

:: Compilar archivos fuente
g++ -c SRC/Forecast.cpp -I Include -o Forecast.o
if errorlevel 1 (
    echo Error compilando Forecast.cpp
    pause
    exit /b 1
)

g++ -c SRC/WeatherLog.cpp -I Include -o WeatherLog.o
if errorlevel 1 (
    echo Error compilando WeatherLog.cpp
    pause
    exit /b 1
)

g++ -c SRC/WeatherControl.cpp -I Include -o WeatherControl.o
if errorlevel 1 (
    echo Error compilando WeatherControl.cpp
    pause
    exit /b 1
)

g++ -c SRC/WeatherControlUI.cpp -I Include -o WeatherControlUI.o
if errorlevel 1 (
    echo Error compilando WeatherControlUI.cpp
    pause
    exit /b 1
)

g++ -c bd.cpp -I Include -o bd.o
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