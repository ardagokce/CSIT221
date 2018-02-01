#include <iostream>
#include <string> // For strcmp
#include <stdlib.h> // For atoi
using namespace std;

int main(void){
    char Input[20];
    int Total = 0, Count = 0;
    float Average;
    cout << "This program will average a series of numbers.\n";
    cout << "Enter the first number or Q to quit: ";
    cin.getline(Input, 20);
    while ((strcmp(Input, "Q") != 0)&&(strcmp(Input, "q") != 0)){
        Total += atoi(Input);  // Keep a running total
        Count++;  // Keep track of how many numbers entered
        cout << "Enter the next number or Q to quit: ";
        cin.getline(Input, 20);
    }
    if (Count != 0)
    {
        Average = Total / Count;
        cout << "Average: " << Average << endl;
    }
}	
