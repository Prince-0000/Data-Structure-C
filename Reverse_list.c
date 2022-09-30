#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
};
struct node *head=NULL;
struct node *reverse(struct node *start);
void create();
int main()
{
    struct node *list_ptr=NULL,*ptr=NULL;
    create();
    list_ptr = head;
    printf("All values are : ");
    while(list_ptr!=NULL){
        printf("%d ",list_ptr->info);
        list_ptr = list_ptr->link;
    }
    printf("\nReverse list is : ");
    ptr = reverse(head);
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    return 0;
}
void create(){
struct node *list=NULL,*list_ptr=NULL;
    int n,i=0;
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);
    while(i<n){
        if(head == NULL){
            head = list = (struct node*)malloc(sizeof(struct node));
        }else{
            list->link = (struct node*)malloc(sizeof(struct node));
            list = list->link;
        }
        printf("Enter the value of info : ");
        scanf("%d",&list->info);
        i++;
    }
    list->link = NULL;
}
struct node *reverse(struct node *start){
    struct node *end;
    if (start ==NULL || start->link == NULL){
        return start;
    }
    end = reverse(start->link);
    start->link->link = start;
    start->link = NULL; 
    return end;
}
