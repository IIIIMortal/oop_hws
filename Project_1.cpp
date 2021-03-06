#include"Project_1.h"

using namespace std;

STU::STU()
{
    //不含形参的初始化函数
    stumark = "";
    name = "";
    les_count = 0;
    mark_sum = 0;
}
STU::STU(string mark):stumark(mark)
{
    //根据学号构建的学生类别
    name = "";
    les_count = 0;
    mark_sum = 0;
}
void STU::rename(string nam)
{
    //根据学号建构的是不包括名字的，通过这个函数给对应学号的同学命名
    name = nam;
}
void STU::Ins_score(string lesson, double score)
{
    //记录成绩用
    mark_sum+=score;
    les_count++;
    S_score[lesson] = score;
}
double STU::Cal_avg_score()
{
    //用于计算平均成绩
    return mark_sum/les_count;
}
void STU::output_stu_file(map<string,CLA> a)
{
    //这个函数的意义在于根据传入的地图决定的学科顺序依次输出学生的成绩
    cout << this->name << ", ";
    for(map<string,CLA>::iterator i = a.begin();i!=a.end();i++)
    {
        if(S_score.find(i->first)!=S_score.end()) 
        {
            cout<<setprecision(1);
            double a = this->S_score[i->first];
            cout <<setiosflags(ios::fixed)<<setprecision(1)<< a;
        }
        cout << ", ";
    }
    double avg = this->Cal_avg_score();
    cout << avg;
    cout << endl;
}

double CLA::lesson_choose = 0;
double CLA::lesson_score = 0;
//没有形参传入时的构造函数
CLA::CLA():choose_num(0),all_score(0){}
//根据传入的字符串作为课程信息的构造函数
CLA::CLA(string s):choose_num(0),all_score(0),name(s){}
//计算课程平均分
double CLA::cal_avg() 
{
    return all_score/choose_num;
}
//该课程有新的成绩需要录入
void CLA::Ins_new(double score)
{
    choose_num++;
    all_score+=score;
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
        //获得数据之后不断将得到的字符串分割
        while(getline(trans,tmp,','))
        {
            trim(tmp);
            fragments.push_back(tmp);
        }
        //如果这一行数据的学号没有出现过，就新建一个学生class，等着后续补全信息
        if(all_stu.find(fragments[0])==all_stu.end()) all_stu[fragments[0]] = STU(fragments[0]);
        //如果是只有两个字段，就只更新这个学号所表示的类的名字
        if(fragments.size() <3)
        {
            all_stu[fragments[0]].rename(fragments[1]);
        }
        //否则就代表成绩需要更新
        else
        {
            all_stu[fragments[0]].Ins_score(fragments[1],1.0*stod(fragments[2]));
            if(all_course.find(fragments[1])==all_course.end()) all_course[fragments[1]] = CLA(fragments[1]);
            all_course[fragments[1]].Ins_new(stod(fragments[2]));
        }
        //清楚栈内的信息，防止信息重叠
        fragments.clear();
    }

    //接下来就是输出环节
    //输出标题
    cout << "student id, name";
    for(map<string,CLA>::iterator p = all_course.begin();p!=all_course.end();p++)
    {
        cout<<", " << p->first;
    }
    cout << ", average";
    cout << endl;
    //根据顺序逐次输出各个学生
    for(map<string,STU>::iterator p = all_stu.begin();p!=all_stu.end();p++)
    {
        cout<<p->first<<", ";//输出学号
        p->second.output_stu_file(all_course);
    }
    //根据顺序输出各个课程的平均成绩
    cout<<", ";
    for(map<string,CLA>::iterator p = all_course.begin();p!=all_course.end();p++)
    {
        CLA::lesson_choose++;
        CLA::lesson_score+=p->second.cal_avg();
        cout<<", "<<p->second.cal_avg();
    }
    cout<<", " << CLA::lesson_score/CLA::lesson_choose;
    cout <<endl;
}