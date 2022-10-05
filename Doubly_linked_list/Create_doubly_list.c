#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *prev,*next;
}*head=NULL;
int main()
{   
    struct node *list=NULL,*list_ptr=NULL,*end=NULL;
    int n,i=0;
    printf("Enter the no. of nodes ");
    scanf("%d",&n);
    while(i<n){
        if(head == NULL){
            head = list = (struct node*)malloc(sizeof(struct node));
            list->prev = NULL;
        }else{
            list->next = (struct node*)malloc(sizeof(struct node));;
            list->next->prev = list;
            list = list->next;
        }   
        printf("Enter the no. of nodes : ");
        scanf("%d",&list->info);
        i++;
    }
    list->next = NULL;

    //Printing the values
    printf("All values : ");
    list_ptr = head;
    while(list_ptr !=NULL){
        end = list_ptr;
        printf("%d ",list_ptr->info);
        list_ptr = list_ptr->next;
    }
    return 0;
}
