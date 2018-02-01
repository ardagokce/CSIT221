//
//  main.cpp
//  classwork3
//
//  Created by ARDA on 11/9/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
using namespace std;

void p(int x){
    if(x % 10 <= 2)
        return;
    cout << x << endl;
    x /= 10;
    p(x/10);
    cout << x << endl;
}


int main(){
    int n;
    while(cin >> n, n >= 0)
        p(n);
    
    return 0;
}
