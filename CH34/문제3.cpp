
//mylib.hpp
#ifndef _MAX_HPP_
#define _MAX_HPP_
class Max
{
    int a;
    int b;
    int m;
    public:
    void input();
    void max();
    void print();
};
#endif
//main.cpp
#include "mylib.hpp"
int main(void)
{
    Max a;
    a.input();
    a.max();
    a.print();
    return 0;
}

//mylib.cpp
#include<iostream>
#include "mylib.hpp"
using namespace std;
void Max::input()
{
    cout << "Input:";
    cin >> a;
    cout << "Input:";
    cin >> b;
}
void Max::max(){ 
    if(a>=b) m=a;
    else m=b;
}
void Max::print()
{ cout <<"max:"<<m<< endl; }
