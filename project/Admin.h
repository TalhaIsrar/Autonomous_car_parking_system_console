//importing required libraries and user defined header file
#include<iostream>
#include<string>
#include<fstream>
#include "Vehicle.h"
#include "Cabin.h"

using namespace std;//indicating which namespace to use
//using preprocessor wrappers to avoid multiple definition errors

#ifndef ADMIN_H
#define ADMIN_H

class admin
{
	//declaring passowrd and file name as static
	static int password;
	static string filename;

public:
	fstream admin_file;
	//destructor
	~admin();
	void check_admin_file();
	void make_admin_file();
	void delete_admin_file();
	static bool verify_password(int pass);
	void set_filename(string file);
	static string get_filename();
	void read_admin_file();
	void edit_admin_file();
	void read_vehicle();
	vector<store> read_to_vector();
	int calc_money();
	void operator-();
};
#endif