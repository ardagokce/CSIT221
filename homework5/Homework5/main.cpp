//
//  main.cpp
//  Homework5
//
//  Created by ARDA on 11/2/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct node{
    string mail;
    node *next;
};

bool isEmpty(node *head){
    if(head == NULL)
        return true;
    else
        return false;
}

void insertAsFirstElement(node *&head, node *&last, string mail){
    node *temp = new node;
    temp -> mail = mail;
    temp -> next = NULL;
    head = temp;
    last = temp;
}
void insert(node *&head, node *&last, string mail){
    if(isEmpty(head))
        insertAsFirstElement(head, last, mail);
    else{
        node *temp = new node;
        temp -> mail = mail;
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }
}
void remove(node *&head, node *&last){
    if(isEmpty(head))
        cout << "The list is already empty" << endl;
    else if(head == last){
        delete head;
        head = NULL;
        last = NULL;
    }
    else{
        node *temp = head;
        head = head -> next;
        delete temp;
    }
}
void showList(node *current){
    if(isEmpty(current))
        cout << "The list is empty." << endl;
    else{
        cout << "The list contains: " << endl;
        while(current != NULL){
            cout << current->mail << endl;
            current = current->next;
        }
    }
}

char menu(){
    char choice;
    
    cout << "Menu" << endl;
    cout << "1) Read a file." << endl;
    cout << "2) Remove an item." << endl;
    cout << "3) Show in the list." << endl;
    cout << "4) EXIT" << endl;
    
    cin >> choice;
    return choice;
}


int main() {
    node *head = NULL;
    node *last = NULL;
    
    char choice;
    char filename[50];
    ifstream dosya;
    string mail;
    
        
    
    do{
        choice = menu();
        switch(choice){
            case '1':
                cout << "Type the name of the file to open it : " << endl;
                cin >> filename;
                dosya.open(filename);
                if(!dosya.is_open()){
                    exit(EXIT_FAILURE);
                }
                while(dosya.good()){
                    dosya >> mail;
                    insert(head, last, mail);
                }
                break;
            case '2':
                remove(head,last);
                break;
            case '3':
                showList(head);
                break;
            default :
                cout << "System Exit." << endl;
                exit(EXIT_FAILURE);
                
        }
    }while(choice != 4);
    
    return 0;
}
