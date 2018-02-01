//
//  main.cpp
//  homework2
//
//  Created by ARDA on 9/14/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    
    
    int verticalSize = 0;
    int horizontalSize = 0;
    int verticalSize2 = 0;
    int horizontalSize2 = 0;
    
    
    cout << "Please enter dimentions of the first matrix. First row , column second." << endl;
    cin >> verticalSize;
    cin >> horizontalSize;
    cout << "Please enter dimentions of the second matrix. " << endl;
    cin >> verticalSize2;
    cin >> horizontalSize2;
    
    if(horizontalSize != verticalSize2){
        cout << "Error cannot multiply. " << endl;
        exit(-1);
    }
    
    int ** p = new int*[verticalSize];
    for(int i = 0; i < verticalSize; ++i) {
        p[i] = new int[horizontalSize];
    }
    
    int ** p2 = new int*[verticalSize2];
    for(int i = 0; i < verticalSize2; i++){
        p2[i] = new int[horizontalSize2];
    }
    
    int ** multi = new int*[verticalSize];
    for(int i = 0; i < verticalSize; i++){
        multi[i] = new int[horizontalSize2];
    }
    
    for(int i = 0; i < verticalSize; ++i) {
        for(int j = 0; j < horizontalSize; ++j) {
            int a = rand()%10;
            p[i][j] = a;
        }
    }
    
    for(int i = 0; i < verticalSize2; ++i) {
        for(int j = 0; j < horizontalSize2; ++j) {
            int b = rand()%10;
            p2[i][j] = b;
        }
    }
    
    for(int i = 0; i < verticalSize; ++i) {
        for(int j = 0; j < horizontalSize; ++j) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < verticalSize2; ++i) {
        for(int j = 0; j < horizontalSize2; ++j) {
            cout << p2[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < verticalSize; ++i)
        for(int j = 0; j < horizontalSize2; ++j)
            for(int k = 0; k < horizontalSize; ++k)
            {
                multi[i][j] += p[i][k] * p2[k][j];
            }
    
    cout << "****" << "****" << "****" << endl;
    cout << "Result of the multiplication : " << " " << endl;
    
    for(int i = 0; i < verticalSize; ++i) {
        for(int j = 0; j < horizontalSize2; ++j) {
            cout << multi[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
