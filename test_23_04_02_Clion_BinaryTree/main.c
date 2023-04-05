#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef char BTDataType;


//-------------------------------------------------手动分割----------------------------------------------//
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;
//-------------------------------------------------手动分割----------------------------------------------//
BTNode * btNodeCreat(BTDataType c)
{
    BTNode * btNode = (BTNode*)malloc(sizeof(BTNode));
    btNode->_left = NULL;
    btNode->_right = NULL;
    btNode->_data = c;
    return btNode;
}//函数结束

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
    if(*pi > n - 1)
    {
        return NULL;
    }
    if(a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }//if

    BTNode * newNode = btNodeCreat(a[(*pi)++]);
    newNode->_left = BinaryTreeCreate(a,n,pi);
    newNode->_right = BinaryTreeCreate(a,n,pi);
    return newNode;

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树销毁
void BinaryTreeDestory(BTNode* root){

    if(root == NULL)
    {
        return;
    }//if

    BinaryTreeDestory(root->_left);
    BinaryTreeDestory(root->_right);
    free(root);
    root = NULL;

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    if(root == NULL)
    {
        return 0;
    } //if

    int leftNode = BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;

    return leftNode;
}
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if(root == NULL )
    {
        return 0;
    }
    if(root->_left == NULL && root->_right == NULL )
    {
        return 1;
    }

    int leafNode = BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);

    return leafNode;
}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if(root != NULL  && k == 1)
    {
        return 1;
    }//if
    if(root == NULL)
    {
        return 0;
    }//if

    int nodeSize = BinaryTreeLevelKSize(root->_left,k - 1) + BinaryTreeLevelKSize(root->_right,k - 1);

    return nodeSize;

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
    BTNode * node = NULL;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->_data == x)
    {
        return root;
    }

    node = BinaryTreeFind(root->_left,x);
    if(node != NULL)
    {
        return node;
    }//if
    node = BinaryTreeFind(root->_right,x);

    return node;


}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
    if(root != NULL)
    {
        printf("%c ",root->_data);
    }//if
    else
    {
        return;
    }//else

    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{

    if(root == NULL)
    {
        return;
    }//if

    BinaryTreeInOrder(root->_left);
        printf("%c ",root->_data);
    BinaryTreeInOrder(root->_right);

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if(root == NULL)
    {
        return;
    }//if
    BinaryTreePostOrder(root->_left);
    BinaryTreePostOrder(root->_right);

    printf("%c ",root->_data);

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//
typedef struct Node{
    BTDataType val;
    struct Node * next;
    BTNode *left;
    BTNode *right;
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
}Queue;

Node * NodeCreat(BTDataType x,BTNode * left,BTNode * right)
{
    Node * N = (Node*) malloc(sizeof (Node));
    N->val = x;
    N->next = NULL;
    N->left = left;
    N->right = right;
    return N;
}//
Queue * QueueCreat()
{
    Queue * p = (Queue*) malloc(sizeof(Queue));
    p->size = 0;
    p->head = NULL;
    p->tail = NULL;
    return p;

}//函数结束

//入队列
void QueuePush(Queue * queue , BTDataType x,BTNode * left,BTNode * right)
{
    assert(queue);
    if(queue->size == 0)
    {
        queue->head = queue->tail = NodeCreat(x,left,right);
        queue->size++;
    }//if
    else
    {
        queue->tail->next = NodeCreat(x,left,right);
        queue->tail = queue->tail->next;
        queue->size++;
    }//
}//函数结束

//出队列
int QueuePop(Queue * queue)
{
    BTDataType num = 0;
    assert(queue);
    if(queue->size == 0)
    {
        return -1;
    }//if
    if(queue->size == 1)
    {
        num = queue->head->val;
        free(queue->head);
        queue->head = queue->tail = NULL;
        queue->size--;
        return num;
    }
    else
    {
        Node *p = queue->head->next;
        num = queue->head->val;
        free(queue->head);
        queue->head = p;
        queue->size--;
    }//

    return num;
}//函数结束



// 层序遍历
void BinaryTreeLevelOrder(BTNode* root){
    if(root == NULL)
    {
        return;
    }//if
    Queue * queue = QueueCreat();
    QueuePush(queue,root->_data,root->_left,root->_right);
    int num = 0;

    while (queue->size)
    {
        num = queue->size;
        while (num--)
        {
            if(queue->head->left != NULL)
            {
                QueuePush(queue,queue->head->left->_data,queue->head->left->_left,queue->head->left->_right);
            }
            if(queue->head->right != NULL)
            {
                QueuePush(queue,queue->head->right->_data,queue->head->right->_left,queue->head->right->_right);
            }

            printf("%c,", QueuePop(queue));
        }//while

    }//while


}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
    int num = 1;
    if(root == NULL )
    {
        return 1;
    }


    if(root -> _left == NULL && root -> _right == NULL)
    {
        return 1;
    }

    if(root->_left == NULL && root ->_right != NULL)
    {
        return 3;
    }
    if(root->_left != NULL && root->_right == NULL)
    {
        return 0;
    }

    int left = BinaryTreeComplete(root->_left);
    int right = BinaryTreeComplete(root->_right);
    if(left == 0 && right == 0 )
    {
        return 3;
    }
    if(left == 3 || right == 3)
    {
        return 3;
    }

    return 1;

}//函数结束
//-------------------------------------------------手动分割----------------------------------------------//


int main() {
    char a[] = "ABD##E#H##CF##G##";
    int pi = 0;
    BTNode *p = BinaryTreeCreate(a,(int)strlen(a),&pi);

    BinaryTreePrevOrder(p);
    printf("\n");
    //BinaryTreeDestory(p);

    printf("%d\n", BinaryTreeSize(p));
    printf("%d\n", BinaryTreeLeafSize(p));
    printf("%d\n", BinaryTreeLevelKSize(p,1));

    BTNode *n = BinaryTreeFind(p,'E');
    printf("%c\n",n->_data);
    BinaryTreeInOrder(p);
    printf("\n");
    BinaryTreePostOrder(p);
    printf("\n");
    BinaryTreeLevelOrder(p);
    printf("\n");

    if( BinaryTreeComplete(p) == 3)
    {
        printf("不是完全二叉树\n");
    }
    else{
        printf("是完全二叉树\n");
    }

    return 0;
}
