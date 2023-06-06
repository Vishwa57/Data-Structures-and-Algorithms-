#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    int data;
    struct Queue* next;
};

struct Node* root=NULL;
struct Queue* head=NULL;
struct Queue* tail=NULL;

void push(int d){
    struct Queue* temp1=(struct Queue*)malloc(sizeof(struct Queue));
    temp1->data=d;
    temp1->next=NULL;
    if(head==NULL){
        head=tail=temp1;
        }
    else{
        tail->next=temp1;
        tail=tail->next;
        }
}

  
struct Node* tree(){
    int x;
    printf("Enter the data (-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
        }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    printf("Enter the left node of %d\n ",x);
    temp->left=tree();
    printf("Enter the right node of %d\n ",x);
    temp->right=tree();
    return temp;
}

int isbst(){
    struct Queue* temp=head;
    while(temp->next!=NULL){
        if(temp->data < temp->next->data){
             temp=temp->next;}
        else{
            return 0;}
     }
    return 1;  
}    

void inorder(struct Node* temp){ 
    if(temp==NULL){
        return ;}
    inorder(temp->left);
    push(temp->data);
    printf("%d ",temp->data);
    inorder(temp->right);
    }
    
    
void main(){
    printf("Enter the Nodes of the tree :\n");
    root=tree();
    if(root!=NULL){
        printf("Inorder traversal : ");
        inorder(root);
        printf("\n");
        if(isbst())
            printf("It is binary search tree\n");
        else
            printf("It is not a binary search tree\n");
        }
    else 
        printf("Tree is empty\n");
}    

