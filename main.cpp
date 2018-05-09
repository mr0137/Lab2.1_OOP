#include <iostream>
#include "List.h"
#include "Bus.h"

int main()
{
    List<Bus> park;
    List<Bus> outside;
    List<Bus>::iterator iter;
    int i;

    park.load("data.csv");
	cout << " Park: " << endl;
	for (iter = park.begin(), i = 1; iter != park.end(); ++iter, ++i) 
	{
		cout << " " << i << ". ";
		(*iter).Print();
	}
	cout << "\nFirst driver outside park:" << endl;
	park.splice(park.begin(), outside);
	cout << " Park: " << endl;
	for (iter = park.begin(), i = 1; iter != park.end(); ++iter, ++i)
	{
		cout << " " << i << ". ";
		(*iter).Print();
	}
	cout << " Outside: " << endl;
	for (iter = outside.begin(), i = 1; iter != outside.end(); ++iter, ++i)
	{
		cout << " " << i << ". ";
		(*iter).Print();
	}

	cout << "\nDriver back to park:" << endl;
	outside.splice(outside.begin(), park);
	cout << " Park: " << endl;
	park.Print();
	cout << " Outside: " << endl;
	outside.Print();
	
	cout << "\n Rename first driver in Park :\n";
	park.rename((park.begin()),"Alexus");

	cout << " Park: " << endl;
	park.Print();
	cout << "\n Buses that move along the route 44 :\n";
	park.Print_route_number(park.begin(), "44");

	system("pause");
	return 0;
}
