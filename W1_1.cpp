#include<iostream>
using namespace std;

int main()
{
    string s1,s2;
    int l2;
    size_t found;
    getline(cin,s1);
    getline(cin,s2);
    l2 = s2.size();
    found = s1.find(s2);
    while(found !=string::npos)
    {
        s1.erase(found,l2);
        found = s1.find(s2);
    }
    cout << s1;
 
}