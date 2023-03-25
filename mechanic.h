#include "customer.h"
#pragma once
class mechanic: public customer
{
private:
	int counter;
	customer::Appointment* booking;
public:
	//constructor + destructor
	mechanic(std::string name="", int id = 0, int age = 0) :customer(name, id, age) {
		//we are supposing that an appointment takes one hour and that the mechanic has only 24 appointments possible a dayu
		booking = new Appointment[24];
		for (int i = 0; i < 24; i++) {
			booking[i].hours = -1;
			booking[i].mins = -1;
			booking[i].name = "";
		}
		counter = 1;
	}
	~mechanic(){}

	//function 
	bool isAvailable(int, int);

	//getters
	int getCounter();
	void printinfo();

	//setters
	void addapp(int, int, std::string);
	





};

