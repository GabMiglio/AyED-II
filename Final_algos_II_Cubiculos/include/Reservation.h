#ifndef RESERVATION_H
#define RESERVATION_H

#include <memory>
#include <list>
#include <string>
#include "Customer.h"
#include "Cubicle.h"

using namespace std;

class Reservation {
private:
    int id;
    shared_ptr<Customer> customer;  
    list<shared_ptr<Cubicle>> cubicles;
    string startDate; // yyyy-mm-dd
    string endDate;   // yyyy-mm-dd

public:
    Reservation(shared_ptr<Customer> customer, list<shared_ptr<Cubicle>> cubicles, string startDate, string endDate);

    // Setters
    void setCustomer(shared_ptr<Customer> customer);
    void setCubicles(list<shared_ptr<Cubicle>> cubicles);
    void setStartDate(int startDate);
    void setEndDate(int endDate);

    // Getters
    shared_ptr<Customer> getCustomer();
    list<shared_ptr<Cubicle>> getCubicles();
    string getStartDate();
    string getEndDate();
    int getId();
};

#endif // RESERVATION_H
