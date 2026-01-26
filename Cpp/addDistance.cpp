#include<iostream>
using namespace std;
class Distance
{
    int m,c;
    public : 
    void getDistance(){
        cout<<"Meter value : ";
        cin>>m;
        cout<<"Centimeter value : ";
        cin>>c;
    } 
    Distance addDistance(Distance &d1,Distance &d2){
        Distance result;
        result.m = d1.m + d2.m ;
        result.c = d1.c + d2.c ;
        if(result.c >=100)
        {
            result.m += result.c/100 ;
            result.c = result.c%100 ;
        }
        return result ;
    }
    void Display()
    {
        cout<<m<<" meters "<<c<<" centimeters ";
    }

};

int main()
{
    Distance d1,d2,result ;
    cout<<"Enter the 1st distance : ";
    d1.getDistance();
    cout<<"Enter the 2nd distance : ";
    d2.getDistance();
    result = result.addDistance(d1,d2);
    cout<<"Thus sum of distances is : "<<endl;
    result.Display();

}