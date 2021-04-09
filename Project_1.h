#ifndef __P1head
#define __P1head

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;
class CLA;
class STU;
//学生的class，存储学号，姓名，课程
class STU
{
public:
    STU();
    STU(string mark);
    void rename(string nam);
    void Ins_score(string lesson, double score);
    double Cal_avg_score();
    void output_stu_file(map<string,CLA> a);
private:
    string stumark;
    string name;
    double mark_sum;
    map<string,double> S_score;
    int les_count;
};
//用来记录课程的相关信息
class CLA
{
public:
    //这个只是在之后的计算中有用到，尝试着试用了一下静态成员变量
    static double lesson_score;
    static double lesson_choose;
    CLA();
    CLA(string s);
    double cal_avg();
    void Ins_new(double score);
private:
    string name;
    int choose_num;
    double all_score;
};

#endif