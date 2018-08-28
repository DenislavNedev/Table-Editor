#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include <fstream>
#include <iomanip>      // std::setw
#include "Cell.h"
#include "Validation.h"

using namespace std;
	class Table
{
public:
	
	void edit_cell(size_t row, size_t column, String data);
	void print_table();
	
	void save_table();
	bool open_table();

	size_t max_length();

protected:
	vector<Cell> cells;
	void add_cell(size_t row, size_t column, String data);
	size_t max_row();
	size_t max_column();
	void fill_empty_spaces(size_t length);

};
#endif // !TABLE_H
