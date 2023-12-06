#ifndef CLIENTE_H
#define CLIENTE_H

#include "ICliente.hpp"

class Cliente : public ICliente {
     Cliente();
		void setName(std::string);
		void setSurname(std::string);
		void setPhoneNumber(std::string);
		std::string getName();
		std::string getSurname();
		std::string getPhoneNumber();
		~Cliente();
	private:
		std::string name, surname, phoneNumber;

};



#endif