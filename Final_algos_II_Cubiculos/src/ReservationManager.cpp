#include "../include/ReservationManager.h"
#include "../include/Messager.h"
#include <iostream>

ReservationManager::ReservationManager() {
    this->customers = list<shared_ptr<Customer>>();
    this->cubicles = list<shared_ptr<Cubicle>>();
    this->reservations = list<shared_ptr<Reservation>>();
}

bool ReservationManager::isCubicleAvailable(int cubicleId, string initDate, string endDate) {
    // Verificacion completa de disponibilidad - contempla TODOS los casos de solapamiento
    for (auto reservation : this->reservations) {
        if (reservation->getCubicles().front()->getId() == cubicleId) {
            string resStart = reservation->getStartDate();
            string resEnd = reservation->getEndDate();
            
            // CASO 1: Nueva reserva completamente dentro de reserva existente
            if (initDate >= resStart && endDate <= resEnd) {
                return false;
            }
            
            // CASO 2: Nueva reserva engloba completamente a la existente
            if (initDate <= resStart && endDate >= resEnd) {
                return false;
            }
            
            // CASO 3: Nueva reserva empieza antes y termina dentro de la existente
            if (initDate < resStart && endDate > resStart && endDate <= resEnd) {
                return false;
            }
            
            // CASO 4: Nueva reserva empieza dentro y termina después de la existente
            if (initDate >= resStart && initDate < resEnd && endDate > resEnd) {
                return false;
            }
            
            // CASO 5: Fechas exactamente iguales (inicio o fin coinciden)
            if (initDate == resStart || initDate == resEnd || endDate == resStart || endDate == resEnd) {
                return false;
            }
        }
    }
    return true; // No hay conflictos, cubicle disponible
}

void ReservationManager::createReservation(int customerDni, list<int> cubicleIds, string startDate, string endDate) {
    // Verificar si el cliente existe
    shared_ptr<Customer> customer = getCustomer(customerDni);

    // Verificar si los cubicles existen
    list<shared_ptr<Cubicle>> reservationCubicles;
    for (int cubicleId : cubicleIds) {
        reservationCubicles.push_back(getCubicle(cubicleId));
    }

    // Verificar si los cubicles estan disponibles
    for (auto cubicle : reservationCubicles) {
        if (!isCubicleAvailable(cubicle->getId(), startDate, endDate)) {
            cout << "\033[1;31mSYSTEM ERROR: Cubicle " << cubicle->getId() << " is not available\033[0m" << endl;
            return;
        }
    }

    // Crear la reserva
    shared_ptr<Reservation> reservation = make_shared<Reservation>(customer, reservationCubicles, startDate, endDate);
    reservations.push_back(reservation);
}

void ReservationManager::createCustomer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername) {
    shared_ptr<Customer> customer = make_shared<Customer>(dni, name, facebookUsername, instagramUsername, whatsappUsername);
    customers.push_back(customer);
}

void ReservationManager::createCubicle(int id) {
    shared_ptr<Cubicle> cubicle = make_shared<Cubicle>(id);
    cubicles.push_back(cubicle);
}

void ReservationManager::removeCustomer(int dni) {
    customers.remove_if([&](const shared_ptr<Customer>& c) {
        return c->getDni() == dni;
    });
}

void ReservationManager::removeCubicle(int id) {
    cubicles.remove_if([&](const shared_ptr<Cubicle>& c) {
        return c->getId() == id;
    });
}

void ReservationManager::removeReservation(int id) {
    reservations.remove_if([&](const shared_ptr<Reservation>& r) {
        return r->getId() == id;
    });
}

shared_ptr<Reservation> ReservationManager::getReservation(int id) {
    for (auto reservation : reservations) {
        if (reservation->getId() == id) {
            return reservation;
        }
    }
    return nullptr;
}

shared_ptr<Customer> ReservationManager::getCustomer(int dni) {
    for (auto customer : customers) {
        if (customer->getDni() == dni) {
            return customer;
        }
    }
    return nullptr;
}

shared_ptr<Cubicle> ReservationManager::getCubicle(int id) {
    for (auto cubicle : cubicles) {
        if (cubicle->getId() == id) {
            return cubicle;
        }
    }
    return nullptr;
}

list<shared_ptr<Reservation>> ReservationManager::getReservations() {
    return reservations;
}

list<shared_ptr<Customer>> ReservationManager::getCustomers() {
    return customers;
}

list<shared_ptr<Cubicle>> ReservationManager::getCubicles() {
    return cubicles;
}

void ReservationManager::notifyCustomer(int customerId, string message, MessagerEnum messagerEnum, string from) {
    shared_ptr<Customer> customer = getCustomer(customerId);
    string username = customer->getUsername(messagerEnum);
    shared_ptr<Messager> messager;
    
    switch (messagerEnum) {
        case FACEBOOK:
            messager = make_shared<Facebook>();
            break;
        case INSTAGRAM:
            messager = make_shared<Instagram>();
            break;
        case WHATSAPP:
            messager = make_shared<Whatsapp>();
            break;
        default:
            cout << "\033[1;31mSYSTEM ERROR: Messager not found\033[0m" << endl;
            return;
    }
    messager->sendMesagge(message, username, from);
}
