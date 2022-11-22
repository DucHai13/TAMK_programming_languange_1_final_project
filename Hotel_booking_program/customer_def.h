#ifndef DEF_CUSTOMER_H
#define DEF_CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
	std::string name;
	int stay;
	int reservation;
	int discount;
	int total;
	public:
		Customer(std::string, int, int);
		Customer(int );
		void setName(std::string);
		std::string getName();
		void setStay(int);
		int getStay();
		int getReservation();
		void setDiscount(int);
		int getDiscount();
		void setTotal(int);
		int getTotal();
};

#endif