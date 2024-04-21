#include <iostream>
#include <vector>
#include <algorithm> // Include algorithm header for std::for_each

class Observer
{
public:
	virtual void update(double temperature) = 0;
};

class TemperatureSensor
{
public:
	void addObserver(Observer *observer)
	{
		observers.push_back(observer);
	}

	void removeObserver(Observer *observer)
	{
		observers.erase(std::remove_if(observers.begin(), observers.end(), [observer](Observer *obs)
									   { return obs == observer; }),
						observers.end());
	}

	void notifyObservers()
	{
		std::for_each(observers.begin(), observers.end(), [this](Observer *observer)
					  { observer->update(temperature); });
	}

	void setTemperature(double temp)
	{
		temperature = temp;
		notifyObservers();
	}

private:
	double temperature;
	std::vector<Observer *> observers;
};

class TemperatureDisplay : public Observer
{
public:
	void update(double temperature) override
	{
		std::cout << "Temperature Display: Temperature is now " << temperature << " degrees Celsius." << std::endl;
	}
};

int main()
{
	TemperatureSensor sensor;

	TemperatureDisplay display1;
	TemperatureDisplay display2;

	sensor.addObserver(&display1);
	sensor.addObserver(&display2);

	sensor.setTemperature(25.0);

	sensor.removeObserver(&display1);

	sensor.setTemperature(22.3);

	return 0;
}
