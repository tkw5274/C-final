#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
//function prototypes
int saveInfo();
void searchInfo();
void readInfo();
int main(int argc, char *argv[]) 
{
	char customer;
	double serviceCost, tax, totalCost = 0;	
	string name = "";
	char appointMent;
	string address = "";
	string phoneNum = "";
	string timeSet = "";
	string dateSet = "";
	cout << "WELCOME TO TO PC TECH 4 ME!\n";
	
    while (customer != 'Y' && customer != 'N')
	{
		cout << "Are you an existing customer?\n";
		cin >> customer;
		cin.ignore();
		customer = toupper(customer);
		cout << endl;
		
		if (customer == 'Y')
		{
			cout << "What is your name? ";
			cin >> name;
			cout << "Hello " << name << ".\n";
			searchInfo();
			saveInfo();
		}	
		
		else if (customer == 'N')
		{
			readInfo();
			saveInfo();
		}
		else 
			cout << "Invalid please type Y for yes, or N for no please try again: ";
	}
}
//function definitons		
int saveInfo()
{
	char appointMent = 0;
	double serviceCost, tax, totalCost = 0;	
	//writes records to sequential access file
	string name = "";
	string address = "";
	string phoneNum = "";
	string timeSet = "";
	string dateSet = "";
	//create file object and open the file
	ofstream outFile;
	outFile.open("Customers.txt", ios::app);
	
	//determine whether the file is open
	if (appointMent != 'Y' || appointMent != 'N')
	{
		
		cout << "Would you like to make an appointment? Y for yes and N for no ";
		cin >> appointMent;
		cin.ignore();
		appointMent = toupper(appointMent);
		cout << endl;
		
		if (appointMent == 'Y')
		{
			appointMent = 'Y';
		}
		
		else if (appointMent == 'N')
		{
			return 0;
		}
	}
	if (outFile.is_open())
	{
		cout << "What is your name? ";
		getline(cin, name);
		cout << "Hello " << name << ".\n";
		cout << "What is your address" << endl;
		getline(cin, address);
		cout << "What is your phone number" << endl;
		getline(cin, phoneNum);
		cout << "What time do you want to set up an appointment? " << endl;
		getline(cin, timeSet);
		cout << "What date would you like to make that? " << endl;
		getline(cin, dateSet);
		outFile << name << '#' << address << '#' << phoneNum << '#' << timeSet << '#' << dateSet << endl;
	} //end of saveInfo function
	outFile.close();
		return 0;
}
void searchInfo()
{
	char appointMent = 0;
	//displays the record stored in filed
	string name = "";
	//create file object and open the file
	ofstream outFile;
	outFile.open("Customers.txt", ios::app);
	
	//determine whether the file is open
	if (outFile.is_open())
	{
		cout << "Welcome back" << name << ".\n" << endl;
		cout << "What service would you like? " << endl;
		readInfo();
		saveInfo();
	}
}		
void readInfo()
{
	//writes records to sequential access file
	string services = "";
	string number = "";
	string stringCost = "";
	string descr = "";
	string inputString = "";
	string name = "";
	int input = 0;
	double serviceCost, tax, totalCost = 0;
	char found = 'N';
	//create file object and open the file
	ifstream inFile;
	inFile.open("Services.txt", ios::in);
	
	//determine whether the file is open
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			getline(inFile, number, '#');
			getline(inFile, services, '#');
			getline(inFile, stringCost, '#');
			getline(inFile, descr);
			cout << number << " " << services << " - $" << stringCost << endl << "   " << descr << endl;
		}
		inFile.close();
	}
	else 
	{
		cout << "File failed to open" << endl;
	}
		cout << "What service would you like? " << endl;
		cin >> inputString;
		input = atoi(inputString.c_str());
		
		while (input <= 7 && input > 0)
		{				
			int count = 0;
			inFile.open("Services.txt", ios::in);
			if (inFile.is_open())
			{		
				getline(inFile, number, '#');
				getline(inFile, services, '#');
				getline(inFile, stringCost, '#');
				getline(inFile, descr);
				
					while (!inFile.eof()&&found == 'N') 
					{
						if (inputString == number)
						{
							found = 'Y';	
						}
						else 
						{
							getline(inFile, number, '#');
							getline(inFile, services, '#');
							getline(inFile, stringCost, '#');
							getline(inFile, descr);
						}
					}
					int num = atoi(number.c_str());
				inFile.close();
			}
			else 
			{
				cout << "File services.txt failed to open. " << endl;
			}
			// determine price
			cout << endl;
			cout << "Let me give you an estimate of the service! " << endl;
			/*getline(inFile, stringCost, '#');*/
			int cost = atoi(stringCost.c_str());	
			tax =  cost * 0.08;
			totalCost = cost + tax;
			cout << "Service Cost: $" << cost << endl;
			cout << fixed;
			cout << "Tax: $" << setprecision(2) << tax << endl;
			cout << fixed;
			cout << "Total Cost: $" << setprecision(2) << totalCost << endl;
			input = 0;
			cout << endl; 
		}	
		getline(inFile,services,'#');
		inFile.close();
		
		if (found == 'N')
		{
			cout << input << " Not valid" << endl;
		}	
			
}