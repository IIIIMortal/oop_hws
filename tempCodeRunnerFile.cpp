#include<iostream>
using namespace std;

int main()
{
    string str;
    int f = -1, n = -1;//f is the type of the former font,
                       //while c is the type of the current font.
    // flag 1:number;
    // flag 0:operator;
    // flag 2:minus token;
    string nstr = "";
    char cur;
    getline(cin,str);
    while(str.size())
    {
        cur = str[0];
        if(cur>= '0' && cur <= '9')
        {
            n = 1; 
            if(f == 0)
            {
                cout << nstr << endl;
                nstr = "";
                nstr.append(&cur);
            }
            else{
                nstr.append(&cur);
            }
        }
        else if(cur == '-')
        {
            if(f == 1)
            {
                n = 0;
                cout << nstr << endl;
                nstr = "";
                nstr.append(&cur);
            }
            else if(f == 0 || f == -1)
            {
                n = 1;
                cout << nstr << endl;
                nstr = "";
                nstr.append(&cur);
            }
        }
        else
        {
            n = 0;
            cout << nstr << endl;
            nstr = "";
            nstr.append(&cur);   
        }
        str.erase(str.begin());
        f = n;
    }
    cout << nstr;
    return 0;
}