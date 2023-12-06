#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H
#include <iostream>
#include <string>
#include <Sensor.hpp>
#include <HumiditySensor.hpp>
#include <TemperatureSensor.hpp>
using namespace std;

#pragma once

class SensorFactory
{
    public:
        SensorFactory();
        ~SensorFactory();
        static Sensor* create(string id);
};

#endif