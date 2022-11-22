#include <stdio.h>


struct ElenType{
    int value;

};

typedef struct BiTNode{
    struct ElenType data;
    struct BiTNode *lchild, *rchild;

}BiTNode,*bitree;
int main() {

    BiTNode biTNode = {1, NULL,NULL};
    return 0;
}
