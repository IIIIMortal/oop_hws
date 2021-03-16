#include<iostream>
using namespace std;

int main()
{
    string str1;
    string str2;
    string str,nstr = "";
    int Fl;
    char c;
    int del;
    cin >> Fl;
    cin >> c;
    cin.ignore();
    getline(cin,str);
    del = Fl - str.size();
    if(del>0)
    {
        nstr.append(del,c);
        nstr.append(str);
    }
    else{
        nstr.append(str,-del,str.size());
    }
    cout << nstr << endl;
}