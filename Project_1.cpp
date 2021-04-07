#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


class STU
{
public:
    STU()
    {
        stumark = "";
        name = "";
        les_count = 0;
    }
    void rename(string nam){name = nam;}
    void Ins_score(string lesson, double score)
    {
        S_score[lesson] = score;
    }
    
    double Cal_avg_score();
private:
    string stumark;
    string name;
    map<string,double> S_score;
    int les_count;
};
class CLA
{
public:
    CLA():choose_num(0),all_score(0){}
    double cal_avg() {return all_score/choose_num;}
    void Ins_new(double score)
    {
        choose_num++;
        all_score+=score;
    }
private:

    int choose_num;
    double all_score;
};

string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
 
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}
int main()
{
    map<string,STU> all_stu;
    map<string,CLA> all_course;

    vector<string> fragments;
    string input;
    while(getline(cin,input))
    {
        string tmp;
        istringstream trans(input);
        if(input.size()<1) break;
        while(getline(trans,tmp,','))
        {
            trim(tmp);
            fragments.push_back(tmp);
        }
        for(int i = 0;i<fragments.size();i++)
        {
            cout << fragments[i] <<endl;
        }
        if(fragments.size() <3)
        {
            all_stu[fragments[0]].rename(fragments[1]);
        }
        else
        {
            all_stu[fragments[0]].Ins_score(fragments[1],stod(fragments[2]));
            all_course[fragments[1]].Ins_new(stod(fragments[2]));
        }
    }
}

