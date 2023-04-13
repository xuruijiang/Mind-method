#include <iostream>
using namespace std;
int a = 0;
namespace bit
{
    int a = 10;
}

namespace N1
{
    int a = 0;
    int b = 0;
    int c = 0;
    namespace N2
    {
        int a = 0;
        int b = 0;
        int c = 0;

    }

}

//using namespace bit;
int main() {
    //int a = 1;
    //printf("%d",a);
    cout << a << endl;
    return 0;
}
