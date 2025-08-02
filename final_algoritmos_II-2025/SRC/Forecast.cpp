#include "Forecast.h"

void Forecast::Up_Temp(float X) {
    temp += X;
}

void Forecast::Down_Temp(float X) {
    temp -= X;
}

void Forecast::Up_Humity(float X) {
    humid += X;
}

void Forecast::Down_Humity(float X) {
    humid -= X;
}

float Forecast::Read_Temp() {
    return temp;
}

float Forecast::Read_Humity() {
    return humid;
} 