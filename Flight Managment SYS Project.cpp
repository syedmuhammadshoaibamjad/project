#include <iostream>
#include <windows.h>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;

// Define a structure to store details about a record
struct record_detail
{
	string passenger_name,
		flightName,
		flightNumber, ticket_price,
		seat_no;
};

int count = 0, choice;
char ch = 178, sb = 219;
vector<record_detail> Record; // Define a vector to store records

// Declare functions used in the program
void Manage_Data();
void Search_Data();
void Display_Data();
void Add_Data();
void Update_Data();
void Delete_Data();
void header_s(string x);
void fooder_s(string y);

int main()
{
	// Set the console color to green
	system("color A");

	// Display a loading screen
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                 System Starting Please Wait";
	for (int i = 0; i < 30; i++)
	{
		Sleep(200);
		cout << ".";
	}

	// Clear the console and display the introduction screen
	system("cls");
	string m = " Introduction ";
	header_s(m);
	cout << endl
		 << endl
		 << ch << ch << ch << " Submitted to:   =>   S.Amer Ahmad Gallani\n";
	cout << endl
		 << endl
		 << sb << ch << ch << " created by "
		 << "     <=>    "
		 << " Registration No " << ch << ch << sb;
	cout << "\n_________________________________________________";
	cout << "\n\n"
		 << sb << ch << " Mohsin Haider            => SP22-BCS-136" << endl;
	cout << "\n"
		 << sb << ch << " Muhammad Shoaib          => SP22-BCS-109" << endl;
	cout << "\n"
		 << sb << ch << " Tania  Shoukat           => SP22-BCS-110" << endl;
	cout << "\n"
		 << sb << ch << " Ayesha Mubeen            => SP22-BCS-130\n"
		 << endl;
	string y = " COMSATS University Islamabad Sahiwal ";
	fooder_s(y);

	// Display a loading bar
	cout << endl
		 << endl
		 << endl
		 << "                                              Loading Please wait..............";
	cout << endl
		 << endl
		 << "                  ";
	for (int i = 0; i <= 80; i++)
	{
		Sleep(80);
		cout << char(219);
	}
	cout << endl
		 << endl;
	system("cls");

	// Display the main menu and perform the selected action until the user chooses to exit
	do
	{
		// Display the main menu
		string m = " Main manu ";
		header_s(m);
		cout << endl
			 << endl
			 << sb << ch << " 1. Add & Manage Data.";
		cout << endl
			 << endl
			 << sb << ch << " 2. Search Data.";
		cout << endl
			 << endl
			 << sb << ch << " 3. Display data.";
		cout << endl
			 << endl
			 << sb << ch << " 4. Exit Program.";
		cout << endl
			 << endl
			 << sb << ch << " Enter your choice: ";
		cin >> choice;
		system("cls");

		// Perform the selected action
		switch (choice)
		{
		case 1:
		{
			Manage_Data(); // Call the Manage_Data function
			break;
		}
		case 2:
		{
			Search_Data(); // Call the Search_Data function
			break;
		}
		case 3:
		{
			Display_Data(); // Call the Display_Data function
			break;
		}
		
		case 4:
		{
			string a = " THANKS FOR USING S.M.A.T Airlines SYSTEM ";
			fooder_s(a);
			exit(0); // Exit the program
			break;
		}
		default:
		{
			cout << endl
				 << sb << ch << " You Entered an invalid Number please try Again => " << endl;
		}
		}
	} while (tolower(choice) != 'n');

	return 0;
}

void Search_Data()
{
	// Display the Search Data menu
	string m = " Search manu ";
	header_s(m);
	cout << endl;
	if (Record.empty())
	{
		cout << endl
			 << endl
			 << sb << ch << " No records found in the database. " << endl;
		return;
	}
	cout << endl
		 << endl
		 << sb << ch << " 1. Search by Passenger Name.";
	cout << endl
		 << endl
		 << sb << ch << " 2. Search by Flight Number.";
	cout << endl
		 << endl
		 << sb << ch << " 3. Search by Seat Number.";
	cout << endl
		 << endl;
	cout << sb << ch << " 4. Return to Main Menu.";
	cout << endl
		 << endl
		 << sb << ch << " Enter your choice: ";
	cin >> choice;
	system("cls");

	// Perform the selected action
	switch (choice)
	{
	case 1:
	{
		string m = " Search manu ";
		header_s(m);
		// Search for records by passenger name
		string passengerName;
		cout << endl
			 << endl
			 << sb << ch << " Enter Passenger Name: ";
		cin >> passengerName;
		bool found = false;
		for (int i = 0; i < Record.size(); i++)
		{
			if (Record[i].passenger_name == passengerName)
			{
				found = true;
				cout << endl
					 << endl
					 << sb << ch << " Record Found!" << endl;
				cout << endl
					 << endl
					 << sb << ch << " Passenger Name: " << Record[i].passenger_name << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Name: " << Record[i].flightName << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Number: " << Record[i].flightNumber << endl;
				cout << endl
					 << endl
					 << sb << ch << " Ticket price: " << Record[i].ticket_price << endl;
				cout << endl
					 << endl
					 << sb << ch << " Seat Number: " << Record[i].seat_no << endl;
				cout << endl
					 << endl;
			}
		}
		if (!found)
		{
			cout << endl
				 << sb << ch << " No Record found with the Given Flight number. " << endl;
		}
		break;
	}
	case 2:
	{
		string m = " Search manu ";
		header_s(m);
		// Search for records by flight number
		string flight_Number;
		cout << endl
			 << endl
			 << sb << ch << " Enter Flight Number: ";
		cin >> flight_Number;
		bool found = false;
		for (int i = 0; i < Record.size(); i++)
		{
			if (Record[i].flightNumber == flight_Number)
			{
				found = true;
				cout << endl
					 << endl
					 << sb << ch << " Record Found!" << endl;
				cout << endl
					 << endl
					 << sb << ch << " Passenger Name: " << Record[i].passenger_name << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Name: " << Record[i].flightName << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Number: " << Record[i].flightNumber << endl;
				cout << endl
					 << endl
					 << sb << ch << "  Ticket price: " << Record[i].ticket_price << endl;
				cout << endl
					 << endl
					 << sb << ch << " Seat Number: " << Record[i].seat_no << endl;
				cout << endl
					 << endl;
			}
		}
		if (!found)
		{

			cout << endl
				 << sb << ch << " No Record found with the Given Flight Number. " << endl;
		}
		break;
	}

	case 3:
	{
		string m = " Search manu ";
		header_s(m);
		// Search for records by seat number
		string seatNumber;
		cout << endl
			 << endl
			 << sb << ch << " Enter Seat Number: ";
		cin >> seatNumber;
		bool found = false;
		for (int i = 0; i < Record.size(); i++)
		{
			if (Record[i].seat_no == seatNumber)
			{
				found = true;
				cout << endl
					 << endl
					 << sb << ch << " Record Found!" << endl;
				cout << endl
					 << endl
					 << sb << ch << " Passenger Name: " << Record[i].passenger_name << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Name: " << Record[i].flightName << endl;
				cout << endl
					 << endl
					 << sb << ch << " Flight Number: " << Record[i].flightNumber << endl;
				cout << endl
					 << endl
					 << sb << ch << " Ticket price: " << Record[i].ticket_price << endl;
				cout << endl
					 << endl
					 << sb << ch << " Seat Number: " << Record[i].seat_no << endl;
				cout << endl
					 << endl;
			}
		}
		if (!found)
		{
			cout << endl
				 << sb << ch << " No Record found with the given Seat number. " << endl;
		}
		break;
	}
	case 4:
	{
		// Return to main menu
		return;
	}
	default:
	{
		cout << endl
			 << endl
			 << sb << ch << " Invalid choice. " << endl;
		break;
	}
	}
	string choice;
	cout << endl
		 << endl
		 << sb << ch << " Want to use Main manu (y/n): ";
	cin >> choice;
	if (choice == "y")
	{
		return;
	}
	else
	{

		string a = " Thanks For using our Softwere ";
		fooder_s(a);
		exit(0);
	}
}

void Display_Data()
{
	string d = " Displaying all Records ";
	header_s(d);

	if (Record.empty())
	{
		cout << endl
			 << endl
			 << sb << ch << " No Records Found in the Database. " << endl;
		return;
	}

	for (int i = 0; i < Record.size(); i++)
	{
		cout << endl
			 << endl
			 << sb << sb << sb << ch << ch << ch << " Record " << i + 1 << " " << ch << ch << ch << sb << sb << sb << endl;
		cout << endl
			 << endl
			 << sb << ch << " Passenger name: " << Record[i].passenger_name << endl;
		cout << endl
			 << endl
			 << sb << ch << " Tecket Price: " << Record[i].ticket_price << endl;
		cout << endl
			 << endl
			 << sb << ch << " Seat number: " << Record[i].seat_no << endl;
		cout << endl
			 << endl
			 << sb << ch << " Flight name: " << Record[i].flightName << endl;
		cout << endl
			 << endl
			 << sb << ch << " Flight class: " << Record[i].flightNumber << endl;
	}
	string choice;
	cout << endl
		 << endl
		 << sb << ch << " Want to use Main Manu (y/n): ";
	cin >> choice;
	if (choice == "y")
	{
		return;
	}
	else
	{
		string a = " Thanks For using our S.M.A.T Airlines System ";
		fooder_s(a);
		exit(0);
	}
system("cls");	
}


void Manage_Data()
{
	// Display the Manage Data menu
	string m = " Manage manu ";
	header_s(m);
	cout << endl;
	cout << endl
		 << endl
		 << sb << ch << " 1. Add New Data.";
	cout << endl
		 << endl
		 << sb << ch << " 2. Update Existing Data.";
	cout << endl
		 << endl
		 << sb << ch << " 3. Delete Data.";
	cout << endl
		 << endl;
	cout << sb << ch << " 4. Return to Main Menu.";
	cout << endl
		 << endl
		 << sb << ch << " Enter your choice: ";
	cin >> choice;
	system("cls");

	// Perform the selected action
	switch (choice)
	{
	case 1:
	{
		Add_Data(); // Call the Add_Data function
		break;
	}
	case 2:
	{
		Update_Data(); // Call the Update_Data function
		break;
	}
	case 3:
	{
		Delete_Data(); // Call the Delete_Data function
		break;
	}
	case 4:
	{
		main(); // Return to the main menu
		break;
	}
	default:
	{
		cout << endl
			 << sb << ch << " You Entered an invalid Number please try Again => " << endl;
	}
	}

}


void Add_Data()
{

	char choice = 'y';

	while (choice != 'n')
	{
		string a = " Add manu ";
		header_s(a);

		record_detail record;

		cout << endl
			 << endl
			 << sb << ch << " Enter Passenger Name: ";
		cin >> record.passenger_name;
		cout << endl
			 << endl
			 << sb << ch << " Enter Flight Name: ";
		cin >> record.flightName;
		cout << endl
			 << endl
			 << sb << ch << " Enter Flight Number: ";
		cin >> record.flightNumber;
		cout << endl
			 << endl
			 << sb << ch << " Enter  Ticket price: ";
		cin >> record.ticket_price;
		cout << endl
			 << endl
			 << sb << ch << " Enter Seat Number: ";
		cin >> record.seat_no;

		Record.push_back(record);

		string d = " Record Added successfully! ";
		fooder_s(d);
		cout << endl;
		cout << endl
			 << endl
			 << ch << ch << " Want to Add Another Passenger (y/n): ";
		cin >> choice;
		count++;
		system("cls");
	}
}

// Update an existing record in the records vector
void Update_Data()
{

	char choice = 'y';
	while (tolower(choice != 'n'))
	{
		string u = " Update manu ";
		header_s(u);
		cout << endl;
		if (Record.empty())
	{
		cout << endl
			 << endl
			 << sb << ch << " No records found in the database. " << endl;
		return;
	}
	

		string name;
		cout << endl
			 << endl
			 << sb << ch << " Enter the name of the passenger whose Data you want to Update: ";
		cin >> name;

		cout << endl
			 << ch << ch << " Checking! Please Wait";
		for (int i = 0; i < 15; i++)
		{
			Sleep(150);
			cout << ".";
		}

		bool found = false;

		// Search for the passenger in the database
		for (int i = 0; i < Record.size(); i++)
		{
			if (Record[i].passenger_name == name)
			{
				found = true;

				cout << endl
					 << endl
					 << sb << ch << " Enter New Seat No: ";
				cin >> Record[i].seat_no;

				cout << endl
					 << endl
					 << sb << ch << " Enter New Tecket Price : ";
				cin >> Record[i].ticket_price;

				cout << endl
					 << endl
					 << sb << ch << " Enter New Flight Name: ";
				cin >> Record[i].flightName;

				cout << endl
					 << endl
					 << sb << ch << " Enter New Flight number: ";
				cin >> Record[i].flightNumber;
				cout << endl
					 << endl;

				string u = " Passenger Data Dpdated Successfully! ";
				fooder_s(u);
				break;
			}
		}

		if (!found)
		{
			cout << endl
				 << endl
				 << sb << ch << " No Passenger with name " << name << " was Found in the Database." << endl;
		}
		cout << endl
			 << endl
			 << sb << ch << " Want to use Update Menu Again(y/n): ";
		cin >> choice;
		system("cls");
	}
}

void Delete_Data()
{
    char choice = 'y';
    while (choice != 'n')
    {
        string d = " Delete manu ";
        header_s(d);
        if (Record.empty())
	{
		cout << endl
			 << endl
			 << sb << ch << " No records found in the database. " << endl;
		return;
	}
     else{
	 
            cout << endl << endl << sb << ch << " Enter the Passenger Name of the record you want to delete: ";
            string name;
            cin >> name;
            cout << endl << sb << ch << " Checking! Please Wait";
            for (int i = 0; i < 15; i++)
            {
                Sleep(150);
                cout << ".";
            }

            // Search for the record in the database
            bool found = false;
            for (int i = 0; i < Record.size(); i++)
            {
                if (Record[i].passenger_name == name)
                {
                    // Shift all records after the found record one position back
                    Record.erase(Record.begin() + i);
                    cout << endl << endl;
                    string f = " Record deleted successfully! ";
                    fooder_s(f);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << endl << endl << ch << ch << " No record with passenger name " << name << " was found in the database. " << endl;
            }
            cout << endl << endl << ch << ch << " Want to use Delete Menu Again(y/n): ";
            cin >> choice;
            system("cls");
        }
    }}



void header_s(string x)
{
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		Sleep(20);
		cout << sb;
	}
	for (int i = 0; i < 40; i++)
	{
		Sleep(20);
		cout << ch;
	}
	cout << "  S.M.A.T Airlines  ";
	for (int i = 0; i < 40; i++)
	{
		Sleep(15);
		cout << ch;
	}
	for (int i = 0; i < 10; i++)
	{
		Sleep(15);
		cout << sb;
	}
	cout << endl
		 << endl
		 << endl;
	for (int i = 0; i < 5; i++)
	{
		Sleep(10);
		cout << sb;
	}
	for (int i = 0; i < 5; i++)
	{
		Sleep(10);
		cout << ch;
	}
	cout << x;
	for (int i = 0; i < 5; i++)
	{
		Sleep(10);
		cout << ch;
	}

	for (int i = 0; i < 5; i++)
	{
		Sleep(15);
		cout << sb;
	}
}

void fooder_s(string y)
{
	cout << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		Sleep(20);
		cout << sb;
	}
	for (int i = 0; i < 35; i++)
	{
		Sleep(20);
		cout << ch;
	}
	cout << y;
	for (int i = 0; i < 35; i++)
	{
		Sleep(20);
		cout << ch;
	}

	for (int i = 0; i < 10; i++)
	{
		Sleep(20);
		cout << sb;
	}
	cout << endl
		 << endl;
}
