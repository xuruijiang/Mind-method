#include <stdio.h>
//5. 定义一个结构体类型描述图书的基本信息，一本图书的基本信息包括：编号，书名，作者，价格。
//编写程序，实现如下功能：（1）输入10本书的信息，保存在结构体数组中。（2）输出10本图书中价格最高的图书信息。
//（3）对结构体数组按照价格进行升序排列，排序之后，下标为0的数组成员存放价格最低的图书信息，…下标为9的数组成员
//存放价格最高的图书信息。

struct Book{
    int id;
    char name[20];
    char author[20];
    float price;
};

int main() {

    struct Book books[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d %s %s %f",&books[i].id,books[i].name,books[i].author,&books[i].price);
    }
    struct Book tempBook;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if(books[j].price > books[j + 1].price)
            {
                tempBook = books[j];
                books[j] = books[j + 1];
                books[j + 1] = tempBook;
            }
        }
    }

    printf("%d %s %s %f",books[9].id,books[9].name,books[9].author,books[9].price);


    return 0;
}
