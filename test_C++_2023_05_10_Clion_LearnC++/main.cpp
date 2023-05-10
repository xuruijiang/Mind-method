#include <iostream>
using namespace std;

class A{
private:
    static int k;
    int h;

public:
    class B{

    public:
        void foo()
        {

        }
    private:
        int b;
    };
};


int main() {
    A a;
    printf("%d\n", (int)sizeof(a));
    printf("%d\n",(int)sizeof(A));

    int b;
    int & c = b;

    int* p = new int[10];
    delete[] p;
}