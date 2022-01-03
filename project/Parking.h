//importing required libraries and user defined header file
#include<iostream>
#include<string>
#include<fstream>

using namespace std;//indicating which namespace to use
//using preprocessor wrappers to avoid multiple definition errors

#ifndef PARKING_H
#define PARKING_H

class parking
{
protected:
	int cabins;
	double fee_car;
	double fee_bike;
	int hrs;
	double fine_car;
	double fine_bike;

public:
	int get_cabins();
	int get_fee_car();
	int get_fine_car();
	int get_fee_bike();
	int get_fine_bike();

	//friend function
	friend parking make_parking_profile();
};

parking make_parking_profile();

#endif