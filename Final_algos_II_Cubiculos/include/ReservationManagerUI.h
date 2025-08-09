#ifndef RESERVATION_MANAGER_UI_H
#define RESERVATION_MANAGER_UI_H

#include "ReservationManager.h"

class ReservationManagerUI {
private:
    ReservationManager& reservationManager;

public:
    ReservationManagerUI(ReservationManager& reservationManager);

    void showMenu();
    void createReservation();
    void createCustomer();
    void createCubicle();
    void removeCustomer();
    void removeCubicle();
    void removeReservation();
    void getReservations();
    void getCustomers();
    void getCubicles();
    void notifyCustomer();
    void setupTestData();
};

#endif // RESERVATION_MANAGER_UI_H
