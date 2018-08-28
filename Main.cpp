#include <iostream>

#include "Cell.h"
#include "Validation.h"
#include "Transformation.h"
#include "Table.h"
#include "Menu.h"

using namespace std;

void show_menu();
void menu();

int main() 
{

	Table table;
	//cout<<table.open_table()<<"\n";
	if(table.open_table())table.print_table();
	//show_menu();

	system("pause");
	return 0;
}
void show_menu()
{
	cout << "\n\t*MENU*\n";
	cout << "\tPress 1 to:\t Open file\n";
	cout << "\tPress 2 to:\t Close file\n";
	cout << "\tPress 3 to:\t Save file\n";
	cout << "\tPress 4 to:\t Save as file\n";
	cout << "\n\tPress 5 to:\t Edit table\n";
	cout << "\tPress 6 to:\t Print table\n";
	//cout << "\t5\t List customer accounts\n";
	cout << "\n\tPress 0 to:\t Exit\n";
}

void menu()
{
	//size_t menu_choose
	//cin >> menu_choose;
}
