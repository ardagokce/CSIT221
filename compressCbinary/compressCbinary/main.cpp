#include <iostream>
#include <iterator>
#include <bitset>
#include<fstream>
#include <algorithm>
using namespace std;
void ConvertFileIN();
int main() {
    
    
    ConvertFileIN();
    
    system("Pause");
}
void ConvertFileIN()
{
    ifstream mytext;
    
    mytext.open("fuck.png");                                        //convert in  -------------------
    if (!mytext.is_open())
    {
        cout << "open error" << endl;
    }
    
    ofstream Getbitset;
    
    Getbitset.open("bitset.txt");
    
    istreambuf_iterator < char > in(mytext), eof;
    ostream_iterator < bitset< 64 > > out(Getbitset);
    copy(in, eof, out);
    
    mytext.close();
    Getbitset.close();
}

