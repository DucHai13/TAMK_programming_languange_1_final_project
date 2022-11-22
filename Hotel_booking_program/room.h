#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "room_def.h"
/*
Type: true - single, false - double
Vacancy: true - vacant, false - booked
*/
Room::Room() {
	this->number = 0;
	this->type = "";
	this->vacancy = false;
	this->customer = new Customer(0);
}
Room::Room(int number, bool vacancy) {
	this->number = number;
	this->vacancy = vacancy;
}
void Room::setNumber(int number) {
	this->number = number;
}
int Room::getNumber() {
	return number;
}
void Room::setType(std::string type) {
	this->type = type;
}
std::string Room::getType() {
	return type;
}
void Room::setVacancy(bool vacancy) {
	this->vacancy = vacancy;
}
bool Room::getVacancy() {
	return vacancy;
}
void Room::setCustomer(Customer* customer) {
	this->customer = customer;
	setVacancy(false);
}
void Room::unsetCustomer() {
	this->customer = new Customer(0);
	setVacancy(true);
}
Customer* Room::getCustomer() {
	return customer;
}

Single_room::Single_room() : Room() {
	this->price = 100;
	Room::setType("Single");
}
Single_room::Single_room(int number, bool vacancy) : Room(number, vacancy) {
	this->price = 100;
	Room::setType("Single");
}
int Single_room::getPrice() {
	return price;
}

Double_room::Double_room() : Room() {
	this->price = 150;
	Room::setType("Double");
}
Double_room::Double_room(int number, bool vacancy) : Room(number, vacancy) {
	this->price = 150;
	Room::setType("Double");
}
int Double_room::getPrice() {
	return price;
}

#endif // !ROOM_H
