#ifndef MENU_H
#define MENU_H
#include "String.h"
#include "Table.h"

class Menu
{
	
	bool open_file(String file_path);
	bool close_file();
	bool save_file();
	bool save_as_file(String file_path);

};
#endif // !MENU_H
