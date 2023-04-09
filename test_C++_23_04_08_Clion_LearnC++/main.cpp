#include <iostream>
#include <ctime>
using namespace std;
int main() {

    srand((unsigned int) time(NULL));
    int i = 0;
   ba: 
    i = rand() % 100;
    cout << i << endl;
    
    if(i != 99)
    {
        goto ba;
    }//if


    bool bo = true;
    switch (1) {
        case 1:
            cout << "1" << endl;
            break;
        case 0:
            cout << "0" << endl;
            break;

    }

    return 0;
}
