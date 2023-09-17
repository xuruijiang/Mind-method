#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//----------------------------------------------------------//
void Convergence()
{
    char* cp = malloc(100);
    printf("请输入字符串(小于100个字符)！\n");
    scanf("%s",cp);
    char ch[100] = {0};

    for (int i = 0; i < sizeof(ch) ; ++i) {
        ch[i] = '*';
    }//for

    int count = (int)strlen(cp);
    ch[count] = '\0';

    int right = count - 1;
    int left = 0;

    do {
        ch[left] = cp[left];
        ch[right] = cp[right];
        printf("%s\r",ch);
        fflush(stdout);
        left++;
        right--;
        usleep(500000);
    } while (right >= left);

}//函数结束
//----------------------------------------------------------//
int main() {

    Convergence();
    return 0;
}
//----------------------------------------------------------//
//知识点 strcmp(char * cp1, char * cp2)
//如果cp1>cp2则返回大于0的数
//如果cp1<cp2则返回小于0的数
//如果cp1==cp2则返回等于0的数