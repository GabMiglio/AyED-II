#include "../include/Customer.h"

Customer::Customer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername) {
    this->dni = dni;
    this->name = name;
    this->facebookUsername = facebookUsername;
    this->instagramUsername = instagramUsername;
    this->whatsappUsername = whatsappUsername;
}

int Customer::getDni() {
    return dni;
}

string Customer::getName() {
    return name;
}

string Customer::getUsername(MessagerEnum messagerEnum) {
    if (messagerEnum == FACEBOOK) {
        return facebookUsername;
    } else if (messagerEnum == INSTAGRAM) {
        return instagramUsername;
    } else if (messagerEnum == WHATSAPP) {
        return whatsappUsername;
    } else {
        return "User not found";
    }
}

void Customer::setDni(int dni) {
    this->dni = dni;
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setUsername(MessagerEnum messagerEnum, string username) {
    if (messagerEnum == FACEBOOK) {
        this->facebookUsername = username;
    } else if (messagerEnum == INSTAGRAM) {
        this->instagramUsername = username;
    } else if (messagerEnum == WHATSAPP) {
        this->whatsappUsername = username;
    }
}
