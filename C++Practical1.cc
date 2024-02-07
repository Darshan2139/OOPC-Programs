
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

int main(){
    string stdid;
    cout<<"Enter Student ID : ";
    cin>>stdid;
    string stdname;
    cout<<"Enter Student Name : ";
    cin>>stdname;
    int sem;
    cout<<"Semester: ";
    cin>> sem;
    int numsub;
    cout<<"No. of Subject : ";
    cin>>numsub;
    string sub[numsub];
    int theory[numsub];
    int practical[numsub];
    int theorygradepoint[numsub];
    int practicalgradepoint[numsub];
    string gradetheory[numsub];
    string gradepractical[numsub];
    int credit = 3;
    float sgpanum;
    float sgpa;
   
    for(int i=0;i<numsub;i++){
        cout<<"Name of Subject : ";
        fflush(stdin);
        getline(cin,sub[i]);

        cout<<"Theory Marks of "<<sub[i]<<" : ";
        cin>>theory[i];
        if(theory[i]>=80){ gradetheory[i] = "AA"; theorygradepoint[i]=10;}
        else if(theory[i]>=80){ gradetheory[i] = "AA"; theorygradepoint[i]=9;}
        else if(theory[i]<80 && 73<=theory[i]){gradetheory[i] = "BB"; theorygradepoint[i]=8;}
        else if(theory[i]<66 && 60<=theory[i]){ gradetheory[i] = "BC"; theorygradepoint[i]=7;}
        else if(theory[i]<60 && 55<=theory[i]){ gradetheory[i] = "CC"; theorygradepoint[i]=6;}
        else if(theory[i]<55 && 50<=theory[i]){ gradetheory[i] = "CD"; theorygradepoint[i]=5;}
        else if(theory[i]<50 && 45<=theory[i]){ gradetheory[i] = "DD"; theorygradepoint[i]=4;}
        else if(theory[i]<45){ gradetheory[i] = "FF"; theorygradepoint[i]=0;}
      
        sgpanum += credit*theorygradepoint[i];

        cout<<"Practical Marks of "<<sub[i]<<" : ";
        cin>>practical[i];
        if(practical[i]>=80){ gradepractical[i] = "AA"; practicalgradepoint[i]=10;}
        else if(practical[i]>=80){ gradepractical[i] = "AA"; practicalgradepoint[i]=9;}
        else if(practical[i]<80 && 73<=practical[i]){gradepractical[i] = "BB"; practicalgradepoint[i]=8;}
        else if(practical[i]<66  && 60<=practical[i]){ gradepractical[i] = "BC"; practicalgradepoint[i]=7;}
        else if(practical[i]<60 && 55<=practical[i]){ gradepractical[i] = "CC"; practicalgradepoint[i]=6;}
        else if(practical[i]<55 && 50<=practical[i]){ gradepractical[i] = "CD"; practicalgradepoint[i]=5;}
        else if(practical[i]<50 &&45<=practical[i]){ gradepractical[i] = "DD"; practicalgradepoint[i]=4;}
        else if(practical[i]<45){ gradepractical[i] = "FF"; practicalgradepoint[i]=0;}

        sgpanum += credit*practicalgradepoint[i];
    }
        sgpa = sgpanum/(2*credit*numsub) ;
        cout<<""<<endl;
        cout<<"Student ID   : "<<stdid<<endl;
        cout<<"Student Name : "<<stdname<<endl;
        cout<<"Semester     : "<<sem<<endl;
        cout<<setw(50)<<"Theory"<<setw(15)<<"Practical"<<endl;
    for(int i=0;i<numsub;i++){
        cout<<sub[i]<<setw(50-sub[i].length())<<gradetheory[i]<<setw(10)<<gradepractical[i]<<endl;
    }
         cout<<"SGPA : "<<setprecision(2)<<sgpa;
 
}