#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <memory>
#include <list>
#include <string>
#include "Customer.h"
#include "Cubicle.h"
#include "Reservation.h"
#include "MessagerEnum.h"

using namespace std;

class ReservationManager {
private:
    list<shared_ptr<Reservation>> reservations;
    list<shared_ptr<Customer>> customers;
    list<shared_ptr<Cubicle>> cubicles;
    
public:
    ReservationManager();

    // Availability check
    bool isCubicleAvailable(int cubicleId, string initDate, string endDate);

    // Create methods
    void createReservation(int customerDni, list<int> cubicleIds, string startDate, string endDate);
    void createCustomer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername);
    void createCubicle(int id);

    // Remove methods
    void removeCustomer(int dni);
    void removeCubicle(int id);
    void removeReservation(int id);

    // Get single item methods
    shared_ptr<Reservation> getReservation(int id);
    shared_ptr<Customer> getCustomer(int dni);
    shared_ptr<Cubicle> getCubicle(int id);

    // Get all items methods
    list<shared_ptr<Reservation>> getReservations();
    list<shared_ptr<Customer>> getCustomers();
    list<shared_ptr<Cubicle>> getCubicles();

    // Notification
    void notifyCustomer(int customerId, string message, MessagerEnum messagerEnum, string from = "EMPRESA QBIGOTEC");
};

#endif // RESERVATION_MANAGER_H
