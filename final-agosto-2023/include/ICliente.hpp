#ifndef ICLIENTE_H
#define ICLIENTE_H
#include <iostream>
#include <string>

class ICliente{

       public: 
         class IUser{
	public:
		virtual void setName(std::string) = 0;
		virtual void setSurname(std::string) = 0;
		virtual void setPhoneNumber(std::string) = 0;
		virtual std::string getName() = 0;
		virtual std::string getSurname() = 0;
		virtual std::string getRole() = 0;
		virtual ~IUser(){std::cout << "Cliente destruido" << std::endl;}
    };

};



#endif