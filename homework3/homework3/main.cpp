//
//  main.cpp
//  homework3
//
//  Created by ARDA on 9/27/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <istream>

using namespace std;


void saveFile();
void readFile();
void searchRecord();
void deleteFile();

int SIZE;

struct Record{
    char firstName[25], lastName[25], address[50];
    int phoneNumber[50];
};

void saveFile(){
    
    char firstName[25];
    char lastName[25];
    char address[50];
    int phoneNumber[50];
    
    char buffer[256];
    
    ofstream SaveTo("address.txt");
    
    if (SaveTo.fail()){
        cout << "Error opening file.\n" << endl;
        exit(-1);
    }
    else{
        cout << "Opening file... " << endl;
    }
    
    cout << "Please enter first name and last name. " << endl;
    cin.getline(firstName, 25);
    cin.getline(lastName, 25);
    cout << "Please enter adress. " << endl;
    cin.getline(address, 50);
    cout << "Please enter phone number. " << endl;
    fgets(buffer, 256, stdin);
    phoneNumber[49] = atoi(buffer);
    
    SaveTo << firstName[25] << lastName[25] << endl;
    SaveTo << address[50] << endl;
    SaveTo << phoneNumber[50] << endl;
    SaveTo.close();
    
}

void readFile(){
    int i = 0;
    Record records[10];
    char name,lname,address;
    int pnumber;
    
    ifstream inp("address.txt");
    
    if (inp.fail()){
        cout << "Error opening file.\n" << endl;
        exit(-1);
    }
    else{
        cout << "Opening file...\n" << endl;
    }
    
    while(!inp.eof()){
        inp >> name >> lname >> address >> pnumber;
        
        strcpy(records[i].firstName, &name);
        strcpy(records[i].lastName, &lname);
        strcpy(records[i].address, &address);
        records[i].phoneNumber[49] = pnumber;
        
        i++;
        
        SIZE = i;

    }
    inp.close();
    
    
}

void searchRecord(){
    int key;
    
    Record records[10];
    
    cout << "Please enter the last 4 digits of the phone number you want to search. " << endl;
    cin >> key;
    
    for(int i = 0; i < SIZE ; i++){
        
        if(key==records[i].phoneNumber[49]){
            cout << "FOUND " << endl;
            
            cout <<"Name : " << records[i].firstName << records[i].lastName << "\n" << "Address : " << records[i].address <<  "\n" << "Phone number : " << records[i].phoneNumber << endl;
            break;
        }
        else
            cout << "NOT FOUND " << endl;
    }
    
}

void deleteFile(){
    int key;
    
    Record records[10];
    
    cout << "Please enter the phone number of the person you want to delete. " << endl;
    cin >> key;
    for(int i = 0 ; i<SIZE ; i++){
        if (records[i].phoneNumber[49] == key){
        cout << "FOUND AND DELETED: " << records[i].firstName << " " << records[i].lastName << endl;
            delete &records[i];
            exit(-1);
    }
        else{
            cout << "NOT FOUND." << endl;
            cout << "Back to menu." << endl;
        }
    }
}

int main(){
    
    int x=-1;
    
    
    
    do{
    cout << "_WELCOME_" << endl;
    cout << "1) Add a new record. " << endl;
    cout << "2) Delete a record. " << endl;
    cout << "3) Search a record. " << endl;
    cout << "4) Exit." << endl;
    
    cin >> x;
    
        switch (x) {
        case 1:{
            saveFile();
            break;}
        case 2:{
            deleteFile();
            break;}
        case 3:{
            readFile();
            searchRecord();
            break;}
        case 4:{
            exit(-1);}
            
        default:{
            cout << "Invalid selection please try again" << endl;
            break;}
    }
    
    }while(x!=0);
    
    
    return 0;
}
