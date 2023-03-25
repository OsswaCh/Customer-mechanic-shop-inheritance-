#include "mechanic.h"
//function 
bool mechanic::isAvailable(int h, int m) {
	for (int i = 0; i < counter; i++) {
		if ((booking + i)->hours == h && (booking + i)->mins == m && (booking + i)->name != "")
			return false;
		return true;

	}

}
//getters	
int mechanic::getCounter() {
	return counter;
}

//setters
void mechanic::addapp(int h,int m, std::string Theirname) {
	(booking + counter-1)->hours = h;
	(booking + counter-1)->mins = m;
	(booking + counter-1)->name = Theirname;
	counter++;

}

void mechanic::printinfo() {
	std::cout << "name: " << getName() << ", age: " << getAge() << ", ID: " << getID() << std::endl;
}
