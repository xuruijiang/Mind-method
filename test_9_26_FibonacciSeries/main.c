#include <stdio.h>


int Fibonacci(int n ) {
    // write code here
    if( n > 2){

        return Fibonacci(n -1) +  Fibonacci(n - 2);
    } else{
        return 1;
    }

}
int main() {
    int sum =  Fibonacci(4);
    printf("%d",sum);
    return 0;
}
