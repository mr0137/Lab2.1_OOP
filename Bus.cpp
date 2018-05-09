#include "Bus.h"
Bus::Bus()
{
	driver = nullptr;
	bus_number = nullptr;
	route_number = nullptr;
}

void Bus::rename(string name)
{
	delete[] driver;
	driver = new char[strlen(name.c_str()) + 1];
	strcpy(driver, name.c_str());
}

bool Bus::operator==(const Bus & obj) const
{
	return strcmp(driver, obj.driver) == 0;
}

bool Bus::operator!=(const Bus & obj) const
{
	return strcmp(driver, obj.driver) != 0;
}

ostream & operator<<(ostream & stream, Bus & obj)
{
	stream << setw(1) << obj.driver << "\t";
	stream << obj.bus_number << "\t";
	stream << obj.route_number;
	return stream;
}

istream & operator>>(istream & stream, Bus & obj)
{
	obj.driver = nullptr;
	obj.bus_number = nullptr;
	obj.route_number = nullptr;

	string str;
	getline(stream, str, ';');
	obj.driver = new char[str.length() + 1];
	strcpy(obj.driver, str.c_str());

	getline(stream, str, ';');
	obj.bus_number = new char[str.length() + 1];
	strcpy(obj.bus_number, str.c_str());

	getline(stream, str, '\n');
	obj.route_number = new char[str.length() + 1];
	strcpy(obj.route_number, str.c_str());
	return stream;
}

bool Bus::Print_route_number(const char *route)
{
	if (strcmp((const char*)route, (const char*)route_number) == 0)
	{
		return true;
	}
	return false;
}