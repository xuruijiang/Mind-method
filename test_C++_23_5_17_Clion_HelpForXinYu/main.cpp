#include <iostream>
#include<string>
using namespace std;
class Date{


public:
    Date(int x,int y,int d)
    {
        printf("构造函数\n");
        year = x;
        month = y;
        day = d;
    }
    Date()
    {
        printf("构造函数\n");
        year = 0;
        month = 0;
        day = 0;
    }

    ~Date()
    {
        printf("析构函数\n");


    }
    Date(const Date& a)
    {
        printf("拷贝构造\n");
        year = a.year;
        month = a.month;
        day = a.day;
    }//这是拷贝构造

    Date  & operator=(const Date& a)
    {
        printf("赋值运算符重载\n");
        year = a.year;
        month = a.month;
        day = a.day;

        return *this;
    }//这是运算符重载


    Date& operator-( const Date& x);
    int year;
    int month;
    int day;

public:
    bool operator>(const Date& x) const
    {
        if(this->year > x.year )
        {
            return true;
        } else if(this->year == x.year && this->month > x.month)
        {
            return true;
        } else if (this->year == x.year && this->month == x.month && this->day > x.day)
        {
            return true;
        } else
        {
            return false;
        }


    }
};

Date&  Date::operator-( const Date& x){
    Date max = *this;
    Date min = x;
    if(x > *this)
    {

    }
    return *this;
}

template<typename T1,class TN2>
T1 fun(T1 t1, TN2 t2)
{
    return t1 + t2;
}

void init(char board[5][5], char set)
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            board[i][j] = set;
        }

    }

}

int main() {

//    char board[5][5] = {0};
//    init(board,'x');
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            printf("%c ",board[i][j]);
//        }
//        printf("\n");
//    }
//    char x  = 126;
//    x++;
//    printf("%d\n",x);
//    x++;
//    printf("%d\n",x);

//    string s("hello world");
//    s += "sss";
//    //cout << s << endl;
//    string s3("https://edu.bitejiuyeke.com/personInf/student?userId=12506");
//
//    size_t pos1 = s3.find("://");
//    cout << pos1 << endl;

//    string s = "你好";
//    char s1[] = "比特";
//    cout << s.size() << endl;
//    cout << sizeof(s1)<< endl;
//    Date *pclassa = new Date[5];
//    //int *p = (int *)malloc(4);
//    delete []pclassa;

//    Date *a = new Date;
//    delete a;
//    Date A;
//    Date B = A;
    //B = A;

    //cout << fun(1,4.5) << endl;

//    string s1;
//    string s2("混沌游戏");
//    string s3("hello");
//    string s4(10,'*');//初始化为10个*
//    string s5(s2);//拷贝构造
//    string s6(s2,3);
//
//    cout << s6 << endl;
//
//    const Date x(1,2,3);
//    Date y(2,3,4);
//    if(y > x){
//        ;
//    }
    return 0;
}
