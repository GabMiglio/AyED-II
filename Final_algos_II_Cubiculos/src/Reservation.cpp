#include "../include/Reservation.h"
#include <cstdlib>

Reservation::Reservation(shared_ptr<Customer> customer, list<shared_ptr<Cubicle>> cubicles, string startDate, string endDate) {
    id = rand() % 10000000000; // numero pseudoaleatorio
    this->customer = customer;
    this->cubicles = cubicles;
    this->startDate = startDate;
    this->endDate = endDate;
}

void Reservation::setCustomer(shared_ptr<Customer> customer) {
    this->customer = customer;
}

void Reservation::setCubicles(list<shared_ptr<Cubicle>> cubicles) {
    this->cubicles = cubicles;
}

void Reservation::setStartDate(int startDate) {
    this->startDate = startDate;
}

void Reservation::setEndDate(int endDate) {
    this->endDate = endDate;
}

shared_ptr<Customer> Reservation::getCustomer() {
    return customer;
}

list<shared_ptr<Cubicle>> Reservation::getCubicles() {
    return cubicles;
}

string Reservation::getStartDate() {
    return startDate;
}

string Reservation::getEndDate() {
    return endDate;
}

int Reservation::getId() {
    return id;
}
