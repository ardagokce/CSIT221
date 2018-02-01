//
//  main.cpp
//  classwork1
//
//  Created by ARDA on 11/7/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
using namespace std;



int main() {
    
    int n,next;
    int t1 = 0;
    int t2 = 1;
    
    cout << "Please enter a boundary number : " << endl;
    cin >> n;
    cout << t1 << " " << t2 << " " ;
    for(int i = 0 ; i <= n ; i++){
        
        next = t1 + t2;
        cout << next << " ";
        t1 = t2;
        t2 = next;
        
    }
    return 0;
}
