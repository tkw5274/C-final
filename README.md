Synopsis

This program is going to personally greet you by name when you first open it and inform you of the business that you are scheduling with. Then it will ask you what type of computer services you need by giving you options to pick, using numbers for you to select. Once you pick which service you want, it will calculate the total and include the sales tax. Then the program will allow the user to set up an appointment for the services previously selected. 

Code Example

if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			getline(inFile, number, '#');
			getline(inFile, services, '#');
			getline(inFile, stringCost, '#');
			getline(inFile, descr);
			cout << number << " " << services << " $" << stringCost << " " << descr << endl;
		}
		inFile.close();
	}
	else 
	{
		cout << "File failed to open" << endl;
	}
		cout << "What service would you like? ";
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
				


Motivation

This program will be beneficial to companies who utilize on-call and call-out services. The program will be user friendly, easy customizable and less likely to have technical errors versus competitors. It will be efficient and cost effective for business and less time consuming for the consumer.

Installation

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
	}
	outFile.close();
		return 0;


Tests

WELCOME TO TO PC TECH 4 ME!
Are you an existing customer!
n
1  Basic Computer Service $30 This includes a complete system check, computer case clean out, and an in-depth exam of all connectors.
2  Virus & Malware Removal $70 Includes a full removal of any viruses or malware detected and a 30 day guarantee on the removal.
3  Windows Re-install $130 A complete install of a genuine Microsoft Windows Operation System.
4  On-site Visit $75 Onsite computer service & repairs.
5  Remote Access Repair $45 This only includes minor repairs, which will be determined by the technician.
6  Modem/Router Setup and Repair $40 Make sure everthing is working correctly.
7  Windows & Basic Network Training $35 Hands on training with Windows, Mac, and residential Modem/Routers.
What service would you like? 1
130
Let me give you an estimate of the service! Service Cost: $30
Tax: $2.40
Total Cost: $32.40
Would you like to make an appointment? Y for yes and N for no y
What is your name? 
Then is will start storing your information.
