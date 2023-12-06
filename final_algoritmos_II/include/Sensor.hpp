#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;


class Sensor
{
    public:
        virtual ~Sensor() {}
        virtual float getValue() = 0;
    private:

};

#endif