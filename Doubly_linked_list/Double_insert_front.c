#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *prev,*next;
}*head=NULL;
void create();
void addfront(int data);
void view();
int main()
{
    create();
    view();
    int data;
    printf("\nEnter the element to insert : ");
    scanf("%d",&data);
    addfront(data);
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
void addfront(int data){
    struct node *newnode = NULL,*ptr=NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    newnode->prev = NULL;
    head->prev = newnode;
    newnode->next = head;
    head = head->prev;
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