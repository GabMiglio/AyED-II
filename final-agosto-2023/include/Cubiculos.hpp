#ifndef CUBICULOS_H
#define CUBICULOS_H

#include <iostream>
#include <string>
#include "ICubiculos.hpp"

class Cubiculos: public ICubiculos{
           public:
           Cubiculos();
           void setAvailableCubicles(int);
           void setRentedCubicles(int);
           void setCubicleOwner(std::string);
           ~Cubiculos(){std::cout << "El cubiculo ha sido decomisionado" << std::endl;};

};

#endif