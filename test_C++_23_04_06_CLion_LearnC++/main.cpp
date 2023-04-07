#include <iostream>
#include <string>
using namespace std;
#define MAX 10
//这是一个注释
int main()
{
    cout <<"Hello world" << endl;
    std::cout << "Hello, World!" << std::endl;
    std::cout << "你好， 世界"<<std::endl;

    int a = 0;
    cout <<"a = " << a << endl;

    int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        cout << arr[i] << endl;
    }//for
    const int m = 5;
    cout<<endl;
    cout << sizeof(short)<<endl;
    cout << sizeof(int)<<endl;
    cout << sizeof(long)<<endl;
    cout << sizeof(char)<<endl;
    cout << sizeof(long long )<<endl;
    cout << sizeof(float) << "\n";
    cout << sizeof(double )<<endl;
    cout << sizeof(bool )<<endl;
    bool bo = true;
    cout << "bo = " << bo << endl;
    bo = false;
    cout << "bo = " << bo << endl;

    //科学计数法

    int n = 3e2; //  n = 300
    cout << "n = " << n << endl;
    float b = 3e-2; // b = 0.03
    cout << "b = " << b <<endl;

    //char ch = ""; 错误
    //char ch = 'abcd'; 这里虽然警告但是存的是d
    //cout << ch << endl;

    cout << "aaa\thello" << endl;
    cout << "aaaa\thello" << endl;
    cout << "aaaaa\thello" << endl;
    cout << "aaaaaa\thello" << endl;
    cout << "aaaaaaa\thello" << endl;
    cout << "aaaaaaaaaa\thello" << endl;
    cout << "aaaaaaaaaaaa\thello" << endl;
    cout << "aaaaaaaaaaaaaaa\thello" << endl;
    string s = "abcdef";
    cout << s << endl;

    int int_a = 0;
    cout << "请给整型变量int_a赋值" << endl;
//    cin >> int_a;
//    cout << "int_a = " << int_a << endl;
//
//    char ch = getchar();
//    cout << (char )(ch + 38) << endl;
//    // cout << sizeof(s) << endl;
//
//    cin >> bo ;
//    //printf("%d\n",bo);
//    cout << bo << endl;

    cout << "a = " << 3 << endl << "b = " << 4 << endl;

    double dOne = 3.5;
    double dTwo = 2.4;
    //bool bo = true;
    bo = true;
    bo = false;
    char chh = 'a';
    cout << chh % 3 << endl;
    return 0;
}
