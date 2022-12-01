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
//Constructor for customer, take reservation as reservation number

Customer::Customer(std::string name, int stay, int reservation) {
	this->name = name;
	this->stay = stay;
	this->reservation = reservation;
	this->discount = 0;
	this->total = 0;
}
//Constructor for customer, take name as customer's name, stay as customer's stay period 
//take reservation as reservation number

void Customer::setName(std::string name) {
	this->name = name;
}
//Set customer name

std::string Customer::getName() {
	return name;
}
//Get customer's name

void Customer::setStay(int stay) {
	this->stay = stay;
}
//Set customer stay period

int Customer::getStay() {
	return stay;
}
//Get customer stay period

int Customer::getReservation() {
	return reservation;
}
//Get customer's reservation number

void Customer::setDiscount(int discount) {
	this->discount = discount;
}
//Set customer discount amount

int Customer::getDiscount() {
	return discount;
}
//Get customer's discount amount

void Customer::setTotal(int total) {
	this->total = total;
}
//Set customer's total invoice

int Customer::getTotal() {
	return total;
}
//Get customer's total invoice


#endif 
