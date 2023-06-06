/*tree traversal:
    breadth first traversal : -->levelorder traversal
                                (print the node values level by level)
    depth first traversal : --> preorder(root,left,right)
                            -->postorder(left,right,root)
                            -->inorder(left,root,right)*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    struct Node* ptr;
    struct Queue* next;
};

struct Node* root=NULL;
struct Queue* head=NULL;
struct Queue* tail=NULL;

void push(struct Node* temp){
    struct Queue* temp1=(struct Queue*)malloc(sizeof(struct Queue));
    temp1->ptr=temp;
    temp1->next=NULL;
    if(head==NULL){
        head=tail=temp1;
        }
    else{
        tail->next=temp1;
        tail=tail->next;
        }
}

struct Node* pop(){
    if(head==NULL){
        return NULL;}
    else{
        struct Queue* temp=NULL;
        temp=head;
        head=head->next;
        free(temp);
        if(head==NULL){ return NULL;}
        return head->ptr;
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

void print(struct Node* temp){
    if(temp==NULL){
        return ;
        }
    printf("%d ",temp->data);
    if(temp->left!=NULL){
        push(temp->left);}
    if(temp->right!=NULL){
        push(temp->right);}
    print(pop());
    }
    
    
void main(){
    printf("Enter the Nodes of the tree :\n");
    root=tree();
    push(root);
    printf("Level order traversal : ");
    print(root);
    printf("\n");
    } 
