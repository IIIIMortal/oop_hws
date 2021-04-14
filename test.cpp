#include <iostream>
#include <string>
using namespace std ;
class A{
    int i;
public:
    A(int ii=0):i(ii) { cout << 1; }
    A(const A& a) {
        i = a.i;
        cout << 2;     
    }
    void print() const { cout << 3 << i; }
};

class B : public A {
    int i;
    A a;
public:
    B(int ii = 0) : i(ii) { cout << 4; }
    B(const B& b) {
        i = b.i;
        cout << 5;
    }
    void print() const {
        A::print();
        a.print();
        cout << 6 << i;    
    }
};

int main()
{
    B b(2);
    cout<<endl;        //1
    b.print();
     cout<<endl;    //2
    B c(b); 
     cout<<endl;       //3
    c.print();    //4
}