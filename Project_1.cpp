#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;


class STU
{
public:
    STU()
    {
        stumark = "";
        name = "";
        les_count = 0;
        mark_sum = 0;
    }
    void rename(string nam){name = nam;}
    void Ins_score(string lesson, double score)
    {
        mark_sum+=score;
        les_count++;
        S_score[lesson] = score;
    }
    
    double Cal_avg_score(){return mark_sum/les_count;}
    void output_stu_file(map<string,CLA> a);
private:
    string stumark;
    string name;
    double mark_sum;
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

void STU::output_stu_file(map<string,CLA> a)
{
    cout << this->name << ", ";
    for(map<string,CLA>::iterator i = a.begin();i!=a.end();i++)
    {
        if(S_score.find(i->first)!=S_score.end()) cout << this->S_score[i->first];
        cout <<", ";
    }
    double avg = this->Cal_avg_score();
    cout<<avg<<setprecision(1)<<endl;

}


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
int main(
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
    for(map<string,STU>::iterator p = all_stu.begin();p!=all_stu.end();p++)
    {
        cout<<p->first<<", ";//输出学号
        p->second.output_stu_file(all_course);
    }
}

