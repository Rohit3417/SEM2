#include<iostream>
using namespace std;
class P
{public:
    void display()
    {
        cout<<"P class "<<endl;
    }

};
class Q : public P
{public:
    void display()
    {
        cout<<"Q class "<<endl;
    }
};
int main()
{
    P p1;
    p1.display();
    Q q1;
    q1.display();

}