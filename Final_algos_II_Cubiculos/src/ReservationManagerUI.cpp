#include "../include/ReservationManagerUI.h"
#include <iostream>
#include <cstdlib>

ReservationManagerUI::ReservationManagerUI(ReservationManager& reservationManager) : reservationManager(reservationManager) {
    setupTestData();
}

void ReservationManagerUI::setupTestData() {
    // Test data
    reservationManager.createCustomer(123456789, "Juan Perez", "juanperez", "juanperez", "juanperez");
    reservationManager.createCustomer(123456790, "Maria Gomez", "mariagomez", "mariagomez", "mariagomez");
    reservationManager.createCustomer(123456791, "Pedro Gomez", "pedrogomez", "pedrogomez", "pedrogomez");
    reservationManager.createCustomer(123456792, "Ana Gomez", "anagomez", "anagomez", "anagomez");
    reservationManager.createCustomer(123456793, "Luis Gomez", "luisgomez", "luisgomez", "luisgomez");
    
    for (int i = 1; i <= 10; i++) {
        reservationManager.createCubicle(i);
    }
    
    reservationManager.createReservation(123456789, {1, 2, 3}, "2025-01-01", "2025-01-03");
    reservationManager.createReservation(123456790, {4, 5, 6}, "2025-01-01", "2025-01-03");
    reservationManager.createReservation(123456791, {7, 8, 9}, "2025-01-01", "2025-01-03");
    reservationManager.createReservation(123456792, {10}, "2025-01-01", "2025-01-03");
}

void ReservationManagerUI::showMenu() {
    while (true) {
        cout << "1. Create Reservation" << endl;
        cout << "2. Create Customer" << endl;
        cout << "3. Create Cubicle" << endl;
        cout << "4. Remove Customer" << endl;
        cout << "5. Remove Cubicle" << endl;
        cout << "6. Remove Reservation" << endl;
        cout << "7. Get Reservations" << endl;  
        cout << "8. Get Customers" << endl;
        cout << "9. Get Cubicles" << endl;
        cout << "10. Notify Customer" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: createReservation(); break;
            case 2: createCustomer(); break;
            case 3: createCubicle(); break;
            case 4: removeCustomer(); break;
            case 5: removeCubicle(); break;
            case 6: removeReservation(); break;
            case 7: getReservations(); break;
            case 8: getCustomers(); break;
            case 9: getCubicles(); break;
            case 10: notifyCustomer(); break;
            case 11: exit(0); break;
            default: cout << "Invalid choice" << endl; break;
        }
    }
}

void ReservationManagerUI::createReservation() {
    list<int> cubicleIds;
    int cubiclesAmount, customerDni;
    string startDate, endDate;

    cout << "Enter customer dni: ";
    cin >> customerDni;
    cout << "Enter start date: ";
    cin >> startDate;
    cout << "Enter end date: ";
    cin >> endDate;

    cout << endl << "Cubicles available: " << endl;
    list<shared_ptr<Cubicle>> cubicles = reservationManager.getCubicles();
    int availableCubicles = 0;
    for (auto cubicle : cubicles) {
        bool isAvailable = reservationManager.isCubicleAvailable(cubicle->getId(), startDate, endDate);
        if (isAvailable) {
            cout << "Cubicle id: " << cubicle->getId() << endl;
            availableCubicles++;
        }
    }
    cout << "Amount of available cubicles: " << availableCubicles << endl << endl;

    cout << "How many cubicles will you reserve? ";
    cin >> cubiclesAmount;
    if (cubiclesAmount > reservationManager.getCubicles().size()) {
        cout << "There are not enough cubicles available" << endl;
        return;
    }
    
    for (int i = 0; i < cubiclesAmount; i++) {
        cout << "Enter cubicle id: ";
        int cubicleId;
        cin >> cubicleId;
        shared_ptr<Cubicle> cubicle = reservationManager.getCubicle(cubicleId);
        if (cubicle == nullptr) {
            cout << "Cubicle not found" << endl;
            return;
        }
        cubicleIds.push_back(cubicleId);
    }
    reservationManager.createReservation(customerDni, cubicleIds, startDate, endDate);
}

void ReservationManagerUI::createCustomer() {
    cout << "Enter customer dni: ";
    int customerDni;
    cin >> customerDni;
    cout << "Enter customer name: ";
    string name;
    cin >> name;
    cout << "Enter customer facebook username: ";
    string facebookUsername;
    cin >> facebookUsername;
    cout << "Enter customer instagram username: ";
    string instagramUsername;
    cin >> instagramUsername;
    cout << "Enter customer whatsapp username: ";
    string whatsappUsername;
    cin >> whatsappUsername;
    reservationManager.createCustomer(customerDni, name, facebookUsername, instagramUsername, whatsappUsername);
}

void ReservationManagerUI::createCubicle() {
    cout << "Enter cubicle id: ";
    int cubicleId;
    cin >> cubicleId;
    reservationManager.createCubicle(cubicleId);
}

void ReservationManagerUI::removeCustomer() {
    cout << "Enter customer dni: ";
    int customerDni;
    cin >> customerDni;
    reservationManager.removeCustomer(customerDni);
}

void ReservationManagerUI::removeCubicle() {
    cout << "Enter cubicle id: ";
    int cubicleId;
    cin >> cubicleId;
    reservationManager.removeCubicle(cubicleId);
}

void ReservationManagerUI::removeReservation() {
    cout << "Enter reservation id: ";
    int reservationId;
    cin >> reservationId;
    reservationManager.removeReservation(reservationId);
}

void ReservationManagerUI::getReservations() {
    list<shared_ptr<Reservation>> reservations = reservationManager.getReservations();
    cout << "===========================================================" << endl;
    cout << "Ingrese el id de la reserva (0 para ver todas las reservas)" << endl;
    int reservationId;
    cin >> reservationId;
    
    for (auto reservation : reservations) {
        if (reservationId == 0 || reservationId == reservation->getId()) {
            cout << "Reservation id: " << reservation->getId() << endl;
            cout << "Customer dni: " << reservation->getCustomer()->getDni() << endl;
            cout << "Cubicle ids: ";
            for (auto cubicle : reservation->getCubicles()) {
                cout << cubicle->getId() << " ";
            }
            cout << endl;
            cout << "Start date: " << reservation->getStartDate() << endl;
            cout << "End date: " << reservation->getEndDate() << endl << endl;
        }
    }
    cout << "===========================================================" << endl;
}

void ReservationManagerUI::getCustomers() {
    for (auto customer : reservationManager.getCustomers()) {
        cout << "Customer dni: " << customer->getDni() << endl;
        cout << "Customer name: " << customer->getName() << endl;
        cout << "Customer facebook username: " << customer->getUsername(FACEBOOK) << endl;
        cout << "Customer instagram username: " << customer->getUsername(INSTAGRAM) << endl;
        cout << "Customer whatsapp username: " << customer->getUsername(WHATSAPP) << endl;
    }
}

void ReservationManagerUI::getCubicles() {
    for (auto cubicle : reservationManager.getCubicles()) {
        cout << "Cubicle id: " << cubicle->getId() << endl;
    }
}

void ReservationManagerUI::notifyCustomer() {  
    cout << "Enter customer dni: ";
    int customerDni;
    cin >> customerDni;
    cout << "Enter message: ";
    string message;
    cin.ignore();
    getline(cin, message);
    cout << "Enter messager type (0: Facebook, 1: Instagram, 2: Whatsapp): ";
    int messagerType;
    cin >> messagerType;
    MessagerEnum messagerEnum = static_cast<MessagerEnum>(messagerType);
    reservationManager.notifyCustomer(customerDni, message, messagerEnum);
}
