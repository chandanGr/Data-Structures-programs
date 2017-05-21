#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head, *head11;

void insertDataToLinkList1(int value){
    struct node *var;
    struct node *temp;
    temp = head;
    var = (struct node *)malloc(sizeof(struct node));
    var -> data = value;

    if(head == NULL){
        head = var;
        head->next = NULL;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = var;
        var->next = NULL;
    }
}

void insertDataToLinkList2(int value){
    struct node *temp;
    struct node *var;
    temp = head11;
    var = (struct node *)malloc(sizeof(struct node));
    var -> data = value;

    if(head11 == NULL){
        head11 = var;
        head11->next = NULL;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = var;
        var->next = NULL;
    }
}

void appendTwoLinkList(struct node *head, struct node *head11){
   struct node *temp = head;

   if(head == NULL){
        temp = head11;
   }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head11;
        head11 = head;
        numberOfNodes();
   }
}

void deleteCompleteLinkList(){
    struct node *temp2;
    struct node *temp1;
    temp1 = head;
    if(head == NULL){
        printf("link lists is already empty \n");
    }else{
        while(temp1 != NULL){
            temp2 = temp1->next;
            free(temp1);
            temp1 = temp2;
        }
        head = NULL;
        printf("all the nodes are deleted \n");
        numberOfNodes();
    }
}

void numberOfNodes(){
    struct node *temp;
    int count = 0;
    temp = head;
    while(temp != NULL){
        count ++;
        temp = temp->next;
    }
    printf("Number of nodes are  : %d \n", count);
}

void main(){
    int i, value;
    while(1){
        printf("enter the choice :\n");
        printf("\t 1 : exit \n");
        printf("\t 2 : insertDataToLinkList1 \n");
        printf("\t 3 : numberOfNodes \n");
        printf("\t 4 : deleteCompleteLinkList \n");
        printf("\t 5 : insertDataToLinkList2 \n");
        printf("\t 6 : appendTwoLinkList\n");

        scanf("%d", &i);
        switch(i){
            case 1 :
                exit(0);
            case 2 :
                printf("Enter the data to b inserted \n");
                scanf("%d", &value);
                insertDataToLinkList1(value);
                break;
            case 3 :
                numberOfNodes();
                break;
            case 4 :
                deleteCompleteLinkList();
                break;
            case 5 :
                printf("Enter the data to b inserted \n");
                scanf("%d", &value);
                insertDataToLinkList2(value);
                break;
            case 6 :
                appendTwoLinkList(head, head11);
                break;
            default :
                exit(0);
        }
    }

}
