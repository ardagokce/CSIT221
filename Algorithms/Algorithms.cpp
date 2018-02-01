//
//  Algorithms.cpp
//  Algorithms
//
//  Created by ARDA on 11/30/17.
//  Copyright © 2017 ARDA. All rights reserved.
//

#include <iostream>
using namespace std;

//Time Complexity:
//O(n^2) for all cases
void selectionSort(int arr[], int length)
{
    int index; //Current smallest value.
    int temp;
    int i; //To keep the index if smaller value be found
    int j; //Traverses through the array to find smaller value
    for(i=0; i<length-1 ; i++)
    {
        index = i; //Sets index as the current index of the array.
        for(j = i+1 ; j<length ; j++)
        {
            if(arr[j] < arr[index]) //If j find a smaller number than current smaller(index)
            {
                index  = j;
            }
        }
        if(index != i)//If the smallest number is not same as previous index
        {
            //Swap the numbers
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] =temp;
        }
    }
    //Prints the sort
    for(i=0; i<length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertionSort(int arr[], int length)
{
    int temp; //Temporary variable
    int i; //i is the first order
    int j;
    for(i=1; i<length ; i++)
    {
        j = i;//Sets the j to whatever the current value of i
        while(j>0 && arr[j] < arr[j-1]) //For decreasing :  while(j > 0 && arr[j] > arr[j-1]) {
        {
            //Basically takes the smaller value to left and larger to the right
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    //Prints the sort
    for(i=0; i<length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Time Complexity:
//Best: O(n), Average and Worst: O(n^2)
void bubbleSort(int arr[], int length)
{
    bool notSorted = true;
    int temp;
    int j=0;
    int i;
    while(notSorted)
    {
        notSorted = false;
        for(i=0; i<length-j; i++)//Make loop till to reach lenght-1
        {
            if(arr[i]> arr[i+1])//Swap two
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                notSorted = true;
            }
        }
    }
    for(i=0; i<length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arraySize;
    int sortingType;
    int i;
    cout<<"Please enter the size of array: ";
    cin>>arraySize;
    cout<<endl;
    cout<<"Please enter the elements of the array: ";
    cout<<endl;
    int arr[arraySize];
    for(i = 0; i<arraySize ; i++)
    {
        cin>>arr[i];
    }
    cout<<"Please choose the sorting type: "<<endl;
    cout<<"1 for Selection Sort"<<endl;
    cout<<"2 for Insertion Sort"<<endl;
    cout<<"3 for Bubble Sort"<<endl;
    cin>>sortingType;
    if(sortingType == 1)
    {
        cout<<"Array after selection sort: "<<endl;
        selectionSort(arr, arraySize);
        
    }
    else if(sortingType == 2)
    {
        
        cout<<"Array after insertion sort: "<<endl;
        insertionSort(arr, arraySize);
    }
    else if(sortingType == 3)
    {
        cout<<"Array after bubble sort: "<<endl;
        bubbleSort(arr, arraySize);
        
    }
    else
    {
        cout<<"Wrong choice!"<<endl;
        
    }
    
    
    
}
void print(){
    
    int arr[] = {};
    int arraySize;
    int sortingType;
    int i;
    
    cout<<"Please enter the size of array: ";
    cin>>arraySize;
    cout<<endl;
    cout<<"Please enter the elements of the array: ";
    cout<<endl;
    for(i = 0; i<arraySize ; i++){
        cin>>arr[i];
    }
    
    cout<<"Please choose the sorting type: "<<endl;
    cout<<"1 for Selection Sort"<<endl;
    cout<<"2 for Insertion Sort"<<endl;
    cout<<"3 for Bubble Sort"<<endl;
    cin>>sortingType;
 
 
    if(sortingType == 1){
        printSelection();
    }
    else if(sortingType == 2){
        printInsertion();
    }
    else if(sortingType == 3){
        printBubble();
    }
    else{
        cout<<"Wrong choice!"<<endl;
    }
}
 

