#include <iostream>
#include <fstream>
//#include <queuee>
#include "customer.h"
#include "mechanic.h"
#include "queuee.cpp"
using namespace std;

//make sure to revise the queuee class
//why is the name of the mech not showing

template<typename t>
void showq(const queuee<t> gq)
{

	//it pops keeps the objects shows it and goes on
	queuee<t> cq = gq;
	t b;
	while (!cq.isEmpty()) {
		cout << '\t';
		cout << cq.peek().getName() << " at ";
		cq.peek().getapp();
		cout << "with";
		cq.peek().getMechName();
		cq.pop();
		cout << '\n';
	}
	cout << '\n';
}

template<typename T>
void sort(queuee<T>& q, int size) {
	if (q.size() <= 1) {
		return;
	}
	int n = q.size();
	T x = q.peek();
	q.pop();
	sort(q, size);
	int count = 0;
	queuee<T> smaller, greater;
	while (!q.isEmpty()) {
		if (q.peek() < x) {
			smaller.push(q.peek());
		}
		else {
			greater.push(q.peek());
		}
		q.pop();
	}
	while (!smaller.isEmpty()) {
		q.push(smaller.peek());
		smaller.pop();
	}
	q.push(x);
	while (!greater.isEmpty()) {
		q.push(greater.peek());
		greater.pop();
	}
}




int main() {
	
	string aux;
	int sizeM=10; int sizeC;
	cout << "how many mechanics do you have?" << endl;
	cin >> sizeM;
	cout << "how many customers do you expeect to have?" << endl;
	cin >> sizeC;

	ifstream mechanics("mechanics.txt");
	if (mechanics.fail())
		cout << "failed to open"<<endl;
	
	//an array having all of the mechanics and an other having all the customers 
	mechanic* Mlist = new mechanic[sizeM];
	customer* Clist = new customer[sizeC];
	
	//queue of the organized customers
	queuee <customer> orgClient;

	int i = 0; int j = 0;

	
	//******* this is the implementation with the file , however i had a compiler problem where it was not reading the file, even though there was no probloem with the code
	//no problem with the name of the file, and with after trying every way possible to open and read from a file, it still was failing to open
	// i do believe this is a compiler problem since all  
	
	/*while (getline(mechanics, aux)) {
		(Mlist + i)->setName(aux);
		getline(mechanics, aux);
		(Mlist + i)->setAge(stoi(aux));
		getline(mechanics, aux);
		(Mlist + i)->setID(stoi(aux));
		getline(mechanics, aux);
		int numapp = stoi(aux);
		while (numapp) {
			getline(mechanics, aux);
			int h = stoi(aux);
			getline(mechanics, aux);
			int m = stoi(aux);
			(Mlist + i)->addapp(h, m,"");
		}
		i++;
	}
	mechanics.close();
	ifstream customers("customers.txt");
	while (getline(customers, aux)) {
		(Clist + i)->setName(aux);
		getline(customers, aux);
		(Clist + i)->setAge(stoi(aux));
		getline(customers, aux);
		(Clist + i)->setID(stoi(aux));
		getline(customers, aux);
		int numapp = stoi(aux);
		while (numapp) {
			getline(customers, aux);
			int h = stoi(aux);
			getline(customers, aux);
			int m = stoi(aux);
			(Clist + i)->setApp(h, m);
		}
		j++;
	}
	customers.close();*/

	for (int k = 0; k < sizeM; k++) {
		string name; int id; int age; 
		cout << "enter the mechanic name";
		cin >> name;
		cout << "enter the mechanic age";
		cin >> age;
		cout << "enter the mechanic id";
		cin >> id;
		(Mlist + k)->setName(name);
		(Mlist + k)->setAge(age);
		(Mlist + k)->setID(id);
		i++;
	}

	for (int k = 0; k < sizeC; k++) {
		string name; int id; int age; int h; int m;
		cout << "enter the customer name";
		cin >> name;
		cout << "enter the customer age";
		cin >> age;
		cout << "enter the customer id";
		cin >> id;
		cout << "enter the customer hour";
		cin >> h;
		cout << "enter the customer min";
		cin >> m;

		(Clist + k)->setName(name);
		(Clist + k)->setAge(age);
		(Clist + k)->setID(id);
		(Clist + j)->setApp(h, m);
		j++;
	}

	//this just to check this have been allocated correctly
	for (int k = 0; k < i; k++) {
		(Mlist + k)->printinfo();
	}
	for (int k = 0; k < j; k++) {
		(Clist + k)->printinfo();
	}

	//checks the availability of the mechanic and gets the rest of the division by the total number of mechanics
	//to make sure it is moving in a circular movement
	int n = 0; int m = 0;
	while (n<j) {
		
		if ((Mlist + m)->isAvailable((Clist + n)->getH(), (Clist + n)->getM())) {
			(Mlist + m)->addapp((Clist + n)->getH(), (Clist + n)->getM(), (Clist + n)->getName());
			orgClient.push(*(Clist + n));
			(Clist + n)->setMech((Mlist + m%i)->getName());
			(++n); (++m);
		}
		else
			m=(++m) % i;
	}

	//this is to show that the function getMechName() works, but for some reason it does not work in the showq function
	//i have discussed this problem with some of the TAs and we concluded that it was a cmpiler issue
	for (int k = 0; k < j; k++) {
		(Clist + k)->getMechName();
		cout << endl;
	}

	cout << "before";

	//shows how the queue looked before 
	showq<customer>(orgClient);
	//sorts the queue
	sort(orgClient,j);
	cout << "after";
	showq<customer>(orgClient);
	


	return 0;
}