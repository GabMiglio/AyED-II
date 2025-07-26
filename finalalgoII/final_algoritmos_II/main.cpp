#include <iostream>
#include <string>
#include <Sensor.hpp>
#include <SensorFactory.hpp>
#include <DataCenter.hpp>
using namespace std;

int main(int argc, char const *argv[])
{
    Sensor* s1 = SensorFactory::create("humidity");
    Sensor* s2 = SensorFactory::create("temperature");

    DataCenter* dc = new DataCenter(s1, s2);
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();
    dc->requestData();

    delete s1;
    delete s2;
    return 0;
}
