#include<iostream>
using namespace std;

int main()
{
    int map[2][3] = {1 ,1 ,1 ,5 ,5,5};
    for(int i = 0;i<2;i++)
    {
        for (int j = 0;j<3;j++)
        {
            cout<<map[i][j]<<endl;

        }
    }
}