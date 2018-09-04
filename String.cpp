#include "String.h"

//Default constructor
String::String()
{
	m_size = 0;
	c_size = 1;
	this->data = new char[c_size];
	data[0] = '\0';
}


//Constructor
String::String(const char* data)
{
	this->m_size = strlen(data);
	c_size = 0;
	this->data = new char[m_size + 1];
	strcpy_s(this->data, m_size + 1, data);
}

//Copy constructor
String::String(const String& other)
{
	copy_data(other);
}

//Operator =
String & String::operator=(const String & other)
{
	if (this != &other)
	{
		delete_data();
		copy_data(other);
	}

	return *this;
}

bool String::operator==(String & other)
{
	if (this->m_size == other.m_size)
	{
		for (int i = 0; i < this->m_size; i++)
		{
			if (this->data[i] != other.data[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

char String::operator[](int number)
{
	int i = 0;
	bool check = false;
	while (i < this->m_size && !check)
	{
		if (i == number) check = true;
		i++;
	}
	if (check)
	{
		return this->data[number];
	}
	
}

size_t String::get_length()
{
	return this->m_size;
}

char * String::get_data()
{
	return this->data;
}

//Destuctor
String::~String()
{
	delete_data();
}

//Copy method
void String::copy_data(const String & other)
{
	this->m_size = other.m_size;
	this->data = new char[m_size + 1];
	strcpy_s(this->data, this->m_size + 1, other.data);
}

//Delete method
void String::delete_data()
{
	delete[] data;
}

//Input
std::istream& operator>>(std::istream& in, String& str)
{
	char inp;
	delete[] str.data;
	str.m_size = 0;
	str.c_size = 1;
	str.data = new char[str.c_size];
	str.data[0] = '\0';
	while (in.get(inp))
	{
		if (inp == '\n') break;
		if (str.m_size == str.c_size - 1)
		{
			str.c_size *= 2;
			char* new_data = new char[str.c_size];
			strcpy_s(new_data, str.c_size, str.data);
			delete[] str.data;
			str.data = new_data;
		}
		str.data[str.m_size++] = inp;
		str.data[str.m_size] = '\0';
	}
	return in;
}

//Output
std::ostream& operator<< (std::ostream& output, const String& str)
{
	//output << strlen(str.data) << endl;
	for (int i = 0; i < strlen(str.data); i++)
	{
		output << str.data[i];
	}
	return output;
}
