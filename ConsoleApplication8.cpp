// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

class FahrenheitSensor
{
public:
	float getFahrenheitTemp() {
		float t = 32.0;
		// some code 
		return t;
	}
protected:
	void adjust() {} // Setting sensor protected method  
};

class Sensor
{
public:
	virtual ~Sensor() {}
	virtual float getTemperature() = 0;
	virtual void adjust() = 0;
};

class Adapter : public Sensor, private FahrenheitSensor
{
public:
	Adapter() { }
	float getTemperature() {
		cout << "getFahrenheitTemp :"<< getFahrenheitTemp() << endl;
		return (getFahrenheitTemp() - 32.0)/ 1.8;
	}
	void adjust() {
		FahrenheitSensor::adjust();
	}
};

int main()
{
	Sensor * p = new Adapter();
	p->adjust();
	cout << "Celsius temperature = " << p->getTemperature() << endl;
	delete p;
	cin.get();
	return 0;
}