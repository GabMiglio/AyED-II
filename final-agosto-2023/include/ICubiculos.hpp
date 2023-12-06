#ifndef ICUBICULOS_H
#define ICUBICULOS_H

#include <iostream>
#include <string>
#include <math.h>

class ICubiculos{

    public:
    virtual void setAvailableCubicles(int);
    virtual void setRentedCubicles(int);
    virtual void setCubicleOwner(std::string);
    ~ICubiculos(){std::cout << "El cubiculo se ha decomisionado" << std::endl;}

};


#endif