#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    int f = -1, n = -1;//f is the type of the former font,
                       //while c is the type of the current font.
    // flag 1:number;
    // flag 0:operator;
    // flag 2:minus token;
    char nstr;
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
                cout << endl;
                cout << cur;
            }
            else{
                cout << cur;
            }
        }
        else if(cur == '-')
        {
            if(f == 1)
            {
                n = 0;
                cout << endl;
                cout << cur;
            }
            else if(f == 0 || f == -1)
            {
                n = 1;
                cout << endl;
                cout << cur;
            }
        }
        else
        {
            n = 0;
            cout << endl;
            cout << cur;   
        }
        str.erase(str.begin());
        f = n;
    }
    //cout << cur;
    return 0;
}