#include <iostream>
using namespace std;
namespace bit{
    int a = 0;

    namespace N1{
        int a = 1;
    }


}

void fun(int a , int b = 20, int c = 30)
{

}

int main() {
    //cout << "Hello, World!" <<endl;
    cout << bit::N1::a << endl;
    return 0;
}
