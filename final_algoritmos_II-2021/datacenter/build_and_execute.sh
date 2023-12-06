#!/bin/bash

## Compilo código objeto
g++ -Wall -std=c++11 -I./include -c ./src/HumiditySensor.cpp 
g++ -Wall -std=c++11 -I./include -c ./src/TemperatureSensor.cpp
g++ -Wall -std=c++11 -I./include -c ./src/SensorFactory.cpp
g++ -Wall -std=c++11 -I./include -c ./src/MailSender.cpp
g++ -Wall -std=c++11 -I./include -c ./src/LogWriter.cpp
g++ -Wall -std=c++11 -I./include -c ./src/DataCenter.cpp
g++ -Wall -std=c++11 -I./include -c main.cpp

## Compilo el Binario
g++ -I./include HumiditySensor.o TemperatureSensor.o SensorFactory.o MailSender.o \
LogWriter.o DataCenter.o main.o -o app.bin

## Limpio los códigos objeto
rm ./*.o

## Permisos de ejecución
chmod +x app.bin

## Ejecución
./app.bin