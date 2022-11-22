#ifndef DEF_ROOM_H
#define DEF_ROOM_H

#include <iostream>
#include <string>
#include "customer.h"

class Room {
	int number;
	bool vacancy;
	std::string type;
	Customer* customer = nullptr;
public:
	Room();
	Room(int, bool);
	void setNumber(int);
	int getNumber();
	void setType(std::string);
	std::string getType();
	void setCustomer(Customer*);
	void unsetCustomer();
	Customer* getCustomer();
	void setVacancy(bool);
	bool getVacancy();
	virtual int getPrice() = 0;
};

class Single_room : public Room {
	int price;
public:
	Single_room();
	Single_room(int, bool);
	int getPrice();
};

class Double_room : public Room {
	int price;
public:
	Double_room();
	Double_room(int, bool);
	int getPrice();
};

#endif // !DEF_ROOM_H
