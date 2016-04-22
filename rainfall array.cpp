#include <iostream>
#include <iomanip> 
#include <string> // string used in functions and statements to pass names of months
using namespace std;


string maximum_rainfall (double array_index[], string monthsarray[], int numberofmonths); //brackets left empty to accept passed address of array elements
string minimum_rainfall (double array_index[], string monthsarray[], int numberofmonths);
double totalrainfunction (double array_index[], int numberofmonths);
double averagerainfunction (double array_index[], int numberofmonths);

void SortFunction (string array_index[], double monthsarray[], int numberofmonths); //new sorting function


int main()
{
	double averagerain=0.0;
	double totalrain=0.0;
	string monthminrain; // to hold the values used from function calculations
	string monthmaxrain;
	
	const int numberofmonths=12; // hold number of months as individual elements in array
	string monthsarray[numberofmonths]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; //hold the names of the elements
	double userdata[numberofmonths]; //hold the values taken from user input
	

	for (int increment=0; increment < numberofmonths; increment++) // based on numberofmonths being set as a constant int, this loop will run 12 times
		{	
			cout << "Please enter the rainfall for " << monthsarray[increment] <<": ";
			cin >> userdata[increment];
			
		
		if (userdata[increment] < 0) // input validation to prevent a negative number being entered
			{
				cout << "Invalid data (negative rainfall) -- retry\n";
				cout << "Please re-enter the rainfall for " << monthsarray[increment] <<": ";
				cin >> userdata[increment];
			}
	
		}
	// functions are used below
	monthmaxrain = maximum_rainfall(userdata, monthsarray, numberofmonths);
	monthminrain = minimum_rainfall(userdata, monthsarray, numberofmonths);
	totalrain = totalrainfunction(userdata, numberofmonths);
	averagerain = averagerainfunction(userdata, numberofmonths);

	cout << "Total rainfall for the year is: " << totalrain << " inches."<< endl;
	cout << "Average rainfall for the year is: " << averagerain << " inches.\n";
	cout << "The smallest amount of rainfall was in: " << monthminrain << endl;
	cout << "The largest amount of rainfall was in: " << monthmaxrain << endl << endl;
	cout << "Here are the rainfall amounts, sorted in ascending order:\n";
	cout << "______________________________________________________________" << endl;

	SortFunction(monthsarray, userdata, numberofmonths);
	
	return 0;
}

string maximum_rainfall (double array_index[], string monthsarray[], int numberofmonths) 
{// start array startScan by counting from 1st (January's) user-entered data
	double maximum=array_index[0]; 
	int index_value=0;
	
	for (int count=0; count < numberofmonths; count++)
		if (array_index[count]>maximum) // highest number determined here
		{
			maximum=array_index[count]; // this portion uses the highest number and links it to array startScan
			index_value=count;
		}
	return monthsarray[index_value]; //index_value returns element linked as highest number within array based on user input
}

string minimum_rainfall (double array_index[], string monthsarray[], int numberofmonths)
{// almost exact copy of above function except for variable names and reversal of greater than operator
	double minimum=array_index[0];
	int index_value=0;
	
	for (int count=0; count < numberofmonths; count++)
			if (array_index[count]<minimum)
			{
				minimum=array_index[count]; //as previous function, except the lowest number is pointed to within array
				index_value=count;
			}
	return monthsarray[index_value];
}

double totalrainfunction (double array_index[], int numberofmonths)
{
	double totalrainfall=0.0;
	for (int count=0; count < numberofmonths; count++)
		totalrainfall+=array_index[count];// this statement adds all values inside each element
	return totalrainfall;
}



double averagerainfunction (double array_index[], int numberofmonths)
{
	double averager=0.0;

	for (int count=0; count < numberofmonths; count++)
	{
		averager+=array_index[count];//adds all values
	}
	double averager_rainfall = 0.0;
	averager_rainfall = averager / numberofmonths ;// divides sum by number of elements to return average
	return averager_rainfall;
}

// the added function to the original program to re-sort user-submitted numbers throughout the array
void SortFunction(string array_index[], double monthsarray[], int numberofmonths) // Selection Sort
{
	int topsort;
	int startScan;
	int index;
for (startScan = 0; startScan < numberofmonths - 1; startScan++) //start scan at element 0 and go up to next to last element
	{
    topsort = startScan; 

    for (index = startScan + 1; index < numberofmonths; index++)
		{
			if (monthsarray[index] < monthsarray[topsort])  //determines the element to start with
			{
				topsort = index;
			}
		}   

    // values being swapped to positions desired
	
    double tempswapdouble = monthsarray[startScan];
    monthsarray[startScan] = monthsarray[topsort];
    monthsarray[topsort] = tempswapdouble;

    string stringholder = array_index[startScan];
    array_index[startScan] = array_index[topsort];
    array_index[topsort] = stringholder;
	}
for(startScan=0; startScan<=11; startScan++) // show months in sorted order
 {
     cout << setprecision(2) << fixed << monthsarray[startScan] << endl;
 }
return;
}
