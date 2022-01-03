#include<iostream>
#include<string>
#include<fstream>

using namespace std;//indicating which namespace to use
//using preprocessor wrappers to avoid multiple definition errors
#ifndef STORE_H
#define STORE_H

class store
{
public:
	string vehicle_num;
	string vehicle_type;
	string park_time;
	string exit_time;
	string fee;
	string fine;
};

#endif
