#include <stdio.h>
#include <stdlib.h>

//* Definition for a binary tree node.
 struct TreeNode {
         int val;
         struct TreeNode *left;
         struct TreeNode *right;
    };
void BinaryTreePrevOrder(struct TreeNode* root, int * tree, int * returnSize)
{
    if(root == NULL)
    {
        return ;
    }

    tree[(*returnSize)++] = root->val;

    BinaryTreePrevOrder(root->left,tree,returnSize);
    BinaryTreePrevOrder(root->right,tree,returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){

    if(root == NULL)
    {
        return NULL;
    }

    int * tree = (int *)malloc(sizeof(int) * 3000);
    *returnSize = 0;
    BinaryTreePrevOrder(root,tree,returnSize);

    return tree;

}
int main() {
    struct TreeNode *p = NULL;

    struct TreeNode node1;
    struct TreeNode node2;
    struct TreeNode node3;
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node1.left = &node2;
    node1.right = &node3;

    node2.left = NULL;
    node2.right = NULL;
    node3.left = NULL;
    node3.right = NULL;

    p = &node1;
    int a = 0;
    int *i = &a;
    int *arr = preorderTraversal(p,i);

    printf("%d,%d,%d",arr[0],arr[1],arr[2]);

    return 0;
}
