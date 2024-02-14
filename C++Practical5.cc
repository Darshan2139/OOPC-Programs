#include<iostream>
#include<iomanip>
using namespace std;
int s=0;
class Area
   {

    private:  float radius;
    public: Area()
    {
        radius=1;
        cout<<"Circle with Radius"<<radius<<"has area:"<<3.14*radius*radius<<endl;
        s++;
    }
    Area(float r)
    {
        radius=r;
        cout<<"Circle with radius"<<radius<<"has area:"<<3.14*radius*radius<<endl;
        s++;
    }
    Area(Area &n)
     {
        radius=n.radius;
        cout<<"Circle with radius"<<radius<<"has area:"<<3.14*radius*radius<<endl;
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
    class Area p;
    class Area q(10);
    class Area s(p);
}
