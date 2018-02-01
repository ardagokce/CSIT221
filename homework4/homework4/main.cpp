#include <iostream>
#include <cassert>
#include <new>

using namespace std;


typedef int ElementType;
class List
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    List(int maxSize = 1024);
    
    /***** Class destructor *****/
    ~List();
    
    /***** Copy constructor *****/
    List(const List & origList);
    
    /***** Assignment operator *****/
    List & operator=(const List & origList);
    
    /***** empty operation *****/
    bool empty() const;
    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    
    void erase(int pos); // Remove value at position pos.
    
    void display(ostream & out) const;
    
     List  operator*(const List &mult);
     List  operator-(const List &sub);
     List  operator+(const List &add);
    
    
private:
    /******** Data Members ********/
    int mySize;        // current size of list stored in array
    int myCapacity;    // capacity of array
    ElementType * myArrayPtr;// pointer to dynamically-
    // allocated array
    
}; //--- end of List class

List List::operator*(const List &mult){
    List *result = new List;
    *result = *this;
    *result *= mult;
    return *result;
}

List List::operator-(const List &sub){
    List *result = new List;
    *result = *this;
    *result -= sub;
    return *result;
}

List List::operator+(const List &add){
    List *result = new List;
    *result = *this;
    *result += add;
    return *result;
}



//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);



//--- Definition of class constructor
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
    myArrayPtr = new(nothrow) ElementType[maxSize];
    assert(myArrayPtr != 0);
}

//--- Definition of class destructor
List::~List()
{
    delete [] myArrayPtr;
}

//--- Definition of the copy constructor
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity)

{
    //--- Get new array for copy
    myArrayPtr = new(nothrow) ElementType[myCapacity];
    
    if (myArrayPtr != 0)                 // check if memory available
        //--- Copy origList's array into this new array
        for(int i = 0; i < myCapacity; i++)
            myArrayPtr[i] = origList.myArrayPtr[i];
    else
    {
        cerr << "*Inadequate memory to allocate stack ***\n";
        exit(1);
    }
}

//--- Definition of the assignment operator
List & List::operator=(const List & origList)
{
    if (this != &origList)    // check for list = list
    {
        mySize = origList.mySize;
        myCapacity = origList.myCapacity;
        
        //-- Allocate a new array if necessary
        if (myCapacity != origList.myCapacity)
        {
            delete[] myArrayPtr;
            myArrayPtr = new(nothrow) ElementType[myCapacity];
            
            if (myArrayPtr == 0)   // check if memory available
            {
                cerr << "*Inadequate memory to allocate stack ***\n";
                exit(1);
            }
        }
        //--- Copy origList's array into this new array
        for(int i = 0; i < myCapacity; i++)
            myArrayPtr[i] = origList.myArrayPtr[i];
    }
    return *this;
}

//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}

//--- Definition of display()
void List::display(ostream & out) const
{
    for (int i = 0; i < mySize; i++)
        out << myArrayPtr[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList)
{
    aList.display(out);
    return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
    if (mySize == myCapacity)
    {
        cerr << "*** No space for list element -- terminating "
        "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "*** Illegal location to insert -- " << pos
        << ".  List unchanged. ***\n";
        return;
    }
    
    // First shift array elements right to make room for item
    
    for(int i = mySize; i > pos; i--)
        myArrayPtr[i] = myArrayPtr[i - 1];
    
    // Now insert item at position pos and increase list size
    myArrayPtr[pos] = item;
    mySize++;
}

//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to delete -- " << pos
        << ".  List unchanged. ***\n";
        return;
    }
    
    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++)
        myArrayPtr[i] = myArrayPtr[i + 1];
    
    // Decrease list size
    mySize--;
}


/***********List Testing program   *********************/
/* listtester.cpp is a program for testing class List. */

// f() is a function with
void f(List aList)                // List value parameter
{                                 // to test the copy constructor
    for (int i = 1; i < 5; i++)
    {
        aList.insert(100*i, i);      // insert into the copy
        cout << aList << endl;       // output the copy
    }
}

int main()
{
    // Test the class constructor
    List intList;
    cout << "Constructing intList\n";
    
    // Test empty() and output of empty list
    if (intList.empty())
        cout << "Empty List: \n"
        << intList << endl;       // Test output of empty list
    
    
    // Test insert()
    for (int i = 0; i < 9; i++)
    {
        intList.insert(i, i/2);       //  -- Insert i at position i/2
        //Test output
        cout << intList << endl;
    }
    cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;
    
    
    // Test destructor
    //  Note, scope rules apply here. After the block, anotherList does not exists.
    {
        List anotherList;
        for (int i = 0; i < 10; i++)
            anotherList.insert(100*i, i);
        cout << "\nHere's another list:\n" << anotherList << endl;
        cout << "Now destroying this list\n";
    }
    
    // Test the copy constructor
    cout << "\n\n";
    f(intList);
    
    cout << "\n\nOriginal list:";      // Output the original to make
    cout << intList<< endl;            //  sure it hasn't been changed
    
    // Test erase
    int index;
    while (!intList.empty())
    {
        cout << "Give an index of list element to remove: ";
        cin >> index;
        intList.erase(index);
        cout << intList << endl;
    }
    cout << "List is empty" << endl;
    
    return 0;
}
