#include <iostream>

#define ADD(x,y) (((x) + (y)) * 10)
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};
//--------------------手动分割------------------------//

int Count()
{
    static int n = 0;
    n++;

    return n;
}//函数结束

//--------------------手动分割------------------------//

int& Count1()
{
    int n = 0;
    n++;
    return n;
}//函数结束
//--------------------手动分割------------------------//
int main() {

//    int a = 0;
//    int & b = a;
//    double c = 0.0;
//    double &d = c;
//    printf("%d\n",(int)sizeof(b));
//    printf("%d\n",(int)sizeof(d));
//    int &n = Count1();
//    cout << n << endl;
//    int m = Count();
//    Count();
//    cout << n << endl;

    //int& a = 10;//错
    int n = ADD(4,5);
    printf("%d\n",n);
    int x = Count1();
    cout << x << endl;

    return 0;
}
