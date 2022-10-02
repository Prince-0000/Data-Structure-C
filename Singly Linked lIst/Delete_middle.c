#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *head = NULL;
void create();
void view();
struct node *delmid(int key,struct node *start);
int main()
{
    create();
    int choice;
    int key,num,info,n;
    while(1){
        printf("\n1.Delete Element\n2.view\n3.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                    printf("Enter the element to search : ");
                    scanf("%d",&info);
                    delmid(info,head);
                    break;
            case 2 : view();
                     break;
            case 3 : exit(0);
                     break;
            default : printf("Invalid choice *_*");
        }
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
void view(){
    struct node *ptr=NULL;
    ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
}
struct node *delmid(int key, struct node *start) {
    struct node *cur = start,*temp=NULL;
    while (cur->info != key) {
        temp = cur;
        cur = cur->link;
    }
    temp->link = cur->link;
    free(cur);
    return start;
}