#include<iostream>
#include<iomanip>
using namespace std;
class Literature{
    protected:
    string title;
    int id;
    public:
    void set_basicdetails()
    {
        cout<<"ID: ";
        cin>>id;
        cout<<"Title: ";
        fflush(stdin);
        getline(cin,title);
        
    }
    void get_basicdetails()
    {
        cout<<id<<setw(12)
            <<title;
    }
};
class E_literature : virtual public Literature{
    protected:
    string doi;
    public:
    void set_doi()
    {
        cout<<"DOI: ";
        fflush(stdin);
        getline(cin,doi);
    }
    void get_doi()
    {
        cout<<doi;
    }
};
class HB_literature : virtual public Literature{
    protected:
     unsigned int copies;
    public:
    void set_copies(){
        cout<<"In Stock copies: ";
        cin>>copies;
    }
    void get_copies(){
        cout<<copies;
    }
};
class Book : public E_literature, public HB_literature{
    private:
    int isbn;
    char a;
    public:
    void set_bookdetails()
    {   
        set_basicdetails();
        cout<<"ISBN: ";
        cin>>isbn;
        cout<<"(E)copy or (H)ardbound: ";
        cin>>a;
        if(a=='E')
        {
            set_doi();
        }
        else{
            set_copies();
        }
    }
    void get_bookdetails()
    {
        get_basicdetails();
        cout<<setw(50)
            <<isbn<<setw(12);
        if(a=='E')
        {
            get_doi();
        }
        else{
            get_copies();
        }

    }
};
class Magazine : public E_literature, public HB_literature{
    private:
    int issn;
    char a;
    public:
    void set_magazinedetails()
    {   
        set_basicdetails();
        cout<<"ISSN: ";
        cin>>issn;
        cout<<"(E)copy or (H)ardbound: ";
        cin>>a;
        if(a=='E')
        {
            set_doi();
        }
        else{
            set_copies();
        }
    }
    void get_magazinedetails()
    {
        get_basicdetails();
        cout<<setw(50)
            <<issn<<setw(12);
        if(a=='E')
        {
            get_doi();
        }
        else{
            get_copies();
        }

    }
};
int main()
{
    int choice;
    char menu;
    Book* bookptr[100];
    Magazine* magazineptr[100];
    int num_of_book=0,num_of_magazine=0; 
    do{
        cout<<"Enter 1: To add book details."<<endl;
        cout<<"Enter 1: To add book magazine details."<<endl;
        cout<<"Enter 1: List all book."<<endl;
        cout<<"Enter 1: List all magazine."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: bookptr[num_of_book]=new Book();
                    bookptr[num_of_book]->set_bookdetails();
                    num_of_book++;
                    break;
            case 2: magazineptr[num_of_magazine]= new Magazine();
                    magazineptr[num_of_magazine]->set_magazinedetails();
                    num_of_magazine++;
                    break;
            case 3: 
            cout<<"***** List of all books *****"<<endl;
            for(int i=0;i<num_of_book;i++)
            {
            bookptr[i]->get_bookdetails();
            cout<<endl;
            }
                    break;
            case 4: for(int i=0;i<num_of_magazine;i++)
            {
            magazineptr[i]->get_magazinedetails();
            cout<<endl;
            }
                    break;        
        }
        cout<<"Enter M to goto main menu. Press any key to exit.";
        cin>>menu;
    }while(menu=='M');
    for(int i=0;i<num_of_book;i++)
    {
        delete bookptr[i];
    }
    for(int i=0;i<num_of_magazine;i++)
    {
        delete magazineptr[i];
    }
    return 0;
}