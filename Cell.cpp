#include "Cell.h"

Cell::Cell():
	row(0),column(0)
{
}

Cell::Cell(size_t row, size_t column, String data):
	row(row),column(column),data(data)
{
}

size_t Cell::get_row()
{
	return this->row;
}

size_t Cell::get_column()
{
	return this->column;
}

String Cell::get_data()
{
	return this->data;
}


void Cell::set_row(size_t row)
{
	this->row = row;
}

void Cell::set_column(size_t column)
{
	this->column = column;
}

void Cell::set_data(String data)
{
	this->data = data;
}
