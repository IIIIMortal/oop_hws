#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

// class GPRMC
// {
// private:
//     int hour;
//     int minute;
//     int second;
//     int check;
// public:
//     GPRMC
// };
int checknum(char c)
{
    if(c<='H' && c>='A')
    {
        return c-'A'+10;
    }
    else if (c<='9'&& c>='0')
    {
        return c-'0';
    }
}

int main()
{
    string origin;
    char result[10];
    string str1 = "$GPRMC";
    while(1)
    {
        origin.clear();
        getline(cin,origin);
        if(origin == "END") break;
        //找到地方退出
        size_t found1 = origin.find(str1);
        if(found1 == string::npos) continue;
        //如果这一行不是就退出
        else{
            int check = origin[1];
            int password = 0;
            size_t found2 = origin.find("*");
            for(size_t a = 2;a<found2;a++)
            {
                check = check ^ origin[a];
            }

            check = check % 65536;
            //计算校验码
            for ( int i = 0; i< 2; i++ )
            {
                password = password*16+checknum(origin[found2+1+i]);
            }
            //计算密码
            if(password == check)
            {
                size_t found3 = origin.find_first_of(",");
                int time=0;
                for (int i = 0;i<6;i++)
                {
                    time = time*10+origin[found3+i+1]-'0';
                }
                int hh = time/10000+8;
                if(hh>=24) hh = hh%24;
                time = time % 10000;
                int mm = time/100;
                time = time %100;
                int ss = time ;
                //cout << hh <<":" << mm << ":"<<ss<<endl; 
                sprintf(result,"%02d:%02d:%02d",hh,mm,ss);
            }
        }
    }
    cout << result;
    return 0;
}



