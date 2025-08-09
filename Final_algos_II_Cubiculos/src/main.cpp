#include "../include/ReservationManagerUI.h"

int main() {
    ReservationManager reservationManager;  // CORREGIDO: instancia con nombre
    ReservationManagerUI reservationManagerUI(reservationManager);
    reservationManagerUI.showMenu();
    return 0;
}
