#include <iostream>

using  std::cout;
using  std::endl;
class A{

public:
    void fun(){
        cout << "hello world" << endl;
    }
};

class B{
public:
    int a;
public:
    B(){
        cout << "aa" << endl;
    }

    ~B(){

    }
};


class C
{
public:
    //这里是给缺省值
    int _year = 1;
    int _month = 1;
    int _day = 1;

public:
    C(int _year, int _month, int _day)
    {
        this->_year = _year;
        this->_month = _month;
        this->_day = _day;
    }

};


int main() {
    //std::cout << "Hello, World!" << std::endl;
    A a;
    a.fun();
    C c(2023,4,30);
    cout << c._year << endl;
    return 0;
}
