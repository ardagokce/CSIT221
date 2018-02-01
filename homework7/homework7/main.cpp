//
//  main.cpp
//  homework7
//
//  Created by ARDA on 12/5/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
#include "algorithms.h"

int main() {
    
    double duration;
    
    int *ar1 = new int[10000]; //Selection
    int *ar2 = new int[10000]; //Insertion
    int *ar3 = new int[10000]; //Bubble
    int *ar4 = new int[10000]; //Original array
    int *ar5 = new int[10000]; //Merge
    int *ar6 = new int[10000]; //Quick
    
    
    for(int i=0;i<9999;i++){
        ar4[i] = rand();
    }
    
    int n = sizeof(ar4)/sizeof(ar4[0]);
    
    
    
    
    //
    
    std::cout << "Sorting with Selection Sort(random)" << std::endl;
    
    duration = clock();
        ar1 = ar4;
        selectionSort(ar1, n);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorting with Selection Sort(sorted)" << std::endl;
    
    duration = 0;
    duration = clock();
        selectionSort(ar1, n);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    //
    //
    
    std::cout << "Sorting with Insertion Sort(random)" << std::endl;
    
    duration = 0;
    duration = clock();
        ar2 = ar4;
        insertionSort(ar2, n);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorting with Insertion Sort(sorted)" << std::endl;
    
    duration = 0;
    duration = clock();
        insertionSort(ar2, n);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    //
    //
    
    std::cout << "Sorting with Bubble Sort(random)" << std::endl;
    
    duration = 0;
    duration = clock();
        ar3 = ar4;
        bubbleSort(ar3, n);
    duration = clock() - duration;
    
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorting with Bubble Sort(sorted) " << std::endl;
    
    duration = 0;
    duration = clock();
        bubbleSort(ar3, n);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    //
    //
    
    std::cout << "Sorting with Merge Sort(random)" << std::endl;
    
    duration = 0;
    duration = clock();
        ar5 = ar4;
        mergeSort(ar5, 0, n-1);
    duration = clock() - duration;
    
    std::cout << "Duration " << duration << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorting with Merge Sort(sorted)" << std::endl;
    
    duration = 0;
    duration = clock();
        mergeSort(ar5, 0, n-1);
    duration = clock() - duration;
    
    std::cout << "Duration " << duration << "ms" << std::endl;
    std::cout << std::endl;
    //
    //
    
    std::cout << "Sorting with Quick Sort(random)" << std::endl;
    
    duration = 0;
    duration = clock();
        ar6 = ar4;
        quickSort(ar6, 0, n-1);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorting with Quick Sort(sorted)" << std::endl;
    
    duration = 0;
    duration = clock();
        quickSort(ar6, 0, n-1);
    duration = clock() - duration;
    
    std::cout << "Duration : " << duration << "ms" << std::endl;
    std::cout << std::endl;
    //
    //
        
        
    return 0;
}
