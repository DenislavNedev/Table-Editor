#include "Table.h"
//Edit cell
void Table::edit_cell(size_t row, size_t column, String data)
{
	

	if (this->cells.empty())
	{
		this->add_cell(row, column, data);
	}

	bool check_for_cell = false;
	int i = 0;


	while (!check_for_cell && i<this->cells.size())
	{
		if (this->cells[i].get_row() == row && this->cells[i].get_column() == column)
		{
			this->cells[i].set_data(data);
			check_for_cell = true;
		}
		i++;
	}
	if (!check_for_cell)
	{
		this->add_cell(row, column, data);
	}
}

//Print table
void Table::print_table()
{
	
		for (int row = 1; row <= this->max_row(); row++)
		{
			for (int column = 1; column <= this->max_column(); column++)
			{
				bool check = true;
				for (int i = 0; i < this->cells.size(); i++)
				{
					if (this->cells[i].get_row() == row && this->cells[i].get_column() == column)
					{
						cout << this->cells[i].get_data();
						this->fill_empty_spaces(this->max_length()-cells[i].get_data().get_length());
						cout << " | ";
						check = false;
					}
				}
				if (check)
				{
					this->fill_empty_spaces(this->max_length());
					cout << " | ";
				}	
			}
			cout << endl;
		}
		
}

//Save table
void Table::save_table()
{
	ofstream outFile;
	outFile.open("C:\\Users\\dnede\\Desktop\\test1223.txt");

	for (int row = 1; row <= this->max_row(); row++)
	{
		for (int column = 1; column <= this->max_column(); column++)
		{
			bool check = true;
			for (int i = 0; i < this->cells.size(); i++)
			{
				if (this->cells[i].get_row() == row && this->cells[i].get_column() == column)
				{
					outFile << this->cells[i].get_data();
					//this->fill_empty_spaces(this->max_length() - cells[i].get_data().get_length());
					outFile << ",";
					check = false;
				}
			}
			if (check)
			{
			//	this->fill_empty_spaces(this->max_length());
				outFile << ",";
			}
		}
		outFile << "\n";
	}
	outFile.close();

}

//Open table
bool Table::open_table()
{
	Validation check_for_type;

	ifstream inFile;
	inFile.open("asd.txt");

	//Check For Error
	if (inFile.fail())
	{
		cerr << "Erorr Opening Files\n";
		return false;
	}

	String str;
	int row = 0;

	while (!inFile.eof())
	{
		int column = 0;
		row++;
		inFile >> str;

		int k = -1;
		for (int i = 0; i < str.get_length(); i++)
		{

			if (str[i] == ','&& i > k + 1)
			{
				column++;

				char* data = new char[i - k];
				for (int j = k + 1; j < i; j++)
				{
					data[j - k - 1] = str[j];
				}
				data[i - k - 1] = '\0';

				String a(data);
			
				if (!check_for_type.check_for_integer(a) &&
					!check_for_type.check_for_fraction(a) &&
					!check_for_type.check_for_formula(a) &&
					!check_for_type.check_for_string(a)) return false;

				this->add_cell(row, column, a);
				
			}
			if (str[i] == ',')
			{
				k = i;
			}
		}
	}

	return true;
	inFile.close();

}

void Table::add_cell(size_t row, size_t column, String data)
{
	Cell new_cell;
	new_cell.set_column(column);
	new_cell.set_row(row);
	new_cell.set_data(data);
	this->cells.push_back(new_cell);

}

size_t Table::max_row()
{
	size_t max_row = this->cells[0].get_row();

	for (int i = 1; i < this->cells.size(); i++)
	{
		if (this->cells[i].get_row() > this->cells[i - 1].get_row()) max_row = this->cells[i].get_row();
	}
	
	return max_row;
}

size_t Table::max_column()
{
	size_t max_column = this->cells[0].get_column();
	for (int i = 1; i < this->cells.size(); i++)
	{
		if (this->cells[i].get_column() > this->cells[i - 1].get_column()) max_column = this->cells[i].get_column();
	}
	return max_column;
}


size_t Table::max_length()
{
	size_t max_length = this->cells[0].get_data().get_length();

	for (int i = 1; i < this->cells.size(); i++)
	{
		if (this->cells[i].get_data().get_length() > this->cells[i - 1].get_data().get_length())
		{
			max_length = this->cells[i].get_data().get_length();
		}
	}
	return max_length;
}


void Table::fill_empty_spaces(size_t length)
{
	for (int i = 0; i < length; i++)
	{
		cout << " ";
	}
}
