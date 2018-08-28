#include "Formula.h"
#include <cmath>

size_t Formula::get_row_first_cell()
{
	size_t row_first_cell = 0;
	int i = 2;
	int degree = 0;
	while (data_formula[i] != 'C')
	{
		degree++;
		i++;
	}
	i = 2;
	while (data_formula[i] != 'C')
	{
		int a = (data_formula[i] - 48) * pow(10, degree - 1);
		degree--;
		row_first_cell += a;
		i++;
	}
	return row_first_cell;
}

size_t Formula::get_column_first_cell()
{
	int i = 0;
	while (data_formula[i] != 'C')
	{
		i++;
	}

	size_t column_first_cell = 0;
	int degree = 0;
	int j = i + 1;
	while (data_formula[j] != 'R')
	{
		degree++;
		j++;
	}
	while (data_formula[i + 1] != 'R')
	{
		int a = (data_formula[i + 1] - 48) * pow(10, degree - 1);
		degree--;
		column_first_cell += a;
		i++;
	}
	return column_first_cell;

}

size_t Formula::get_row_second_cell()
{
	int i = 0;
	while (data_formula[i + 2] != 'R')
	{
		i++;
	}

	size_t row_second_cell = 0;
	int degree = 0;
	int j = i + 3;
	while (data_formula[j] != 'C')
	{
		degree++;
		j++;
	}
	while (data_formula[i + 3] != 'C')
	{
		int a = (data_formula[i + 3] - 48) * pow(10, degree - 1);
		degree--;
		row_second_cell += a;
		i++;
	}
	return row_second_cell;
}

size_t Formula::get_column_second_cell()
{
	int i = 0;
	//
	while (data_formula[i] != 'C')
	{
		i++;
	}
	//
	while (data_formula[i + 1] != 'C')
	{
		i++;
	}
	//
	size_t column_second_cell = 0;
	int degree = 0;
	int j = i + 2;
	while (data_formula[j] != '\0')
	{
		degree++;
		j++;
	}
	while (data_formula[i + 2] != '\0')
	{
		int a = (data_formula[i + 2] - 48) * pow(10, degree - 1);
		degree--;
		column_second_cell += a;
		i++;
	}
	return column_second_cell;
}
