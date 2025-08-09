#include <memory>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

class Cubicle {
    private:
    int id;

    public:
    Cubicle(int id) {
        this->id = id;
    }

    //getters
    int getId() {
        return id;
    }

    //setters
    void setId(int id) {
        this->id = id;
    }
};

class Reservation {
    private:
    int id;
    shared_ptr<Customer> customer;  
    list <shared_ptr<Cubicle>> cubicles;
    string startDate; //yyyy-mm-dd - Este formato es para que se pueda comparar con el formato de la fecha de la reserva
    string endDate; //yyyy-mm-dd - Este formato es para que se pueda comparar con el formato de la fecha de la reserva

    public:
    Reservation(shared_ptr<Customer> customer, list<shared_ptr<Cubicle>> cubicles, string startDate, string endDate) {
        id = rand() % 10000000000; // numero pseudoaleatorio
        this->customer = customer;
        this->cubicles = cubicles;
        this->startDate = startDate;
        this->endDate = endDate;
    }

    void setCustomer(shared_ptr<Customer> customer) {
        this->customer = customer;
    }

    void setCubicles(list<shared_ptr<Cubicle>> cubicles) {
        this->cubicles = cubicles;
    }

    void setStartDate(int startDate) {
        this->startDate = startDate;
    }

    void setEndDate(int endDate) {
        this->endDate = endDate;
    }

    shared_ptr<Customer> getCustomer() {
        return customer;
    }

    list<shared_ptr<Cubicle>> getCubicles(){
        return cubicles;
    }

    string getStartDate() {
        return startDate;
    }

    string getEndDate() {
        return endDate;
    }

    int getId() {
        return id;
    }
};

class ReservationManager {
    private:
    list<shared_ptr<Reservation>> reservations;
    list<shared_ptr<Customer>> customers;
    list<shared_ptr<Cubicle>> cubicles;
    
    
    public:
    bool isCubicleAvailable(int cubicleId, string initDate, string endDate) {
                // Verificacion completa de disponibilidad - contempla TODOS los casos de solapamiento
            for (auto reservation : this->reservations) {
                if (reservation->getCubicles().front()->getId() == cubicleId) {
                    string resStart = reservation->getStartDate();
                    string resEnd = reservation->getEndDate();
                    
                    // CASO 1: Nueva reserva completamente dentro de reserva existente
                    // [----Existente----]
                    //   [--Nueva--]
                    if (initDate >= resStart && endDate <= resEnd) {
                        return false;
                    }
                    
                    // CASO 2: Nueva reserva engloba completamente a la existente
                    // [--Nueva----------]
                    //   [--Existente--]
                    if (initDate <= resStart && endDate >= resEnd) {
                        return false;
                    }
                    
                    // CASO 3: Nueva reserva empieza antes y termina dentro de la existente
                    // [--Nueva-----]
                    //     [--Existente--]
                    if (initDate < resStart && endDate > resStart && endDate <= resEnd) {
                        return false;
                    }
                    
                    // CASO 4: Nueva reserva empieza dentro y termina después de la existente
                    //     [-----Nueva--]
                    // [--Existente--]
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

        ReservationManager() {
        this->customers = list<shared_ptr<Customer>>();
        this->cubicles = list<shared_ptr<Cubicle>>();
        this->reservations = list<shared_ptr<Reservation>>();
    }

    void createReservation(int customerDni, list<int> cubicleIds, string startDate, string endDate){
        // Verificar si el cliente existe
        shared_ptr<Customer> customer = getCustomer(customerDni);

        // Verificar si los cubicles existen
        list<shared_ptr<Cubicle>> reservationCubicles;
        for (int cubicleId : cubicleIds){
            reservationCubicles.push_back(getCubicle(cubicleId));
        }

        // Verificar si los cubicles estan disponibles
        for (auto cubicle : reservationCubicles){
            if (!isCubicleAvailable(cubicle->getId(), startDate, endDate)){
                cout << "\033[1;31mSYSTEM ERROR: Cubicle " << cubicle->getId() << " is not available\033[0m" << endl;
                return;
            }
        }

        // Crear la reserva
        shared_ptr<Reservation> reservation = make_shared<Reservation>(customer, reservationCubicles, startDate, endDate);
        reservations.push_back(reservation);
    }

    void createCustomer(int dni, string name, string facebookUsername, string instagramUsername, string whatsappUsername){
        shared_ptr<Customer> customer = make_shared<Customer>(dni, name, facebookUsername, instagramUsername, whatsappUsername);
        customers.push_back(customer);
    }

    void createCubicle(int id){
        shared_ptr<Cubicle> cubicle = make_shared<Cubicle>(id);
        cubicles.push_back(cubicle);
    }

    void removeCustomer(int dni){
        // Borra en-place sin invalidar el bucle (seguro para std::list)
        customers.remove_if([&](const shared_ptr<Customer>& c){
            // Marca para eliminar cuando el DNI del cliente coincide
            return c->getDni() == dni;
        });
    }

    void removeCubicle(int id){
        cubicles.remove_if([&](const shared_ptr<Cubicle>& c){
            return c->getId() == id;
        });
    }

    void removeReservation(int id){
        reservations.remove_if([&](const shared_ptr<Reservation>& r){
            return r->getId() == id;
        });
    }

    shared_ptr<Reservation> getReservation(int id){
        for (auto reservation : reservations){
            if (reservation->getId() == id){
                return reservation;
            }
        }
        return nullptr;
    }

    shared_ptr<Customer> getCustomer(int dni){
        for (auto customer : customers){
            if (customer->getDni() == dni){
                return customer;
            }
        }
        return nullptr;
    }

    shared_ptr<Cubicle> getCubicle(int id){
        for (auto cubicle : cubicles){
            if (cubicle->getId() == id){
                return cubicle;
            }
        }
        return nullptr;
    }

    list<shared_ptr<Reservation>> getReservations(){
        return reservations;
    }

    list<shared_ptr<Customer>> getCustomers(){
        return customers;
    }

    list<shared_ptr<Cubicle>> getCubicles(){
        return cubicles;
    }

    void notifyCustomer(int customerId, string message, MessagerEnum messagerEnum, string from = "EMPRESA QBIGOTEC"){
        shared_ptr<Customer> customer = getCustomer(customerId);
        string username = customer->getUsername(messagerEnum);
        shared_ptr<Messager> messager; // puntero a la clase abstracta Messager que nos deja decidir que clase instanciar
        switch (messagerEnum){
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
};

class ReservationManagerUI {
    private:
    ReservationManager reservationManager;
    public:
    ReservationManagerUI(ReservationManager reservationManager){
        this->reservationManager = reservationManager;

        //test data
        this->reservationManager.createCustomer(123456789, "Juan Perez", "juanperez", "juanperez", "juanperez");
        this->reservationManager.createCustomer(123456790, "Maria Gomez", "mariagomez", "mariagomez", "mariagomez");
        this->reservationManager.createCustomer(123456791, "Pedro Gomez", "pedrogomez", "pedrogomez", "pedrogomez");
        this->reservationManager.createCustomer(123456792, "Ana Gomez", "anagomez", "anagomez", "anagomez");
        this->reservationManager.createCustomer(123456793, "Luis Gomez", "luisgomez", "luisgomez", "luisgomez");
        this->reservationManager.createCubicle(1);
        this->reservationManager.createCubicle(2);
        this->reservationManager.createCubicle(3);
        this->reservationManager.createCubicle(4);
        this->reservationManager.createCubicle(5);
        this->reservationManager.createCubicle(6);
        this->reservationManager.createCubicle(7);
        this->reservationManager.createCubicle(8);
        this->reservationManager.createCubicle(9);
        this->reservationManager.createCubicle(10);
        this->reservationManager.createReservation(123456789, {1, 2, 3}, "2025-01-01", "2025-01-03");
        this->reservationManager.createReservation(123456790, {4, 5, 6}, "2025-01-01", "2025-01-03");
        this->reservationManager.createReservation(123456791, {7, 8, 9}, "2025-01-01", "2025-01-03");
        this->reservationManager.createReservation(123456792, {10}, "2025-01-01", "2025-01-03");
        this->reservationManager.createReservation(123456793, {1, 2, 3}, "2025-01-01", "2025-01-03");
    }

    void showMenu(){
        while (true){
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
            switch (choice){
                case 1:
                    createReservation();
                    break;
                case 2:
                    createCustomer();
                    break;
                case 3:
                    createCubicle();
                    break;
                case 4:
                    removeCustomer();
                    break;
                case 5: 
                    removeCubicle();
                    break;
                case 6:
                    removeReservation();
                    break;
                case 7: 
                    getReservations();
                    break;
                case 8:
                    getCustomers();
                    break;
                case 9:
                    getCubicles();
                    break;
                case 10:
                    notifyCustomer();
                    break;
                case 11:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice" << endl;
                        break;
            }
        }

    }

    void createReservation(){
        list<int> cubicleIds;
        int cubiclesAmount, customerDni;
        string startDate, endDate;

        //pedir el id del cliente
        cout << "Enter customer dni: ";
        cin >> customerDni;

        //pedir la fecha de inicio
        cout << "Enter start date: ";
        cin >> startDate;
        cout << "Enter end date: ";
        cin >> endDate;

        //pedir los cubicles disponibles
        cout << endl << "Cubicles available: " << endl;
        list<shared_ptr<Cubicle>> cubicles = reservationManager.getCubicles();
        int availableCubicles = 0;
        for (auto cubicle : cubicles){
            bool isAvailable = reservationManager.isCubicleAvailable(cubicle->getId(), startDate, endDate);
            if (isAvailable){
                cout << "Cubicle id: " << cubicle->getId() << endl;
                availableCubicles++;
            }
        }
        cout << "Amount of available cubicles: " << availableCubicles << endl << endl;
        

        //pedir la cantidad de cubicles a reservar
        cout << "How many cubicles will you reserve? ";
        cin >> cubiclesAmount;
        if (cubiclesAmount > reservationManager.getCubicles().size()){
            cout << "There are not enough cubicles available" << endl;
            return; //si no hay cubicles disponibles, no se crea la reserva
        }
        //pedir los cubicles a reservar
        for (int i = 0; i < cubiclesAmount; i++){
            cout << "Enter cubicle id: ";
            int cubicleId;
            cin >> cubicleId;
            shared_ptr<Cubicle> cubicle = reservationManager.getCubicle(cubicleId);
            if (cubicle == nullptr){
                cout << "Cubicle not found" << endl;
                return;
            }
            cubicleIds.push_back(cubicleId);
        }
        reservationManager.createReservation(customerDni, cubicleIds, startDate, endDate);
    }

    void createCustomer(){
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

    void createCubicle(){
        cout << "Enter cubicle id: ";
        int cubicleId;
        cin >> cubicleId;
        reservationManager.createCubicle(cubicleId);
    }

    void removeCustomer(){
        cout << "Enter customer dni: ";
        int customerDni;
        cin >> customerDni;
        reservationManager.removeCustomer(customerDni);
    }

    void removeCubicle(){
        cout << "Enter cubicle id: ";
        int cubicleId;
        cin >> cubicleId;
        reservationManager.removeCubicle(cubicleId);
    }

    void removeReservation(){
        cout << "Enter reservation id: ";
        int reservationId;
        cin >> reservationId;
        reservationManager.removeReservation(reservationId);
    }

    void getReservations(){
        list<shared_ptr<Reservation>> reservations = reservationManager.getReservations();
        cout << "===========================================================" << endl;
        cout << "Ingrese el id de la reserva (0 para ver todas las reservas)" << endl;
        int reservationId;
        cin >> reservationId;
        
        for (auto reservation : reservations){
            if (reservationId == 0 || reservationId == reservation->getId()){
                cout << "Reservation id: " << reservation->getId() << endl;
                cout << "Customer dni: " << reservation->getCustomer()->getDni() << endl;
                cout << "Cubicle ids: ";
                for (auto cubicle : reservation->getCubicles()){
                    cout << cubicle->getId() << " ";
                }
                cout << endl;
                cout << "Start date: " << reservation->getStartDate() << endl;
                cout << "End date: " << reservation->getEndDate() << endl << endl;
            }
        }
        cout << "===========================================================" << endl;
    }
    
    void getCustomers(){
        for (auto customer : reservationManager.getCustomers()){
            cout << "Customer dni: " << customer->getDni() << endl;
            cout << "Customer name: " << customer->getName() << endl;
            cout << "Customer facebook username: " << customer->getUsername(FACEBOOK) << endl;
            cout << "Customer instagram username: " << customer->getUsername(INSTAGRAM) << endl;
            cout << "Customer whatsapp username: " << customer->getUsername(WHATSAPP) << endl;
        }
    }

    void getCubicles(){
        for (auto cubicle : reservationManager.getCubicles()){
            cout << "Cubicle id: " << cubicle->getId() << endl;
        }
    }

    void notifyCustomer(){  
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

};


int main() {
    ReservationManagerUI reservationManagerUI = ReservationManagerUI(ReservationManager());
    reservationManagerUI.showMenu();
    return 0;
} 