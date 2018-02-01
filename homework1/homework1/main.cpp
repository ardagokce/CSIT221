#include <iostream>
#include <fstream>

using namespace std;

void letter_grade(string names[][2], int exams[][4], int quiz[][5], int homeworks[][5]);

int main() {
    
    
    ifstream ReadFrom("grades.txt");
    string names[2][2];
    int exams[4][4];
    int quiz[5][5];
    int homeworks[5][5];
    
    
    
    int n = 2;
    for (int i = 0; i < n; i++)
    {
        for(int i1=0;i1<2;i1++)
            ReadFrom >> names[i][i1];
        for (int i2 = 0; i2 < 4; i2++)
            ReadFrom >> exams[i][i2];
        for (int i3 = 0; i3 < 5; i3++)
            ReadFrom >> quiz[i][i3];
        for (int i4 = 0; i4 < 5; i4++)
            ReadFrom >> homeworks[i][i4];
    }
    
   letter_grade(names, exams, quiz, homeworks);
    
    
    return 0;
}
void letter_grade(string names[][2], int exams[][4], int quiz[][5], int homeworks[][5]){
    
    float we=0;
    float we2=0;
    float wq=0;
    float wq2=0;
    float wa=0;
    float wa2=0;
    float sum=0;
    float sum2=0;
    string lettergrade;
    string lettergrade2;
    
    for(int i=0  ; i<4 ; i++){
        we += exams[0][i] * 0.10;
        if((i = 3))
        we += exams[0][i] * 0.25;
            }
    for(int i=0  ; i<4 ; i++){
        we2 += exams[1][i] * 0.10;
        if((i = 3))
        we2 += exams[1][i] * 0.25;
    }
    for(int i=0  ; i<5 ; i++)
        wq += quiz[0][i] * 0.03;
    for(int i=0  ; i<5 ; i++)
        wq2 += quiz[1][i] * 0.03;
    for(int i=0  ; i<5 ; i++)
        wa += homeworks[0][i] * 0.06;
    for(int i=0  ; i<5 ; i++)
        wa2 += homeworks[1][i] * 0.06;
    
    sum = we+wq+wa;
    sum2 = we2+wq2+wa2;
    
    if(sum>=90)
        lettergrade = "A";
    else if (sum>=80)
        lettergrade = "B";
    else if(sum>=70)
        lettergrade = "C";
    else if(sum>=60)
        lettergrade = "D";
    else
        lettergrade = "F";
    
    
    if(sum2>=90)
        lettergrade2 = "A";
    else if (sum2>=80)
        lettergrade2 = "B";
    else if(sum2>=70)
        lettergrade2 = "C";
    else if(sum2>=60)
        lettergrade2 = "D";
    else
        lettergrade2 = "F";
    
    
    ofstream SaveTo("gradeoutput.txt");
    
    SaveTo << " Name " << " Last " <<  " WE " << " WQ " << " WA " << " Sum " << " Letter Grade " << endl;
    SaveTo << "______" << "______" <<  "____" << "____" << "____" << "_____" << "______________" << endl;
    
    SaveTo <<  names[0][0] << " " <<  names[0][1] << " " <<  we << " " <<  wq << " " <<  wa << " " <<  sum << " " <<  lettergrade  << endl;
    SaveTo <<  names[1][0] << " " <<  names[1][1] << " " <<  we2<< " " <<  wq2<< " " <<  wa2<< " " <<  sum2<< " " <<  lettergrade2  << endl;
    
    SaveTo.close();
}
