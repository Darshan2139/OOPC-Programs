#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
enum grade{AA=10,AB=9,BB=8,BC=7,CC=6,CD=5,DD=4,FF=0};
class Result;
class Student
{
private:
  string StuId, StuName;
  int Semester;

public:
   void getdatastu()
  {
    cout << "Enter Student ID : ";
    cin >> StuId;
    cout << "Enter Student Name : ";
    cin >> StuName;
    cout << "Semester:";
    cin >> Semester;
  }
   void putdatastu()
  {
    cout << "" << endl;
    cout << "Student ID   : " << StuId << endl;
    cout << "Student Name : " << StuName << endl;
    cout << "Semester     : " << Semester << endl;
  }
    void getsturesult(Result &n);
    void putsturesult(Result &n);

};
class Result
{
  string SubName[3],ThGrade[3],PrGrade[3];
  int ThMark[3],PrMark[3],SubCredit[3],ThGradept[3],PrGradept[3];
  float Sgpa;
  public:
  friend void Student::getsturesult(Result &n);
  friend void Student::putsturesult(Result &n);
  Result()
  {
    Sgpa=0;
  }
};
  void Student::getsturesult(Result &n)
  {
      for (int i = 0; i <3; i++)
  {
    cout << "Name of Subject : ";
    fflush(stdin);
    getline(cin, n.SubName[i]);
    cout<<"Enter the credit of the given subject:";
    cin>>n.SubCredit[i];
    cout << "Theory Marks of " << n.SubName[i] << " : ";
    cin >> n.ThMark[i];
    if (n.ThMark[i] >= 80)
    {
      n.ThGrade[i] = "AA";
     n.ThGradept[i] = AA;
    }
    else if (n.ThMark[i] < 80 && 73 <= n.ThMark[i])
    {
      n.ThGrade[i] = "AB";
     n.ThGradept[i] = AB;
    }
    else if (n.ThMark[i] < 73 && 66 <= n.ThMark[i])
    {
      n.ThGrade[i] = "BB";
     n.ThGradept[i] = BB;
    }
    else if (n.ThMark[i] < 66 && 60 <= n.ThMark[i])
    {
      n.ThGrade[i] = "BC";
     n.ThGradept[i] = BC;
    }
    else if (n.ThMark[i] < 60 && 55 <= n.ThMark[i])
    {
      n.ThGrade[i] = "CC";
     n.ThGradept[i] = CC;
    }
    else if (n.ThMark[i] < 55 && 50 <= n.ThMark[i])
    {
      n.ThGrade[i] = "CD";
     n.ThGradept[i] = CD;
    }
    else if (n.ThMark[i] < 50 && 45 <= n.ThMark[i])
    {
      n.ThGrade[i] = "DD";
     n.ThGradept[i] = DD;
    }
    else if (n.ThMark[i] < 45)
    {
      n.ThGrade[i] = "FF";
     n.ThGradept[i] = FF;
    }

    cout << "PrMark Marks of " << n.SubName[i] << " : ";
    cin >> n.PrMark[i];
    if (n.PrMark[i] >= 80)
    {
      n.PrGrade[i] = "AA";
     n.PrGradept[i] = AA;
    }
    else if (n.PrMark[i] < 80 && 73 <= n.PrMark[i])
    {
      n.PrGrade[i] = "AB";
     n.PrGradept[i] = AB;
    }
    else if (n.PrMark[i] < 73 && 66 <= n.PrMark[i])
    {
      n.PrGrade[i] = "BB";
     n.PrGradept[i] = BB;
    }
    else if (n.PrMark[i] < 66 && 60 <= n.PrMark[i])
    {
      n.PrGrade[i] = "BC";
     n.PrGradept[i] = BC;
    }
    else if (n.PrMark[i] < 60 && 55 <= n.PrMark[i])
    {
      n.PrGrade[i] = "CC";
     n.PrGradept[i] = CC;
    }
    else if (n.PrMark[i] < 55 && 50 <= n.PrMark[i])
    {
      n.PrGrade[i] = "CD";
     n.PrGradept[i] = CD;
    }
    else if (n.PrMark[i] < 50 && 45 <= n.PrMark[i])
    {
      n.PrGrade[i] = "DD";
     n.PrGradept[i] = DD;
    }
    else if (n.PrMark[i] < 45)
    {
      n.PrGrade[i] = "FF";
     n.PrGradept[i] = FF;
    }

    n.Sgpa+=(n.SubCredit[i]*(n.ThGradept[i]+n.PrGradept[i]))/(n.SubCredit[i]*2);
  }
  }
  void Student::putsturesult(Result &n)
  {
  cout << setw(40) << "n.ThMark" << setw(15) << "PrMark" << endl;
  for (int i = 0; i <3; i++)
  {
    cout << n.SubName[i] << setw(40 - n.SubName[i].length()) << n.ThGrade[i] << setw(12) << n.PrGrade[i] << endl;
  }
  cout << "SGPA : " << setprecision(2) << n.Sgpa/3.0 << endl;
  }


int main()
{
  Student S;
  Result SR;
  S.getdatastu();
  S.getsturesult(SR);
  S.putdatastu();
  S.putsturesult(SR);
}