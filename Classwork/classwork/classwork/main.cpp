#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

int main(){
    
    node *p, *q, *t, *z;
    
    p = new node;
    p -> data = 10;
    p -> next = NULL;  //0
    
    q = new node;
    q -> data = 20;
    q -> next = NULL;  //0
    
    t = new node;
    t -> data = 30;
    t -> next = NULL;  //0
    
    z = new node;
    z -> data = 40;
    z -> next = NULL;  //0
    
    p -> next = q;  // (1)
    q -> next = t;  // (2) p -> next -> next = T;
    t -> next = z;  // (3) p -> next -> next -> next = Z;
    
    cout << p -> next -> next -> next -> data << endl; // Z -> data
    
    p -> next -> next -> next -> next = new node;
    p -> next -> next -> next -> next -> data = 50;
    p -> next -> next -> next -> next -> next = NULL;
    
    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
    
    system("pause");
}
