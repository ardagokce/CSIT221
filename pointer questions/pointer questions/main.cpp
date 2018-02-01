//
//  main.cpp
//  pointer questions
//
//  Created by ARDA on 9/21/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    char algo[] = "Algo mas" ;
    char * p = algo;
    char * q = algo;
    
    cout << "p =" << p << endl;
    cout << "    *p = " << *p << endl;
    cout << "    *(p++) =" << *(p++) << endl;
    cout << "    *(++q) =" << *(q) << endl;
    cout << "    *p++   =" << *p++ << endl;
    cout << "    *p     =" << *p << endl;
    
    p = q;
    
    for(int i = 0 ; i< sizeof(algo); i++){
        cout << *p++ << endl;
    }
    
    p--;
    
    for(int i = 0 ; i< sizeof(algo); i++){
        cout << *(p--) << endl;
    }
    return 0;
}
