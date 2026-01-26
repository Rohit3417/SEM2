#include<iostream>
#include<cmath>
using namespace std;
class AreaCalculator
{
    public:
    float Areaofrectangle(int length,int width)
    {
        return length*width ;
    }
    float AreaOfCircle(int radius)
    {
        return 4*M_PI*radius*radius ;
    }
};
int main()
{
    int length = 2 ;
    int width = 4;
    int radius = 2 ;
    AreaCalculator G1;
    cout<< "Area of rectangle is : "<<G1.Areaofrectangle(length,width)<<endl;
    cout <<"Area of circle is : "<<G1.AreaOfCircle(radius);

}