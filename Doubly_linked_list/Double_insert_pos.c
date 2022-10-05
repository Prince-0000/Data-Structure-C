#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *prev,*next;
}node;
void create();
void addpos(int data,int pos);
void view();
node *head=NULL;
int n;
int main()
{
    create();
    view();
    int data,pos;
    printf("\nEnter the element to insert : ");
    scanf("%d",&data);
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    addpos(data,pos);
    view();

    return 0;
}
void create(){
    struct node *list=NULL;
    int i=0;
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
void addpos(int data,int pos){
    node *temp=NULL,*newnode=NULL;
    temp=head;
    if(temp==NULL){
        printf("\nList is empty");
        exit(1);
    }
    if(pos>n || pos<1){
        printf("\nYou are adding element out of bound");
        exit(1);
    }
    newnode = (node*)malloc(sizeof(node));
    newnode->info = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    int i=0;
    while(i<pos-2){
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->prev = newnode;
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