#include <stdio.h>
#include <stdlib.h>


//--------------------------------------手动分割-------------------------------------//
typedef char TNodeType;
typedef struct Node{
    TNodeType val;
    struct Node * left;
    struct Node * right;
}Node;
//--------------------------------------手动分割-------------------------------------//

//创建二叉树
Node * TreeCreat(char *arr, int* pi)
{
    if(arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }//if

    Node * root = (Node *)malloc(sizeof(Node));
    root->val = arr[*pi];
    (*pi)++;

    root->left = TreeCreat(arr,pi);
    root->right = TreeCreat(arr,pi);

    return root;

}//函数结束
//--------------------------------------手动分割-------------------------------------//

//中序遍历
void Inorder(Node * root)
{

    if(root == NULL)
    {
        return;
    }

    Inorder(root->left);
    printf("%c ",root->val);
    Inorder(root->right);
}//函数结束
//--------------------------------------手动分割-------------------------------------//

int main() {

    char arr[100];
    int i = 0;
    Node  * p = TreeCreat(arr,&i);
    Inorder(p);
    return 0;
}
