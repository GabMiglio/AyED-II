#include <memory>
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Messager {
    public:
    virtual void sendMesagge(string message, string to, string from) = 0;
};

//heredan facebook, instagram y whatsapp

class Facebook : public Messager {
    public:
    void sendMesagge(string message, string to, string from) override {
        cout << "Facebook: " << message << " to " << to << " from " << from << endl;
    }
};

class Instagram : public Messager {
    public:
    void sendMesagge(string message, string to, string from) override {
        cout << "Instagram: " << message << " to " << to << " from " << from << endl;
    }
};

class Whatsapp : public Messager {
    public:
    void sendMesagge(string message, string to, string from) override {
        cout << "Whatsapp: " << message << " to " << to << " from " << from << endl;
    }
};

enum MessagerEnum {
    FACEBOOK = 0,
    INSTAGRAM = 1,
    WHATSAPP = 2
};

class Customer {
    private:
    int dni;
    string name;
    string facebookUsername;
    string instagramUsername;
    string whatsappUsername;
    
    public:
    Customer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername) {
        this->dni = dni;
        this->name = name;
        this->facebookUsername = facebookUsername;
        this->instagramUsername = instagramUsername;
        this->whatsappUsername = whatsappUsername;
    }

    //getters
    int getDni() {
        return dni;
    }
    
    string getName() {
        return name;
    }
    
    string getUsername(MessagerEnum messagerEnum) {
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

    //setters
    void setDni(int dni) {
        this->dni = dni;
    }
    
    void setName(string name) {
        this->name = name;
    }

    void setUsername(MessagerEnum messagerEnum, string username) {
        if (messagerEnum == FACEBOOK) {
            this->facebookUsername = username;
        } else if (messagerEnum == INSTAGRAM) {
            this->instagramUsername = username;
        } else if (messagerEnum == WHATSAPP) {
            this->whatsappUsername = username;
        }
    }

};




int main() {
    
} 