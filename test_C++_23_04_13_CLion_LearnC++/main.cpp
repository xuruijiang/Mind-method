#include <iostream>

using std::cout ;
using std::endl;
void Func(int a = 0)
{
    cout << a << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << "你好 大小姐" << endl;



    Func();//没有传参时，使用参数的默认值
    Func(10);//传参时，使用指定的实参
    return 0;
}
