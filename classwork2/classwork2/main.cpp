//
//  main.cpp
//  classwork2
//
//  Created by ARDA on 11/9/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
using namespace std;

void p(int x){
    if(x <= 0)
        return;
    cout << x << endl;
    p(x/10);
    p(x/100);
}

int main(){
    
    int n;
    cout << "Enter a positive integer value : " ;
    cin >> n;
    p(n);
    
    
    return 0;
}
