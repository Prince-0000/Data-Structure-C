#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *odd(struct node *head);
int main(){
struct node *list=NULL,*list_t=NULL,*list_ptr=NULL,*ptr=NULL;
int n,i=0;
printf("Enter the no. of nodes : ");
scanf("%d",&n);
do{
    if(list==NULL){
        list = list_t = (struct node*)malloc(sizeof(struct node*));
    }else{
        list_t->link = (struct node*)malloc(sizeof(struct node*));
        list_t = list_t->link;
    }
    printf("Enter the value of info : ");
    scanf("%d",&list_t->info);
    i++;
}while(i<n);
list_t->link = NULL;
list_ptr = list;
printf("\nAll values are : ");
while(list_ptr!=NULL){
    printf("%d ",list_ptr->info);
    list_ptr = list_ptr->link;
}
printf("\nOdd Elements are : ");
ptr = odd(list);
return 0;
}
struct node *odd(struct node *head){
    if(head==NULL){
        return head;
    }else{
        if(head->info%2!=0){
            printf("%d ",head->info);
        }
    }
        head->link = odd(head->link);
}
