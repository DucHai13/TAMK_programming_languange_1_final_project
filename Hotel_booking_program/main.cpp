#include <iostream>
#include "customer.h"
#include "room.h"
#include "menu.h"
using namespace std;
int main() {
	int room_size = randGen(30, 70, 1);
	Menu menu(room_size);
	menu.input();
	menu.interface();
	return 0;
}