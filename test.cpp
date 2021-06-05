
#include <iostream>
using namespace std;

class A {
public:
    A(int x = 0, int y = 0) : x(x), y(y) {}
    void show() const;
    A operator+(A& a);
    A operator-(A& a);
private:
    int x, y;
};

void A::show() const {
    cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}

A A::operator+(A& a)
{
    A tmp(this->x+a.x,this->y+a.y);
    return tmp;
}
A A::operator-(A& a)
{
    A tmp(this->x-a.x,this->y-a.y);
    return tmp;
}
int main() {
    A a1(1, 2);
    A a2(4, 5);
    A a;
    cout << "a1:";    a1.show();
    cout << "a2:";    a2.show();
    a = a1 + a2;
    cout << "a:";    a.show();
    a = a1 - a2;
    cout << "a:";    a.show();
    return 0;
}
