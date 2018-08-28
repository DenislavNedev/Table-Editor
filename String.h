#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>


class String
{
public:
	String();
	String(const String& other);
	String& operator =(const String& other);
	~String();

	String(const char* data);

	friend std::istream& operator>>(std::istream& in, String& str);
	friend std::ostream& operator<< (std::ostream& output, const String& str);
	bool operator ==(String& other);
	char operator[](int number);

	size_t get_length();

private:
	char* data;
	size_t c_size;
	size_t m_size;
	void copy_data(const String& other);
	void delete_data();
};
#endif // !STRING_H
