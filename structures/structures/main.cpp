// This program shows a structure with two nested structure members.
#include <iostream>
using namespace std;

struct Date
{
    int Month;
    int Day;
    int Year;
};
struct Place
{
    char Address[50];
    char City[20];
    char State[15];
    char Zip[11];
};
struct EmpInfo
{
    char Name[50];
    int EmpNumber;
    Date BirthDate;
    Place Residence;
};

int main(void)
{
    EmpInfo Manager;
    // Ask for the manager's name and employee number
    cout << "Enter the manager's name: ";
    cin.getline(Manager.Name, 50);
    cout << "Enter the manager's employee number: ";
    cin >> Manager.EmpNumber;
    // Get the manager's birth date
    cout << "Now enter the manager's date-of-birth.\n";
    cout << "Month (up to 2 digits): ";
    cin >> Manager.BirthDate.Month;
    cout << "Day (up to 2 digits): ";
    cin >> Manager.BirthDate.Day;
    cout << "Year (2 digits): ";
    cin >> Manager.BirthDate.Year;
    cin.get();	// Eat the remaining newline character
    // Get the manager's residence information
    cout << "Enter the manager's street address: ";
    cin.getline(Manager.Residence.Address, 50);
    cout << "City: ";
    cin.getline(Manager.Residence.City, 20);
    cout << "State: ";
    cin.getline(Manager.Residence.State, 15);
    cout << "Zip Code: ";
    cin.getline(Manager.Residence.Zip, 11);
    // Display the information just entered
    cout << "\nHere is the manager's information:\n";
    cout << Manager.Name << endl;
    cout << "Employee number " << Manager.EmpNumber << endl;
    cout << "Date of Birth: ";
    cout << Manager.BirthDate.Month << "-";
    cout << Manager.BirthDate.Day << "-";
    cout << Manager.BirthDate.Year << endl;
    cout << "Place of residence:\n";
    cout << Manager.Residence.Address << endl;
    cout << Manager.Residence.City << ", ";
    cout << Manager.Residence.State << "  ";
    cout << Manager.Residence.Zip << endl;
}	
