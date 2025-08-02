#!/bin/bash

echo "Compilando Weather Control System..."
echo

# Compilar archivos fuente
echo "Compilando Forecast.cpp..."
g++ -c SRC/Forecast.cpp -I Include -o Forecast.o
if [ $? -ne 0 ]; then
    echo "Error compilando Forecast.cpp"
    exit 1
fi

echo "Compilando WeatherLog.cpp..."
g++ -c SRC/WeatherLog.cpp -I Include -o WeatherLog.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherLog.cpp"
    exit 1
fi

echo "Compilando WeatherControl.cpp..."
g++ -c SRC/WeatherControl.cpp -I Include -o WeatherControl.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherControl.cpp"
    exit 1
fi

echo "Compilando WeatherControlUI.cpp..."
g++ -c SRC/WeatherControlUI.cpp -I Include -o WeatherControlUI.o
if [ $? -ne 0 ]; then
    echo "Error compilando WeatherControlUI.cpp"
    exit 1
fi

echo "Compilando bd.cpp..."
g++ -c bd.cpp -I Include -o bd.o
if [ $? -ne 0 ]; then
    echo "Error compilando bd.cpp"
    exit 1
fi

# Enlazar archivos objeto
echo "Enlazando archivos..."
g++ Forecast.o WeatherLog.o WeatherControl.o WeatherControlUI.o bd.o -o weather_app
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