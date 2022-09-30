#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *head = NULL;
void create();
void view();
struct node *before(int num,int key,struct node *start);
struct node *after(int num,int key,struct node *start);
int main()
{
    create();
    int choice;
    int key,num,info,n;
    while(1){
        printf("\n1.Before\n2.After\n3.view\n4.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
                    printf("Enter the element to search : ");
                    scanf("%d",&info);
                    printf("Enter the value of num : ");
                    scanf("%d",&n);
                    before(n,info,head);
                    break;
            case 2 :
                    printf("Enter the element to search : ");
                    scanf("%d",&key);
                    printf("Enter the value of num : ");
                    scanf("%d",&num);
                    after(num,key,head);
                    break;
            case 3 : view();
                     break;
            case 4 : exit(0);
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
struct node *after(int num, int key, struct node *start) {
  struct node * cur = start;
  struct node *newnode;
  while ( cur->info != key) {
      cur = cur->link;
  }
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->info = num;
  newnode->link= cur->link;
  cur->link = newnode;
  return start;
}

struct node *before(int num, int key, struct node *head) {
struct node *cur = head;
struct node *newnode;
  while ( cur->link->info != key) {
    cur = cur->link;
  }
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->info = num;
  newnode->link= cur->link;
  cur->link = newnode;
return head;
}
