//
//  main.c
//  tste_9_29_Xcode_mergeTwoOrderedLinkedLists
//
//  Created by 徐瑞江 on 2022/9/30.
//

#include <stdio.h>
#include <stdlib.h>

//好烧脑，先不做，累死，真的服气。 重做
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if (list1 == NULL && list2 == NULL){
        return NULL;
    } else if (list1 == NULL){
        return list2;
    } else if (list2 == NULL){
        return list1;
    }

    if(list1->next == NULL && list2->next == NULL){
        if(list1->val < list2->val){
            list1->next = list2;
            return list1;

        }else{
            list2->next = list1;
            return list2;

        }

    }


    struct ListNode *listNode = list1;
    struct ListNode *listNodeOne = list1;
    struct ListNode *listNodeTwo = list2;

    int flag = 0;

    int m = 0;

    while (listNodeOne->next == NULL && listNodeTwo->next != NULL) {//应该没有问题
        if(listNodeOne->val < listNodeTwo->val){

            if(flag == 0){
                m = 1;
                listNode->next = listNodeTwo;
                flag = 1;
                break;
            }else{

                listNode->next = listNodeOne;
                listNodeOne->next = listNodeTwo;
                flag = 1;
                break;
            }

        }else{

            if(flag == 0){
                listNode = listNodeTwo;
                m = 2;
                listNodeTwo = listNodeTwo->next;
                flag = 1;
            }else{
                listNode->next = listNodeTwo;
                listNode = listNode->next;
                listNodeTwo = listNodeTwo->next;
                flag = 2;
            }








        }


    }


    if(flag == 2){
        if(listNodeOne->val < listNodeTwo->val){
            listNode->next = listNodeOne;
            listNodeOne->next = listNodeTwo;

        }else{
            listNode->next = listNodeTwo;
            listNodeTwo->next = listNodeOne;

        }

    }

    if(flag){

        if(m == 1 ){
            return list1;
        }else{
            return list2;
        }
    }

    //

    while (listNodeOne->next != NULL && listNodeTwo->next == NULL) {//需要修改
        if(listNodeTwo->val < listNodeOne->val){

            if(flag == 0){
                m = 2;
                listNode = listNodeTwo;
                listNodeTwo->next = listNodeOne;
                flag = 1;
                break;
            }else{

                if(flag == 0){
                    listNodeOne = listNodeOne->next;
                    continue;
                }
                listNode->next = listNodeTwo;
                listNodeTwo->next = listNodeOne;
                flag = 1;
                break;
            }

        }else{

            if(flag == 0){
                m = 1;
                listNodeOne = listNodeOne->next;
                flag = 1;
            }else{
                listNode->next = listNodeOne;
                listNode = listNode->next;
                listNodeOne = listNodeOne->next;
                flag = 2;
            }








        }


    }


    if(flag == 2){
        if(listNodeOne->val < listNodeTwo->val){
            listNode->next = listNodeOne;
            listNodeOne->next = listNodeTwo;

        }else{
            listNode->next = listNodeTwo;
            listNodeTwo->next = listNodeOne;

        }

    }

    if(flag){

        if(m == 1 ){
            return list1;
        }else{
            return list2;
        }
    }

    //




    while (listNodeOne->next != NULL && listNodeTwo->next != NULL){

        if (flag == 0){
            if (list1->val < list2->val){
                listNodeOne = listNodeOne->next;
                listNode = list1;
                m = 1;
                flag = 1;
            } else{
                listNodeTwo = listNodeTwo->next;
                listNode = list2;
                m = 2;
                flag = 1;
            }

        } else{

            if (listNodeOne->val < listNodeTwo->val){
                listNode->next = listNodeOne;
                listNode = listNode->next;
                listNodeOne = listNodeOne->next;

            } else{

                listNode->next = listNodeTwo;
                listNode = listNode->next;
                listNodeTwo = listNodeTwo->next;

            }

        }

    }



    if (listNodeOne->next == NULL && listNodeTwo->next == NULL){
        if(listNodeOne->val < listNodeTwo->val){
            listNode->next = listNodeOne;
            listNode = listNode->next;
            listNode->next = listNodeTwo;

        } else{
            listNode->next = listNodeTwo;
            listNode = listNode->next;
            listNode->next = listNodeOne;
        }

        if (m == 1){
            return list1;
        } else{
            return list2;
        }
    }

    while (flag){

        if (listNodeOne->next == NULL){
            if(listNodeOne->val < listNodeTwo->val){
                listNode->next = listNodeOne;
                listNode = listNode->next;
                listNode->next = listNodeTwo;
                flag = 0;
            } else{
                listNode->next = listNodeTwo;
                listNode = listNode->next;
                if(listNodeTwo->next != NULL){
                    listNodeTwo = listNodeTwo->next;

                }else{
                    listNode->next = listNodeOne;
                    flag = 0;
                }


            }


        } else if(listNodeTwo->next == NULL){

            if(listNodeOne->val < listNodeTwo->val){
                listNode->next = listNodeOne;
                listNode = listNode->next;
                listNodeOne = listNodeOne->next;
            } else{
                listNode->next = listNodeTwo;
                listNode = listNode->next;
                listNodeTwo->next = listNodeOne;

                break;


            }


        }

    }

    if (m == 1){
        return list1;
    } else{
        return list2;
    }


}






int main() {


    struct ListNode listNode ;
    struct ListNode *listNode1 = &listNode;
    printf("%d\n",(int)sizeof(listNode));
    printf("%d\n",(int)sizeof(*listNode1));


    struct ListNode listNodeOne[10] = {{-10,listNodeOne + 1},{-9,listNodeOne + 2},{-6,listNodeOne+3},{-4,listNodeOne+4},{1,listNodeOne+5},{9,listNodeOne+6},{9,NULL}};
    struct ListNode listNodeTwo[10] = {{-5,listNodeTwo + 1},{-3,listNodeTwo + 2},{0,listNodeTwo + 3},{7,listNodeTwo + 4},{8,listNodeTwo + 5},{8,NULL}};
//    [-10,-9,-6,-4,1,9,9]
//    [-5,-3,0,7,8,8]


//    for (int i = 0; i < 5; ++i) {
//
//        listNodeOne[i].val = i + 1;
//        listNodeTwo[i].val = i + 1;
//
//        if(i < 4){
//            listNodeOne[i].next = &listNodeOne[i + 1];
//            listNodeTwo[i].next = &listNodeTwo[i + 1];
//        } else{
//
//            listNodeTwo[i].next = NULL;
//            listNodeOne[i].next = NULL;
//
//        }
//    }

    struct ListNode *listNode2;





    listNode2 =  mergeTwoLists(listNodeOne,listNodeTwo);


    while (listNode2->next != NULL){
        printf("%d,",listNode2->val);
        listNode2 = listNode2->next;
    }

    printf("%d",listNode2->val);

    return 0;
}
