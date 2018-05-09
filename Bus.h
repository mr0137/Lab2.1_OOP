#pragma once

#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "List.h"
#include <iomanip> 
#pragma warning (disable:4996)

//using namespace std;

class Bus
{
public:
	Bus();
	~Bus() {};
	void rename(string name);
	bool Print_route_number(const char *route);
	/*	methods	*/
	friend ostream& operator<<(ostream& stream, Bus &obj);
	friend istream& operator>>(istream& stream, Bus &obj);


	bool operator==(const Bus &obj) const;
	bool operator!=(const Bus &obj) const;

private:
	char *driver;
	char *bus_number;
	char *route_number;
};
