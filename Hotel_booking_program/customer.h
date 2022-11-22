#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "customer_def.h"
Customer::Customer(int reservation) {
	this->name = "";
	this->reservation = reservation;
	this->stay = 0;
	this->discount = 0;
	this->total = 0;
}
Customer::Customer(std::string name, int stay, int reservation) {
	this->name = name;
	this->stay = stay;
	this->reservation = reservation;
	this->discount = 0;
	this->total = 0;
}
void Customer::setName(std::string name) {
	this->name = name;
}
std::string Customer::getName() {
	return name;
}
void Customer::setStay(int stay) {
	this->stay = stay;
}
int Customer::getStay() {
	return stay;
}
int Customer::getReservation() {
	return reservation;
}
void Customer::setDiscount(int discount) {
	this->discount = discount;
}
int Customer::getDiscount() {
	return discount;
}
void Customer::setTotal(int total) {
	this->total = total;
}
int Customer::getTotal() {
	return total;
}

#endif 
