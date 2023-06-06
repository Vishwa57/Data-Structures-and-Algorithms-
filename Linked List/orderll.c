#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    };
    
struct Node* head=NULL;
struct Node* tail=NULL;

void push(){
    struct Node* newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the element :");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=tail=newnode;
        newnode->next=NULL;
        }
    else{
        if(newnode->data < head->data){
            newnode->next=head;
            head=newnode;
            }
        else{
            if(newnode->data >= tail->data){
                tail->next=newnode;
                tail=newnode;
                }
            else{
                struct Node* temp=NULL;
                for(temp=head;temp->next->data < newnode->data;temp=temp->next);
                newnode->next=temp->next;
                temp->next=newnode;
                }
            }
       }
}

void print(){
    struct Node* temp=NULL;
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
        }
    printf("\n");
    }

void main(){
    int n;
    printf("Enter the option :\n1.PUSH\n0.EXIT\n");
    scanf("%d",&n);
    while(n){
           push();
           print();
           printf("Anything else ? :");
           scanf("%d",&n);
           }
           }

       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
