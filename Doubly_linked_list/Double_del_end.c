#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *prev,*next;
}node;
node *head=NULL;
void create();
int delend();
void view();
int main()
{
    create();
    view();
    int del = delend();
    printf("\nDeleted element is : %d",del);
    view();
    return 0;
}
void create(){
    struct node *list=NULL;
    int n,i=0;
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);
    while(i<n){
        if(head==NULL){
            head = list = (struct node*)malloc(sizeof(struct node));
            list->prev = NULL;
        }else{
            list->next = (struct node*)malloc(sizeof(struct node));
            list->next->prev = list;
            list = list->next;
        }
        printf("Enter the value of info : ");
        scanf("%d",&list->info);
        i++;
    }
    list->next = NULL;
}
int delend(){
    node *temp=NULL,*ptr=NULL;
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    int value = temp->info;
    temp->prev->next = NULL;
    free(temp);
    return value;
}
void view(){
    struct node *list_ptr=NULL;
    printf("\nDoubly linked list values : ");
    list_ptr = head;
    while(list_ptr !=NULL){
        printf("%d ",list_ptr->info);
        list_ptr = list_ptr->next;
    }
}