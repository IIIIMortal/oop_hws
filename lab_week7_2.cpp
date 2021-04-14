#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
    Animal():age(0){}
    Animal(int a ):age(a){}
    int getAge(){return age;}
    int age;
};

class Dog:public Animal
{
private:
    string color;
public:
    Dog(int a, string b)
    {
        color = b;
        age = a;
    }
    void showInfor(){cout<<"age:"<<age<<endl<<"color:"<<color;}
};


/* 请在这里填写答案 */

int main(){
    Animal ani(5);
    cout<<"age of ani:"<<ani.getAge()<<endl;
    Dog dog(5,"black");
    cout<<"infor of dog:"<<endl;
    dog.showInfor();
}

