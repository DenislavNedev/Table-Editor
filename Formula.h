#ifndef FORMULA_H
#define FORMULA_H
#include "String.h"

class Formula
{
public:
	size_t get_row_first_cell();
	size_t get_column_first_cell();

	size_t get_row_second_cell();
	size_t get_column_second_cell();

private:
	String data_formula;
};
#endif // !FORMULA_H
