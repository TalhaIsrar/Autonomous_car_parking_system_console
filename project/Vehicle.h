//importing required libraries and user defined header file
#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include "Parking.h"
#include "Store.h"

using namespace std;//indicating which namespace to use
//using preprocessor wrappers to avoid multiple definition errors
#ifndef VEHICLE_H
#define VEHICLE_H

//class vehicla_data  inheriitng the properties of class parking
//abstract class
class vehicle_data: public parking
{
	const string filename;
	int file_length;

public:
	vehicle_data();
	fstream vehicle_file;

	void check_vehicle_file();
	void make_vehicle_file();
	void edit_vehicle_file(string vehicle_num, string type, string enter_time, string exit_time, string fee, string fine);
	void delete_vehicle_file();
	void initial_data();
	void read_vehicle_file();
	int calculate_money();
	vector<store> read_to_vector();
};

//class vehicle inheriitng the properties of class parking
class vehicle : public parking
{
protected:
	int num_plate;
	time_t park_time;
	time_t exit_time;
	int cabin;

public:
	void set_values(parking p);
	void set_custom_park_time(time_t t);
	void set_cabin(int cab);
	void set_num_plate(int num);
	void set_park_time();
	void set_exit_time();
	double get_exit_time();
	int get_plate();
	time_t get_park_time();
	//pure virtual functions
	virtual double calculate_fee() = 0;
	virtual double calculate_fine() = 0;
	virtual int get_type() = 0;

	double calculate_time();
};
//class car inheriitng the properties of vehicle
class car : public vehicle
{
public:
	int get_type();
	double calculate_fee();
	double calculate_fine();
	~car();
};
//class bike inheriitng the properties of vehicle
class bike : public vehicle
{
public:
	int get_type();
	double calculate_fee();
	double calculate_fine();
	//destructor
	~bike();
};

#endif
