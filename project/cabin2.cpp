#include<iostream>
#include<string>
#include<fstream>
#include "Cabin.h"

using namespace std;

cabin::cabin()
{

}

cabin::cabin(int num)
{
	cabin_num = num;
	type = 0;
	password = 0;
	num_plate = 0;
	parked = 0;
	time = 0;
}

cabin::cabin(int num, int park)
{
	cabin_num = num;
	type = 0;
	password = 0;
	num_plate = 0;
	parked = park;
	time = 0;
}

cabin::cabin(int num, int park, int category, int plate, time_t times)
{
	cabin_num = num;
	password = 0;
	type = category;
	num_plate = plate;
	parked = park;
	time = times;
}

int cabin::get_cabin_num()
{
	return cabin_num;
}

cabin_data::cabin_data() : filename("cabin_file")
{
}

void cabin_data::check_data_file()
{
	cabin_file.open(filename, ios::in);
	if (cabin_file)
	{
		cout << "file exists" << endl;
		cabin_file.close();
	}
	else
	{
		cout << "file doesn't exist" << endl;
		make_data_file();
	}
}

void cabin_data::make_data_file()
{
	cabin_file.open(filename, ios::out);
	cout << "New file created" << endl;
	cabin_file.close();
}


void cabin_data::initial_cabin_data(int no_of_cabins)
{
	cabin_file.open(filename, ios::out);
	for (int i = 1; i <= no_of_cabins; i++)
	{
		//cabin_num, parked_status, type, password, num_plate, park_time
		cabin_file << to_string(i) + ",0,-1,-1,-1,-1\n";
	}
	cabin_file.close();
}


void cabin_data::edit_cabin_data(cabin c, int size)
{
	string line;
	cabin_file.open(filename, ios::in);

	fstream temp;
	temp.open("temp_file", ios::out);
	if (!temp) {
		cout << "Error in temp file" << endl;
	}
	else {
		char ch;
		string* lines = new string[20];
		int i = -1;
		std::string myline;
		if (cabin_file.is_open()) {
			while (cabin_file) {
				cout << i << "before" << endl;
				std::getline(cabin_file, myline);
				lines[++i] = myline;
				cout << i << "after" << endl;
			}
		}

		cout << cabins << endl;
		string* values = new string[10];
		for (int j = 0; j < size - 1; j++)
		{
			cout << "in loop" << endl;
			int k = 0;
			string val;
			ch = lines[j][k];
			while (ch != ',')
			{
				val += ch;
				ch = lines[j][++k];
			}
			cout << val << endl;
			if (c.cabin_num == stoi(val))
			{
				temp << to_string(c.cabin_num) + "," + to_string(c.parked) + "," + to_string(c.type) + ","
					+ to_string(c.password) + "," + to_string(c.num_plate) + "," + to_string(c.time) << endl;
			}
			else
			{
				temp << lines[j];
			}
		}
	}
	temp.close();
	cabin_file.close();

	cabin_file.open(filename, ios::out);
	temp.open("temp_file", ios::in);
	if (cabin_file.is_open())
	{
		while (getline(temp, line))
		{
			cabin_file << line;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	temp.close();
	cabin_file.close();
}

void cabin_data::delete_car_file()
{
	cabin_file.open(filename, ios::out);
	cabin_file << "";
	cabin_file.close();
}

cabin* cabin_data::read_file_to_array()
{
	cabin cab[10];
	cabin_file.open(filename, ios::in);

	if (cabin_file.is_open()) {
		string tp;
		int k = 0;
		while (getline(cabin_file, tp))
		{
			string temp = "";
			int j = 0;
			for (int i = 0; i <= (int)tp.size(); i++)
			{
				// If cur char is not del, then append it to the cur "word", otherwise
				  // you have completed the word, print it, and start a new word.
				if (tp[i] != ',') {
					temp += tp[i];
				}
				else {
					try
					{

						cout << temp << endl;
						switch (j)
						{
						case 0:
							cab[k].cabin_num = stoi(temp);
							break;

						case 1:
							cab[k].parked = stoi(temp);
							break;

						case 2:
							cab[k].type = stoi(temp);
							break;

						case 3:
							cab[k].password = stoi(temp);
							break;

						case 4:
							cab[k].num_plate = stoi(temp);
							break;

						case 5:
							cab[k].time = stod(temp);
							break;
						}

						j++;
						temp = "";

						throw "Cannot convert string to int";
					}

					catch (const char* exception)
					{
						cerr << "Error: " << exception << endl;
					}

				}
			}
			k++;
		}
		cabin_file.close();
	}
	cabin_file.close();
	return cab;
}