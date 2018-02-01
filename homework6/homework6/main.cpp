//
//  main.cpp
//  homework6
//
//  Created by ARDA on 11/3/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class queue{
    
private:
    stack <int> s1,s2;
public:
    void enqueue(int element);
    int dequeue();
    void displayQueue();
    
};

void queue::enqueue(int element){
    s1.push(element);
}
int queue::dequeue(){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int store = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return store;
}

void queue::displayQueue(){
    
    cout << "Displaying queue.." << endl;
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        cout << s2.top() << endl;
        s1.push(s2.top());
        s2.pop();
    }
}

char menu(){
    char choice;
    
    cout << "1) Give an int." << endl;
    cout << "2) EXIT." << endl;
    
    cin >> choice;
    return choice;
}

int main() {
    
    queue q;
    int n;
    
    cout << "Please enter a number :" << endl;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
       q.enqueue(rand()%100);
    }
    q.displayQueue();
    int dq_element = q.dequeue();
    cout << "After dequeuing : " << endl;
    q.displayQueue();
    
    cout << endl;
    
    
    return 0;
}
