#pragma once
#include <string>
class person
{
private:
	std::string name;
	int ID;
	int age;
	
public:
	//constructor
	person() : name(""), ID(0), age(0){}
	person(std::string Name, int id, int Age) : name(Name), ID(id), age(Age) {}

	// this can also be written 
	// person(std::string Name, int id, int Age) {
	/*setName(Name);
	setAge(Age);
	setID(id);
}*/

	// 
	
	//destructor
	~person() {};

	//getter
	virtual void printinfo()=0;
	
	struct Appointment {
		int hours;
		int mins;
		std::string name;
		//adding the name of the person's appointment will make it easier to write the program 
	};
	//setters
	void setName(std::string name) {
		this->name = name;
	}

	void setAge(int age) {
		this->age = age;
	}
	
	void setID(int ID) {
		this->ID = ID;
	}

	std::string getName() {
		return name;
	}
	int getID() {
		return ID;
	}
	int getAge() {
		return age;
	}

};

