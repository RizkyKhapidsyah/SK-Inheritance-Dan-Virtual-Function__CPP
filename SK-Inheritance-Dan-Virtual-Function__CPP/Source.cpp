#pragma warning(disable:4996)

#include <string.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Ship {
public:
	char name[50];
	char yearBuilt[10];

	Ship() {
		//nothing to do
	}

	Ship(char* name, char* yearBuilt) {
		strcpy(this->name, name);
		strcpy(this->yearBuilt, yearBuilt);
	}

	virtual void print() {
		cout << " Name: " << name;
		cout << "\n Year built: " << yearBuilt << endl;
	}
};


class CruiseShip : public Ship {
private:
	int passenger;

public:
	CruiseShip(char* name, char* yearBuilt, int passenger) {
		strcpy(this->name, name);
		strcpy(this->yearBuilt, yearBuilt);
		this->passenger = passenger;
	}

	void print() {
		cout << " Name: " << name;
		cout << "\n Maximum Passenger: " << passenger << endl;
	}
};


class CargoShip : public Ship {
private:
	long int capacity;

public:
	CargoShip(char* name, char* yearBuilt, long int capacity) {
		strcpy(this->name, name);
		strcpy(this->yearBuilt, yearBuilt);
		this->capacity = capacity;
	}

	void print() {
		cout << " Name: " << name;
		cout << "\n Cargo capacity: " << capacity << "tons" << endl;
	}
};

int main() {
	// Create an array of Ship pointers, initialized
	// with the addresses of 3 dynamically allocated objects.

	Ship* ships[3] = { new Ship("Lolipop", "1960"),
	new CruiseShip("Disney Magic", "1998", 2400),
	new CargoShip("Black Pearl", "1800", 50000)
	};

	// Call each object's print function.
	for (int index = 0; index < 3; index++)
	{
		ships[index]->print();
		cout << "----------------------------\n";
	}

	_getch();
	return 0;
}