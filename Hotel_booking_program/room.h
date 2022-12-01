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
//Constructor of room

Room::Room(int number, bool vacancy) {
	this->number = number;
	this->vacancy = vacancy;
}
//Constructor of room, take number as the room number, take vacancy as the room vacancy (booked or vacant)

void Room::setNumber(int number) {
	this->number = number;
}
//Set room number

int Room::getNumber() {
	return number;
}
//Get room number

void Room::setType(std::string type) {
	this->type = type;
}
//Set room type

std::string Room::getType() {
	return type;
}
//Get room type

void Room::setVacancy(bool vacancy) {
	this->vacancy = vacancy;
}
//Set room vacancy

bool Room::getVacancy() {
	return vacancy;
}
//Get room vacancy

void Room::setCustomer(Customer* customer) {
	this->customer = customer;
	setVacancy(false);
}
//Set customer to a room, meaning that this room is booked by this customer

void Room::unsetCustomer() {
	this->customer = new Customer(0);
	setVacancy(true);
}
//Unset customer from a room, meaning that this room is unbooked

Customer* Room::getCustomer() {
	return customer;
}
//Get a pointer to the part of memory that contain the information of the customer who book this room

Single_room::Single_room() : Room() {
	this->price = 100;
	Room::setType("Single");
}
//Constructor for single room, inherit constructor of room, add price and set type to "Single"

Single_room::Single_room(int number, bool vacancy) : Room(number, vacancy) {
	this->price = 100;
	Room::setType("Single");
}
//Constructor for single room, inherit constructor of room, take number as room number, take vacancy as room vacancy 
//add price and set type to "Single"

int Single_room::getPrice() {
	return price;
}
//Get this room's price for 1 night

Double_room::Double_room() : Room() {
	this->price = 150;
	Room::setType("Double");
}
//Constructor for double room, inherit constructor of room, add price and set type to "Double"

Double_room::Double_room(int number, bool vacancy) : Room(number, vacancy) {
	this->price = 150;
	Room::setType("Double");
}
//Constructor for double room, inherit constructor of room, take number as room number, take vacancy as room vacancy 
//add price and set type to "Double"

int Double_room::getPrice() {
	return price;
}
//Get this room's price for 1 night

#endif // !ROOM_H
