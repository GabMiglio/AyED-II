#!/bin/bash

echo "Compilando Weather Control System..."
echo

# Compilar archivos fuente
echo "Compilando Forecast.cpp..."
g++ -c Forecast.cpp -o Forecast.o
if [ $? -ne 0 ]; then
    echo "Error compilando Forecast.cpp"
    exit 1
fi

echo "Compilando WeatherLog.cpp..."
g++ -c WeatherLog.cpp -o WeatherLog.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherLog.cpp"
    exit 1
fi

echo "Compilando WeatherControl.cpp..."
g++ -c WeatherControl.cpp -o WeatherControl.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherControl.cpp"
    exit 1
fi

echo "Compilando WeatherControlUI.cpp..."
g++ -c WeatherControlUI.cpp -o WeatherControlUI.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherControlUI.cpp"
    exit 1
fi

echo "Compilando main_new.cpp..."
g++ -c main_new.cpp -o main_new.o
if [ $? -ne 0 ]; then
    echo "Error compilando main_new.cpp"
    exit 1
fi

# Enlazar archivos objeto
echo "Enlazando archivos..."
g++ Forecast.o WeatherLog.o WeatherControl.o WeatherControlUI.o main_new.o -o weather_app
if [ $? -ne 0 ]; then
    echo "Error en el enlazado"
    exit 1
fi

echo
echo "¡Compilación exitosa!"
echo "Ejecutable generado: weather_app"
echo

# Limpiar archivos objeto
echo "Limpiando archivos objeto..."
rm -f *.o

echo "¿Deseas ejecutar el programa ahora? (s/n)"
read -n 1 -r
echo
if [[ $REPLY =~ ^[SsYy]$ ]]; then
    ./weather_app
fi 