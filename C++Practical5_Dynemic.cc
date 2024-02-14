#include<iostream>
#include<iomanip>
using namespace std;
int s=0;

   class Area 
{
  private:  float radius;
  const float Pie=3.14;
   public: Area():radius(1.0f)
    {
        cout<<"Circle with radius"<<radius<<"has area:"<<Pie*radius*radius<<endl;
        s++;
    }
    Area(float r):radius(r)
    {
        cout<<"Circle with radius"<<radius<<"has area:"<<Pie*radius*radius<<endl;
        s++;
    }
    Area(Area &n):radius(n.radius)
     {
        cout<<"Circle with radius"<<radius<<"has area:"<<Pie*radius*radius<<endl;
        s++;
     }
     ~Area()
     {
        s--;
        cout<<"One object is deleted."<<endl;
        cout<<"Total active object:"<<s<<endl;

     }
};
int main()
{
    float r;
    class Area *a;
    a=new Area();
    class Area *b;
    b= new Area(10);
    class Area *s;
    s=new Area(*a);
    delete a;
    delete b;
    delete s;
}
