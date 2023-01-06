#ifndef MENU_DEF_H
#define MENU_DEF_H

#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include "customer.h"
#include "room.h"

//Function and class definition for class menu
//Functions for input validation, exception handling

int randGen(int, int, int);
//generate a random number between a and b, c = 1 if the return is even, c = 0 if the return is random

int input_int();
// check if the input is correct (integer) and return the integer if the input is correct

std::string input_string();
// check if the input is correct (string) and return the string if the input is correct

bool check_range(int, int, int);
//return true if a is within b and c


class Menu {
	std::vector <Room* > room;
	std::vector <Customer* > customer;
	int room_size;
public:
	Menu(int);
	void input_customer(Customer*);
	void input_room(Customer*);
	void calculate_total(Customer*);
	void write_to_file(Customer*);
	//create and update the invoice for each customer
	void input();
	void output();
	void print_customer(Customer*);
	int search_by_name(std::string);
	int search_by_reservation(int);
	void search_function();
	void change_info(Customer*, int);
	void change_info_function();
	void change_room(Customer*);
	void interface();
};
//hold the list of customers and rooms

#endif // !MENU_DEF_H
