#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *prev,*next;
}node;
node *start = NULL;
void create();
void view();
void insertbeg();
void insertend();
void insertbefore();
void insertafter();
int main()
{
    int data;
    create();
    int choice;
    while(1){
        printf("\n1.At Beginning\n2.At End\n3.Before\n4.After\n5.View\n6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : insertbeg();
                     break;
            case 2 : insertend();
                     break;
            case 3 : insertbefore();
                     break;
            case 4 : insertafter();
                     break;
            case 5 : view();
                     break;
            case 6 : exit(0);
                     break;
            default : printf("\nInvalid Choice *_*");
        }    
    }
    return 0;
}
    void create(){
    node *list=NULL;
    int n,i=0;
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);
    while(i<n){
        if(start == NULL){
            start = list = (struct node*)malloc(sizeof(struct node));
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
void view(){
    node *ptr = NULL;
    ptr = start;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}
void insertbeg(){
    int data;
    printf("\nEnter the data : ");
    scanf("%d",&data);
    node *newnode= NULL;
    newnode = (node*)malloc(sizeof(node));
    newnode->info = data;
    newnode->prev = NULL;
    start->prev = newnode;
    newnode->next = start;
    start = start->prev;
}
void insertend(){
    node *temp = NULL,*newnode=NULL;
    temp = start;
    newnode = (node*)malloc(sizeof(node));
    int data;
    printf("\nEnter the data : ");
    scanf("%d",&data);
    newnode->info = data;
    newnode->next = NULL;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insertbefore(){
    node *temp=NULL,*newnode=NULL;
    temp = start;
    newnode = (node*)malloc(sizeof(node));
    int data,key;
    printf("Enter the element to be search : ");
    scanf("%d",&key);
    printf("\nEnter the data : ");
    scanf("%d",&data);
    newnode->info = data;
    newnode->next = NULL;
    while(temp->info!=key){
        temp = temp->next;
    }
    newnode->prev = temp->prev;
    newnode->next = temp;
    temp->prev->next = newnode;
    temp->prev = newnode;
}
void insertafter(){
    node *temp=NULL,*newnode=NULL;
    temp = start;
    newnode = (node*)malloc(sizeof(node));
    int data,key;
    printf("Enter the element to be search : ");
    scanf("%d",&key);
    printf("\nEnter the data : ");
    scanf("%d",&data);
    newnode->info = data;
    newnode->next = NULL;
    while(temp->info!=key){
        temp = temp->next;
    }
    if(temp->info!=key){
        printf("Element not found");
        return;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->prev = newnode;
}