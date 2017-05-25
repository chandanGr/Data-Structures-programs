#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*head;

void insert(struct node *head, int key){

    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = key;
        head->left = head->right = NULL;
    }else if(key < head->data){
        insert(head->left, key);
    }else{
        insert(head->right, key);
    }

}

void inorder(struct node *head){
    if(head){
        inorder(head->left);
        printf(head->data);
        inorder(head->right);
    }
}

int size(struct node *head){

    if(head != NULL){
        printf("ff");
        return(size(head->left) + 1 + size(head->right));
    }else{
        return 0;
    }

}

int main(){
int i, value, c;
    while(1){
        printf("Enter Your Choice : \n");
        printf("\t 1 : Insert \n");
        printf("\t 2 : size of the tree \n");
        printf("\t 3 : to Exit \n");
        printf("\t 4 : inorder \n");
        scanf("%d", &i);

        switch(i){
            case 1 :
                printf("enter the value \n");
                scanf("%d", &value);
                insert(head, value);
                break;
            case 2 :
                c = size(head);
                printf("the size is %d", c);
                break;
            case 3 :
                exit(0);
            case 4 :
                inorder(head);
        }
    }
return 0;
}



























