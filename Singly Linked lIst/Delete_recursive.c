#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *link;
}node;
node *start = NULL;
void create();
void view();
node *delete(node *head,int k);
int main()
{
    create();
    view();
    int k;
    printf("Enter the value of k : ");
    scanf("%d",&k);
    node *head = delete(start,k);
    node *ptr_list = head;
    printf("\nFinal List : ");
    while(ptr_list!=NULL){
        printf("%d ",ptr_list->info);
        ptr_list = ptr_list->link;
    }

    return 0;

}
void create(){
struct node *list=NULL,*list_ptr=NULL;
    int n,i=0;
    printf("Enter the no. of nodes : ");
    scanf("%d",&n);
    while(i<n){
        if(start == NULL){
            start = list = (struct node*)malloc(sizeof(struct node));
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
void view(){
    node *ptr=NULL;
    ptr = start;
    printf("\nFinal List : ");
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
node *delete(node *head,int k)
{   
    if(head==NULL){
        printf("Element not found in the list");
        return NULL;
    }
    if(head->info==k){
        node *temp = head->link;
        free(head);
        return temp;
    }
    head->link = delete(head->link,k);
    return head;
    
}