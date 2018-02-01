#include <iostream>
using namespace std;

void findminmax(int N[], int &minimum , int &maximum , int len){
    
    maximum = minimum = N[0];
    
    for (int index = 1; index < len ; index++){
        if (maximum < N[index]) maximum = N[index];
        if (minimum > N[index]) minimum = N[index];
    }
}

int main ()
{
    const int MAX_ARRAY = 10;
    int  numbers[MAX_ARRAY];
    int  index;
    int  sum;
  
    
    // Stored values in the array.
    for (index = 0; index < MAX_ARRAY; index++)
        numbers[index] = rand();
    
    // The values in the array are summed.
    sum = 0;
    for (index = 0; index < MAX_ARRAY; index++)
        sum = sum + numbers[index];
    
    findminmax(numbers, min, max, MAX_ARRAY);

    
    cout  << "Sum is "  << sum  << endl;
    
    //  print out the values of the array
    for (index = 0; index < MAX_ARRAY; index++)
        
        cout << "Array elements are " << numbers[index] << endl;
    
    
    return 0;
}
