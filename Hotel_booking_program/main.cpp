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
	//menu.output();
	//menu.search_function();
	//menu.change_info_function();
	//menu.change_info_function()
	return 0;
}