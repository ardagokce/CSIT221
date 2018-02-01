#include <iostream>
using namespace std;

int ArrayIsByReference(int []) ;  //Prototype
int main()  {
    int A[4] ;
    A[1] = 2; A[2] = 3; A[3] = 4;
    
    ArrayIsByReference(A) ;
    cout << "The value of A[0] is : " << A[0] << endl ;
    cout << "The Value of *A (=A[0]) is : " << *A << endl ;
    return 0;
}

int ArrayIsByReference (int *Ptr){
    
    *Ptr = *(Ptr+1) *    *(Ptr+2) *   *(Ptr+3) ;
    return 0;
}

