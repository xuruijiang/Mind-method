#include "contact.h"

int main() {

    int input = 0;
    //创建通讯录
    Contact contact;
    //初始化通讯录
    InitContact(&contact);


    do {
        menu();
        printf("请选择: ");
        scanf("%d",&input);
        switch (input) {

            case 1:
                add(&contact);
                break;
            case 2:
                del((&contact));
                break;
            case 3:
                seek(&contact);
                break;
            case 4:
                modify(&contact);
                break;
            case 5:
                show(&contact);
                break;
            case 6:
                sort(&contact);
                break;
            case 0:
                break;
            default:
                printf("输入不合法，请重新输入:\n");
                break;
        }

    } while (input );

    return 0;
}
