#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
void delbeg();
void delend();
void create();
void view();
void check(int n);
int main()
{
    create();
    int choice,n;
    while(1){

        printf("\n1.Insert at beginning\n2.Insert at end\n3.View\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        check(n);
        switch(choice){
            case 1 : delbeg();
                     break;
            case 2 : delend();
                     break;
            case 3 : view();
                     break;
            case 4 : exit(0);
                     break;
            default : 
                    printf("Invalid choice *_*");     
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
void delbeg(){
    struct node *temp1=NULL,*temp2=NULL;
    temp1=start;
    while(temp1->link!=NULL){
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = temp1->link;
    free(temp1);
}
void delend(){
    struct node *temp=NULL;
    temp = start;
    start = temp->link;
    free(temp);
}

void view(){
    struct node *ptr = NULL;
    ptr = start;
    printf("\nFinal list : ");
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
void check(int n){
    int choice;
    if(choice>=n)
        printf("Now, List is empty");
        return;
}
