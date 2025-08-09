#!/bin/bash

echo "Compilando proyecto..."

# Crear directorio bin si no existe
mkdir -p bin

# Compilar
g++ -std=c++17 -I./include -o bin/main \
    src/main.cpp \
    src/Messager.cpp \
    src/Customer.cpp \
    src/Cubicle.cpp \
    src/Reservation.cpp \
    src/ReservationManager.cpp \
    src/ReservationManagerUI.cpp

if [ $? -ne 0 ]; then
    echo "Error en la compilacion!"
    exit 1
fi

echo "Compilacion exitosa! Ejecutando..."
echo
./bin/main
