#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *prev,*next;
}node;
node *head=NULL;
void create();
int delpos(int pos);
void view();
int n;
int main()
{
    create();
    view();
    int pos;
    printf("\nEnter the position to delete element : ");
    scanf("%d",&pos);
    int del = delpos(pos);
    printf("\nDeleted element is : %d",del);
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
int delpos(int pos){
    node *temp = NULL;
    if(pos<=1 || pos>=n){
        printf("Can't delete element at this position *_*");
        exit(1);
    }
        temp = head;
        int i=0;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        int value = temp->info;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
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
    
