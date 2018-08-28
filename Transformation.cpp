#include "Transformation.h"
int Transformation::transform_into_int(String value)
{
	int number = 0;
	int digits = value.get_length();
	for (int i = 0; i < value.get_length(); i++)
	{
		number = number + ((value[i]-48) * pow(10, digits-1));
		digits--;
	}
	return number;
}

double Transformation::transform_into_fraction(String value)
{

	double number = 0;
	int digits_before_dot = 0;
	int k = 0;

	while (value[k++] != '.')
	{
		digits_before_dot++;
	}

	int digits_after_dot = value.get_length() - digits_before_dot - 1;


	int j = digits_before_dot+1; // Laterly used for the loop

	for (int i = 0; i < value.get_length()- digits_after_dot-1; i++)
	{
		number = number + ((value[i] - 48) * pow(10, digits_before_dot - 1));
		digits_before_dot--;
}

	int t = -1;
	for (; j < value.get_length(); j++)
	{
		number = number + ((value[j] - 48)*(pow(10,t)));
		t--;
	}

	return number;
	
}
