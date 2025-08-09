#include "../include/Messager.h"
#include <iostream>

using namespace std;

void Facebook::sendMesagge(string message, string to, string from) {
    cout << "Facebook: " << message << " to " << to << " from " << from << endl;
}

void Instagram::sendMesagge(string message, string to, string from) {
    cout << "Instagram: " << message << " to " << to << " from " << from << endl;
}

void Whatsapp::sendMesagge(string message, string to, string from) {
    cout << "Whatsapp: " << message << " to " << to << " from " << from << endl;
}
