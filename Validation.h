#ifndef VALIDATION_H
#define VALIDATION_H
#include "String.h"

class Validation
{
public:	
	bool check_for_integer(String value);
	bool check_for_fraction(String value);
	bool check_for_string(String value);
	bool check_for_formula(String value);

};
#endif // !VALIDATION_H
