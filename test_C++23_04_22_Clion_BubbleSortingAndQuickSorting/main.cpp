#include <iostream>
#include <unistd.h>
int main() {
    printf("你好 你就是垃圾 !\r");
    fflush(stdout);
    sleep(2);
    printf("nihao\r");
    fflush(stdout);
    sleep(3);
    printf("你好 你就是垃圾 !\n");

    return 0;
}
