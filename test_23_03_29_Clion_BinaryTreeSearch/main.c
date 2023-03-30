#include <stdio.h>

typedef int BTDataType;
typedef struct BTNode{
    BTDataType val;
    struct BTNode * left;
    struct BTNode * right;

}BTNode ;

BTNode * BinaryTreeFind(BTNode* root,BTDataType x)
{
    if(root == NULL)
    {
        return NULL;
    }//if
    if(root->val == x)
    {
        return root;
    }//if

    BTNode *p1 = BinaryTreeFind(root->left,x);

    if(p1 != NULL)
        return p1;

    BTNode *p2 = BinaryTreeFind(root->right,x);

    if(p2 != NULL)
        return p2;


    return NULL;


}


int main() {

    BTNode a1;
    BTNode a2;
    BTNode a3;
    BTNode a4;
    BTNode a5;
    BTNode a6;
    BTNode a7;
    a1.val = 3;
    a2.val = 4;
    a3.val = 5;
    a4.val = 7;
    a5.val = 9;
    a6.val = 31;
    a7.val = 33;
    a1.left = &a2;
    a2.left = &a4;
    a3.left = &a6;
    a1.right = &a3;
    a2.right = &a5;
    a3.right = &a7;

    a4.left = NULL;
    a4.right = NULL;
    a5.left = NULL;
    a5.right = NULL;
    a6.left = NULL;
    a6.right = NULL;
    a7.left = NULL;
    a7.right = NULL;

    BTNode *p = BinaryTreeFind(&a1,31);

    printf("%d\n",p->val);


    int m[10] = {1,2,3,4,5,6,7,8,9,65};

    m[1]++, printf("%d\n",(*(m + 1)));//6

    putchar(*(m + 9));

    return 0;
}
