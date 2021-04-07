#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int group;
    int num;
    string n;
    map<string,int> dic;
    map<string,int>::iterator it;
    cin >> group;
    getchar();
    for(int i = 0;i<group;i++)
    {
        cin >> num;
        getchar();
        for(int j = 0;j<num;j++)
        {
            cin>>n;
            getchar();
            dic[n]++;
        }
    }
    it = dic.begin();
    for(;it!=dic.end();++it)
    {
        if (it == dic.end())
        {
            cout << it->first<<" "<<it->second;
            break;
        }
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}