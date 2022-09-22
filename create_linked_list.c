#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
}*head=NULL;
int main()
{
    struct node *list=NULL,*list_ptr=NULL;
    int n,i=0;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    while(i<n){
        //if head is NULL then it assign address of first node.
        if(head == NULL){    
            head = list = (struct node*)malloc(sizeof(struct node));
        }else{
        //it stores address of the next node.
            list->link = (struct node*)malloc(sizeof(struct node));
            list = list->link;
        }
        printf("Enter the value of info : ");
        scanf("%d",&list->info);
        i++;
    }
    //after creating nodes assign last node link to NULL.
    list->link = NULL;
    //for printing
    printf("All values are : ");
    list_ptr = head;
    while(list_ptr!=NULL){
        printf("%d ",list_ptr->info);
        list_ptr = list_ptr->link;
    }
    return 0;
}