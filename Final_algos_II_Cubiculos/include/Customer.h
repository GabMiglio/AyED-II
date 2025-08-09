#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "MessagerEnum.h"

using namespace std;

class Customer {
private:
    int dni;
    string name;
    string facebookUsername;
    string instagramUsername;
    string whatsappUsername;
    
public:
    Customer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername);

    // Getters
    int getDni();
    string getName();
    string getUsername(MessagerEnum messagerEnum);

    // Setters
    void setDni(int dni);
    void setName(string name);
    void setUsername(MessagerEnum messagerEnum, string username);
};

#endif // CUSTOMER_H
