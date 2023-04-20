#include <iostream>
using namespace std;


struct Stack
{

public:
    int *a;
    int top;
    int capacity;
 public:
    //C++在这还可以定义函数
    void Init(int defaultCapacity = 4)
    {
        a = (int *)malloc(sizeof(int) * defaultCapacity);
        if(nullptr == a)
        {
            perror("malloc error");
            return;
        }

        capacity = defaultCapacity;
        top = capacity;
    }

};


int main() {
    Stack st = {nullptr,0,0};
    st.Init();
    cout << sizeof(st)<< endl;

    return 0;
}
