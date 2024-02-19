#include <iostream>
using namespace std;

void area(int r)
 {
 
  cout<<"Area of the circle"<<3.14*r*r<<endl;
}

void area(int h, int w) {

  cout<<"Area of the rectangle"<<h * w<<endl;
}

 void area(int h,int w, int d) 
{
  
  cout<< "Area of the cuboid"<<(h*w+ +w*d+h*d)*2<<endl;
 

}

int main() {
int r;
  int h,w,d;
 cout << "Enter the radius of a circle: ";
  cin >> r;
  area(r);
  
  cout << "Enter the height of a rectangle: ";
  cin >> h;
  cout << "Enter the width of a rectangle: ";
  cin >> w;
  area(h,w);
  cout << "Enter the height of a cuboid: ";
  cin >> h;
  cout << "Enter the width of a cuboid: ";
  cin >> w;
  cout << "Enter the depth of a cuboid: ";
  cin >> d;
  area(h,w,d);
  cout<<"23CE051Darshan Kachhiya";
  
}