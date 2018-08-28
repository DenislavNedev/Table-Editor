#ifndef CELL_H
#define CELL_H
#include "String.h"


class Cell
{
public:
	Cell();
	Cell(size_t row, size_t column, String data);
	
	size_t get_row();
	size_t get_column();
	String get_data();


	void set_row(size_t row);
	void set_column(size_t column);
	void set_data(String data);

protected:
	size_t row;
	size_t column;
	String data;
};

#endif // !CELL_H
