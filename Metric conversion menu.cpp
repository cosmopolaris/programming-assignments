#include <iostream>
using namespace std;

void MiToKM();
void FtoCelsius();
void FeetToMeters();
void GallonToLiter();
void PoundToGram();
void Menu();
void KeepRunning(int menuselect);

int main() 
{
int menuselect;
	cout << "This program performs five different conversions\n between Imperial and Metric units of measurement." << endl;
do//do-while loop is used because it must run at least once
	{
	Menu();
	cin >> menuselect;
	KeepRunning(menuselect);
	} 
while (menuselect != 0);//should the user enter 0, the loop ends and the program terminates
return 0;
}

void Menu()
{
	cout << "\nChoose from the menu a number that corresponds \nto the type of conversion you wish to employ.\n" << endl;
	cout << " 1. Miles to Kilometers\n 2. Fahrenheit to Celsius\n 3. Feet to Meters\n 4. Gallons to Liters \n 5. Pounds to Grams\n 0. Quit" << endl;
	cout << "\nPlease make a selection." << endl;
}

void KeepRunning(int menuselect)
{
	switch (menuselect)
	{
	case 1: MiToKM();
	break;
	case 2: FtoCelsius();
	break;
	case 3: FeetToMeters();
	break;
	case 4: GallonToLiter();
	break;
	case 5: PoundToGram();
	break;
	default:
	cout << "Please choose between options 1-5 or enter 0 to quit.\n";	
    break;
	}
}

void MiToKM()
{
	double miles;
	double meters;
	cout << "Enter number of miles.";
	cin  >> miles;
	meters = miles * 1.6;
	cout << "That's " << meters << " kilometers." << endl;
}

void FtoCelsius()
{
	double celsius;
	double fahrenheit;
	cout << "Enter temperature in Fahrenheit." << endl;
	cin >> fahrenheit;
	celsius = (fahrenheit - 32) * 5/9;
	cout << "It is" << celsius << " degrees Celsius." << endl;
}

void FeetToMeters()
{
	double feet;
	double onemeter;
	cout << "Enter number of feet." << endl;
	cin >> feet;
	onemeter = feet / 3.2808;
	cout << "That's " << onemeter << " meters." << endl;
}

void GallonToLiter()
{
	double gallon;
	double liter;
	cout << "Enter number of gallons." << endl;
	cin >> gallon;
	liter = gallon / 0.26417;
	cout << "That's " << liter << " liters." << endl;
}

void PoundToGram()
{
	double pound;
	double gram;
	cout << "Enter number of pounds." << endl;
	cin >> pound;
	gram = pound / 0.0022046;
	cout << "That's " << gram << "grams." << endl;
}
