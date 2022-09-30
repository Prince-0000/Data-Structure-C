#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
void insertbeg();
void insertend();
void create();
void view();
int main()
{
    create();
    int choice;
    while(1){

        printf("1.Insert at beginning\n2.Insert at end\n3.View\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : insertbeg();
                     break;
            case 2 : insertend();
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
void insertbeg()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to insert at beginning : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertend()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to insert at end : ");
    scanf("%d", &data);
    temp->link = NULL;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
void view(){
    struct node *ptr = NULL;
    ptr = start;
    while(ptr!=NULL){
        printf("%d ",ptr->info);
        ptr = ptr->link;
    }
}
