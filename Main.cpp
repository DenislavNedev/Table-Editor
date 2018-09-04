#include <iostream>
#include "Cell.h"
#include "Validation.h"
#include "Transformation.h"
#include "Table.h"

using namespace std;

void show_menu();
void menu(Table table);

int main() 
{

	Table table;
	show_menu();
	menu(table);

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
	cout << "\n\tPress 0 to:\t Exit\n";
}

String enter_file_directory()
{
	String file_directory;
	cin >> file_directory;
	return file_directory;
}
void menu(Table table)
{
	size_t menu_choose;
	do
	{
		cin >> menu_choose;
		switch (menu_choose)
		{
		case 1:
		{
			String file_directory;
			cout << "\n*****Example for directory: \"C:\\Users\\dnedev\\Desktop\\file.txt\"*****\n ";
			cout << "\tEnter directory of file: ";
			cin.ignore();
			cin >> file_directory;
			table.set_file_directory(file_directory);
			if (table.open_table()) 	cout << "\n\tFile succesfully opened!\n";
			else cout << "\n\tErorr! File not opened!\n";
			break;
		}
		case 2:
		{
			if (table.close_table()) cout << "File succesfully closed!\n";
			else cout << "Erorr! Try again!\n";
			break;
		}
		case 3:
		{
			if (table.save_table()) cout << "File succesfully saved!\n";
			else cout << "Erorr! Try again!\n";
			break;
		}
		case 4:
		{
			String file_directory;
			cout << "\n*****Example for directory: \"C:\\Users\\dnedev\\Desktop\\file.txt\"*****\n ";
			cout << "\tEnter directory of file: ";
			cin.ignore();
			cin >> file_directory;
			table.set_file_directory(file_directory);
			if (table.save_table()) cout << "File succesfully saved!\n";
			else cout << "Erorr! Try again!\n";
			break;
		}
		case 5:
		{
			size_t row = 0;
			cout << "\tEnter row of the cell: ";
			cin >> row;

			size_t column = 0;
			cout << "\tEnter column of the cell: ";
			cin >> column;
		
			String data;
			cout << "\tEnter data of the cell: ";
			cin.ignore();
			cin >> data;

			table.edit_cell(row,column,data);
		}
			break;
		case 6:
		{
			if (!table.print_table()) cout << "Error! Table is currently empty!\n";
			break;
		}
		case 0: return; break;
		default: cout << "Wrong number! Enter again:"; break;
		}
	} while (menu_choose != 0);
}
