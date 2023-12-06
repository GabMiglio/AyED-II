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
    /**
     * @brief en un futuro podría pasar un vector de sensores
     * 
     */
    DataCenter* dc = new DataCenter(s1, s2);
    dc->setMaxHumidity(5);
    dc->setMaxTemp(5);
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;
    cout << dc->requestData() << endl;

    delete s1;
    delete s2;
    delete dc;
    return 0;
}
