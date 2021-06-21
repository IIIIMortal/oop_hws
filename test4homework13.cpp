#include <iostream>
#include <iomanip>
using namespace std;

class COMPLEX
{
private:
    double real;
    double imag;
public:
    COMPLEX():real(0),imag(0){}
    COMPLEX(double r):real(r),imag(0){}
    COMPLEX(double r, double i):real(r),imag(i) { }
    friend ostream& operator<<(ostream& os, const COMPLEX& c);
    friend istream& operator>>(istream& is, COMPLEX& c);
    friend const COMPLEX operator+(const COMPLEX& c1, const COMPLEX& c2);
};

ostream& operator<<(ostream& os, const COMPLEX& c)
{
    if(c.imag>=0)
        os<<setiosflags(ios::fixed)<<setprecision(0)<<c.real<<"+"<<c.imag<<"i";
    else
        os<<setiosflags(ios::fixed)<<setprecision(0)<<c.real<<c.imag<<"i";

}

istream& operator>>(istream& is, COMPLEX& c)
{
    char c1,c2;
    double r,i;
    is>>r>>c1>>i>>c2;
    if(c1 == '-')
    {
        c.real = r;
        c.imag = -i;
    }
    else
    {
        c.real = r;
        c.imag = i;
    }
    return is;
}
const COMPLEX operator+(const COMPLEX& c1,const COMPLEX& c2)
{
    COMPLEX temp;
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
    return temp;
}

int main()
{
    // COMPLEX a, b, c;
    // cin >> a >> b;
    // c = a + b;
    // cout << c << endl;
    // return 0;
    COMPLEX a(3);
cout << a << endl; // 输出: 3+0i
}