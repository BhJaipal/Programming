#include <string>
#include <iostream>

class Vehicle
{
protected:
	std::string make;
	std::string model;
	int year;
};

class Car : public Vehicle
{
	double distanceTraveled;
	double fuelConsumed;

public:
	Car(std::string _make, std::string _model, int _year, double _distanceTraveled, double _fuelConsumed)
	{
		make = _make;
		model = _model;
		year = _year;
		distanceTraveled = _distanceTraveled;
		fuelConsumed = _fuelConsumed;
	}
	void display()
	{
		std::cout << "Make: " << make << "\n";
		std::cout << "Car Model: " << model << "\n";
		std::cout << "Year: " << year << "\n";
	}
	double calculateMileage()
	{
		if (fuelConsumed <= 0)
		{
			std::cout << "Invalid fuel consumption";
			std::cout << "\n";
			return 0;
		}
		return distanceTraveled / fuelConsumed;
	}
};
class Motorcycle : public Vehicle
{
	double distanceTraveled;
	double fuelConsumed;

public:
	Motorcycle(std::string _make, std::string _model, int _year, double _distanceTraveled, double _fuelConsumed)
	{
		make = _make;
		model = _model;
		year = _year;
		distanceTraveled = _distanceTraveled;
		fuelConsumed = _fuelConsumed;
	}
	void display()
	{
		std::cout << "Make: " << make << "\n";
		std::cout << "Motorcycle Model: " << model << "\n";
		std::cout << "Year: " << year << "\n";
	}
	double calculateMileage()
	{
		if (fuelConsumed <= 0)
		{
			std::cout << "Invalid fuel consumption";
			std::cout << "\n";
			return 0;
		}
		return distanceTraveled / fuelConsumed;
	}
};

int main(int argc, char const *argv[])
{
	Car car("Toyota", "Camry", 2021, 1000, 0);
	car.display();
	std::cout << car.calculateMileage() << "\n";
	std::cout << "\n";
	Motorcycle motorcycle("Hero honda", "I don't know", 2017, 637220, 630);
	motorcycle.display();
	std::cout << motorcycle.calculateMileage() << "\n\n";
	return 0;
}
