#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "menu_def.h"
using namespace std;
int randGen(int a, int b, int c) {
    if (a == b) return a;
    if (c) {
        int n = abs(a - b) / 2;
        srand(static_cast<int> (time(0)));
        return min(a, b) + (rand() % n) * 2 + (min(a, b) % 2);
    }
    else {
        int n = abs(a - b);
        srand(static_cast<int> (time(0)));
        return min(a, b) + rand() % n;
    }
}
//generate a random number between a and b, c = 1 if the return is even, c = 0 if the return is random

int input_int() {
    string s;
    int ans = 0;
    bool check = false;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            check = true;
            ans = 0;
            break;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            ans *= 10;
            ans += (s[i] - '0');
        }
    }
    while (check) {
        cout << "Invalid input, please try again: ";
        getline(cin, s);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                check = true;
                ans = 0;
                break;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                ans *= 10;
                ans += (s[i] - '0');
                check = false;
            }
        }
    }
    return ans;
}
//check if the input is of type int and return an integer if it is

string input_string() {
    string s;
    bool check = false;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == ' ')) {
            check = false;
        }
        else {
            check = true;
            break;
        }
    }
    while (check) {
        cout << "Invalid input, please try again: ";
        getline(cin, s);
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == ' ')) {
                check = false;
            }
            else {
                check = true;
                break;
            }
        }
    }
    return s;
}
//check if the input is of type string and return a string if it is

bool check_range(int a, int b, int c) {
    if (b > c) swap(b, c);
    return (a >= b && a <= c);
}
//return true if the input number is within the range, else return false

Menu::Menu(int room_size) {
    this->room_size = room_size;
    for (int i = 0; i <= room_size; ++i) {
        if (i <= room_size / 2) {
            Room* r = new Single_room(i, true);
            this->room.push_back(r);
        }
        else {
            Room* r = new Double_room(i, true);
            this->room.push_back(r);
        }
    }
}
//Menu constructor, take the total number of room as parameter

void Menu::input_customer(Customer* c) {
    //TODO
    string name;
    int stay;
    cout << "Enter customer name: ";
    name = input_string();
    cout << "Enter customer stay period: ";
    stay = input_int();
    c->setName(name);
    c->setStay(stay);
}
//Use to add a new customer

void Menu::input_room(Customer* c) {
    int room_type = 0, room_number = 0, single_count = 0, double_count = 0;
    for (int i = 1; i <= room_size; ++i) {
        if (room[i]->getVacancy()) {
            if (i <= room_size / 2) single_count++;
            else double_count++;
        }
    }
    cout << "Choose your room type, 1 is single, 2 is double: ";
    room_type = input_int();
    while (!check_range(room_type, 1, 2)) {
        cout << "Out of range, please choose again: ";
        room_type = input_int();
    }
    if (room_type == 1) {
        if (single_count == 0) {
            cout << "There is no vacant single room. " << endl;
        }
        else {
            int room_choice = 1;
            cout << "If you want to pick a random room, choose 1. Otherwise, choose 0: ";
            room_choice = input_int();
            while (!check_range(room_choice, 0, 1)) {
                cout << "Out of range, please try again: ";
                room_choice = input_int();
            }
            if (room_choice) room_number = randGen(1, room_size / 2, 0);
            else {
                cout << "Choose a room between 1 and " << room_size / 2 << " : ";
                room_number = input_int();
                while (!check_range(room_number, 1, room_size / 2) || (!room[room_number]->getVacancy())) {
                    if (!check_range(room_number, 1, room_size / 2)) cout << "Out of range, please try again: ";
                    else if (!room[room_number]->getVacancy()) cout << "This room is booked, please choose another room: ";
                    room_number = input_int();
                }
            }
            room[room_number]->setCustomer(c);
        }
    }
    else if (room_type == 2) {
        if (double_count == 0) cout << "There no vacant double room. " << endl;
        else {
            int room_choice = 1;
            cout << "If you want to pick a random room, choose 1. Otherwise, choose 0: ";
            room_choice = input_int();
            while (!check_range(room_choice, 0, 1)) {
                cout << "Out of range, please try again: ";
                room_choice = input_int();
            }
            if (room_choice) room_number = randGen(room_size / 2 + 1, room_size, 0);
            else {
                cout << "Choose a room between " << room_size / 2 + 1 << " and " << room_size << " : ";
                room_number = input_int();
                while (!check_range(room_number, room_size / 2 + 1, room_size) || (!room[room_number]->getVacancy())) {
                    if (!check_range(room_number, room_size / 2 + 1, room_size)) cout << "Out of range, please try again: ";
                    else if (!room[room_number]->getVacancy()) cout << "This room is booked, please choose another room: ";
                    room_number = input_int();
                }
            }
            room[room_number]->setCustomer(c);
        }
    }
}
//Use to add room(s) to a customer

void Menu::calculate_total(Customer* c) {
    int total = 0;
    int discount = randGen(0, 2, 0) * 10;
    for (int j = 1; j <= room_size; ++j) {
        if ((!room[j]->getVacancy()) && (room[j]->getCustomer()->getReservation() == c->getReservation())) {
            total += room[j]->getPrice();
        }
    }
    total *= c->getStay();
    total = total - total * discount / 100;
    c->setDiscount(discount);
    c->setTotal(total);
}
//Use to calculate the total invoice of a customer, and also pick a random discount between 0% and 20%

void Menu::input() {
    int stop_input = 1;
    int check_available = room_size;
    do {
        if (check_available == 0) {
            stop_input = 0;
            cout << "There is no more room.\n";
        }
        else {
            int reservation = randGen(10000, 99999, 0);
            Customer* c = new Customer(reservation);
            input_customer(c);
            int stop_room_input = 1;
            do {
                if (check_available == 0) {
                    stop_room_input = 0;
                }
                else {
                    input_room(c);
                    cout << "If you want to continue the booking process, choose 1. Otherwise, choose 0: ";
                    stop_room_input = input_int();
                    while (!check_range(stop_room_input, 0, 1)) {
                        cout << "\nInvalid range, please try again: ";
                        stop_room_input = input_int();
                    }
                    check_available--;
                }
            } while (stop_room_input);
            calculate_total(c);
            customer.push_back(c);
            cout << "\nIf you want to add more customer, please choose 1. Otherwise, choose 0: ";
            stop_input = input_int();
            while (!check_range(stop_input, 0, 1)) {
                cout << "\nInvalid range, please try again: ";
                stop_input = input_int();
            }
        }
    } while (stop_input);
}
//Use to start the menu input process

void Menu::output() {
    //TODO
    cout << endl;
    cout << left << setw(20) << "Reservation number" << left << setw(20) << "Customer" << left << setw(10) << "Discount" << left << setw(10) << "Total" << left << "Room" << endl;
    for (int i = 0; i < customer.size(); ++i) {
        cout << left << setw(20) << customer[i]->getReservation() << left << setw(20) << customer[i]->getName() << left << setw(10) << to_string(customer[i]->getDiscount()) + "%" << left << setw(10) << customer[i]->getTotal();
        for (int j = 1; j <= room_size; ++j) {
            if (!room[j]->getVacancy() && (room[j]->getCustomer()->getReservation() == customer[i]->getReservation())) cout << room[j]->getNumber() << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//Print the whole customer list and their boooked room

void Menu::print_customer(Customer* c) {
    cout << left << setw(20) << "Reservation number" << left << setw(20) << "Customer" << left << setw(10) << "Discount" << left << setw(10) << "Total" << left << "Room" << endl;
    cout << left << setw(20) << c->getReservation() << left << setw(20) << c->getName() << left << setw(10) << to_string(c->getDiscount()) + "%" << left << setw(10) << c->getTotal();
    for (int i = 1; i <= room_size; ++i) {
        if (!room[i]->getVacancy() && (room[i]->getCustomer()->getReservation() == c->getReservation())) cout << room[i]->getNumber() << " ";
    }
    cout << endl;
}
//Print only one customer

int Menu::search_by_name(string name) {
    int ans = -1;
    for (int i = 0; i < customer.size(); ++i) {
        if (customer[i]->getName() == name) {
            ans = i;
            break;
        }
    }
    return ans;
}
//find a customer by their name, return the position of this customer in vector customer, return -1 if there is no match result

int Menu::search_by_reservation(int reservation) {
    int ans = -1;
    for (int i = 0; i < customer.size(); ++i) {
        if (customer[i]->getReservation() == reservation) {
            ans = i;
            break;
        }
    }
    return ans;
}
//find a customer by their reservation number, return the position of this customer in vector customer, return -1 if there is no match result

void Menu::search_function() {
    int stop = 1;
    do {
        cout << "Choose your method to find a customer, " << endl
            << "1. Find customer by their name, " << endl
            << "2. Find customer by their reservation number, " << endl
            << "Enter your choice: ";
        int find_method;
        find_method = input_int();
        while (!check_range(find_method, 1, 2)) {
            cout << "Out of range, please try again: ";
            find_method = input_int();
        }
        cout << endl;
        if (find_method == 1) {
            string name;
            cout << "Enter customer's name: ";
            name = input_string();
            if (search_by_name(name) == -1) cout << "No match result.\n";
            else print_customer(customer[search_by_name(name)]);
            cout << endl;
        }
        if (find_method == 2) {
            int reservation;
            cout << "Enter customer's reservation number: ";
            reservation = input_int();
            if (search_by_reservation(reservation) == -1) cout << "No match result.\n";
            else print_customer(customer[search_by_reservation(reservation)]);
            cout << endl;
        }
        cout << "If you want to stop this function, type 0. Otherwise, type 1: ";
        stop = input_int();
        while (!check_range(stop, 0, 1)) {
            cout << "Out of range, please try again: ";
            stop = input_int();
        }
        cout << endl;
    } while (stop);
}
//Use to find and print out a customer of choice

void Menu::change_info(Customer* c, int choice) {
    if (choice == 1) {
        string name;
        cout << "Enter the customer's name: ";
        name = input_string();
        c->setName(name);
        print_customer(c);
        cout << endl;
    }
    else if (choice == 2) {
        int stay;
        cout << "Enter the customer's stay period: ";
        stay = input_int();
        c->setStay(stay);
        calculate_total(c);
        print_customer(c);
        cout << endl;
    }
    else if (choice == 3) {
        //TODO
        change_room(c);
    }
    else if (choice == 0) {
        cout << endl << "Process ended. " << endl;
    }
}
//Use to change information of a customer

void Menu::change_info_function() {
    int stop = 1;
    do {
        int choice;
        Customer* c = new Customer(0);
        cout << "Choose your method to find a customer, " << endl
            << "1. Find customer by their name, " << endl
            << "2. Find customer by their reservation number, " << endl
            << "Enter your choice: ";
        int find_method;
        find_method = input_int();
        while (!check_range(find_method, 1, 2)) {
            cout << "Out of range, please try again: ";
            find_method = input_int();
        }
        cout << endl;
        if (find_method == 1) {
            string name;
            cout << "Enter customer's name: ";
            name = input_string();
            cout << endl;
            if (search_by_name(name) == -1) cout << "No match result.\n";
            else {
                c = customer[search_by_name(name)];
                print_customer(c);
            }
            cout << endl;
        }
        if (find_method == 2) {
            int reservation;
            cout << "Enter customer's reservation number: ";
            reservation = input_int();
            cout << endl;
            if (search_by_reservation(reservation) == -1) cout << "No match result.\n";
            else {
                c = customer[search_by_reservation(reservation)];
                print_customer(c);
            }
            cout << endl;
        }
        if (c->getReservation() == 0) {}
        else {
            cout << "Enter this customer's information that you wish to change: " << endl
                << "0. End the process" << endl
                << "1. Name, " << endl
                << "2.Stay period, " << endl
                << "3. Reserved room(s)." << endl
                << "Enter your choice: ";
            choice = input_int();
            while (!check_range(choice, 0, 3)) {
                cout << "Out of range, please try again: ";
                choice = input_int();
            }
            change_info(c, choice);
        }
        cout << "If you want to stop this function, type 0. Otherwise, type 1: ";
        stop = input_int();
        while (!check_range(stop, 0, 1)) {
            cout << "Out of range, please try again: ";
            stop = input_int();
        }
    } while (stop);
}
//Change information process

void Menu::change_room(Customer* c) {
    int stop_function = 1;
    do {
        print_customer(c);
        cout << "0. Stop this function, " << endl
            << "1. Remove room," << endl
            << "2. Add room, " << endl
            << "Enter your choice: ";
        int choice;
        choice = input_int();
        while (!check_range(choice, 0, 2)) {
            cout << "Out of range, please try again: ";
            choice = input_int();
        }
        cout << endl;
        if (choice == 0) {
            stop_function = 0;
        }
        else if (choice == 1) {
            int room_change = 0;
            cout << "Enter the room number that you want to cancel: ";
            room_change = input_int();
            while (!check_range(room_change, 1, room_size)) {
                cout << "Out of range, please try again: ";
                room_change = input_int();
            }
            if (room[room_change]->getVacancy() || room[room_change]->getCustomer()->getReservation() != c->getReservation()) cout << "This room can not be canceled. " << endl;
            else {
                room[room_change]->unsetCustomer();
                calculate_total(c);
                print_customer(c);
            }
            cout << endl;
        }
        else if (choice == 2) {
            int room_count = 0, stop = 1;
            for (int i = 1; i <= room_size; ++i) {
                if (room[i]->getVacancy()) room_count++;
            }
            if (room_count == 0) {
                cout << "There is no more room available." << endl;
            }
            else {
                while (room_count && stop) {
                    cout << "Available room: " << room_count << endl;
                    input_room(c);
                    room_count--;
                    cout << "To continue the process, choose 1, " << endl
                        << "To stop the process, choose 0. " << endl
                        << "Enter your choice: ";
                    stop = input_int();
                    while (!check_range(stop, 0, 1)) {
                        cout << "Out of range, please try again: ";
                        stop = input_int();
                    }
                }
                calculate_total(c);
                cout << endl;
            }
        }
    } while (stop_function);
}
//Use to change the reserved rooms of a customer

void Menu::interface() {
    int stop = 1;
    do {
        int choice = 0;
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << "Choose your next action, " << endl
            << "0. Close the menu " << endl
            << "1. Print all customers " << endl
            << "2. Search for a customer " << endl
            << "3. Add customer " << endl
            << "4. Change information of a customer " << endl
            << "Enter your choice: ";
        choice = input_int();
        while (!check_range(choice, 0, 4)) {
            cout << "Out of range, please try again: ";
            choice = input_int();
        }
        cout << endl << "--------------------------------------" << endl;
        if (choice == 0) {
            stop = 0;
            cout << endl;
            cout << "Have a good day. " << endl;
            cout << endl << "--------------------------------------" << endl;
        }
        else if (choice == 1) {
            cout << endl;
            output();
            cout << endl << "--------------------------------------" << endl;
        }
        else if (choice == 2) {
            cout << endl;
            search_function();
            cout << endl << "--------------------------------------" << endl;
        }
        else if (choice == 3) {
            cout << endl;
            input();
        }
        else if (choice == 4) {
            cout << endl;
            change_info_function();
            cout << endl << "--------------------------------------" << endl;
        }
    } while (stop);
}
//Print how the program menu

#endif // !MENU_H
