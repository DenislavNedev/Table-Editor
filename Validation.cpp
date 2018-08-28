#include "Validation.h"

//Check if the data in the cell is integer
bool Validation::check_for_integer(String value)
{
	bool check_for_int = true;
	if (value[0] == '+' || value[0] == '-' || (value[0] > 47 && value[0] < 58))
	{
		int i = 1;
		while (i < value.get_length() && check_for_int)
		{
			if (value[i] < 48 || value[i] > 57) check_for_int = false;
			i++;
		}
	}
	else
	{
		return false;
	}
	
	if (check_for_int) return true;
	else return false;
}

//Check if the data in the cell is fraciton
bool Validation::check_for_fraction(String value)
{

	bool check_for_fraciton = true;
	size_t check_for_dot = 0;
	if (value[0] == '.') return false;
	if (value[0] == '+' || value[0] == '-' || (value[0] > 47 && value[0] < 58))
	{
		int i = 1;
		while (i < value.get_length() && check_for_fraciton)
		{
			if (value[i] < 48 || value[i] > 57)
			{
				if (value[i] == '.') check_for_dot++;
				else check_for_fraciton = false;
			}
			i++;
		}
	}
	else
	{
		return false;
	}
	if (check_for_fraciton && check_for_dot == 1) return true;
	else return false;

}

//Check if the data in the cell is string
bool Validation::check_for_string(String value)
{
	if (value[0] == ' " ' && value[value.get_length() - 1] == ' " ') return true;
	else return false;
}

//Check if the data in the cell is formula
bool Validation::check_for_formula(String value)
{
	if (value[0] == '=') return true;
	else return false;
}
