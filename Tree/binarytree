#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    struct Node* left;
    struct Node* right ;
};

struct Node* root=NULL;

struct Node* create(){
    char x;
    printf("Enter the data ( '#' for no node ):");
    scanf(" %c",&x);
    if(x=='#'){
        return NULL;}
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    printf("Enter the left node for node %c :\n",x);
    newnode->left=create();
    printf("Enter the right node for node %c :\n",x);
    newnode->right=create();
    return newnode;
    
    }
    
void preorder(struct Node* temp){
    if(temp==NULL){
        return ;}
    printf("%c ",temp->data);
    preorder(temp->left);
    preorder(temp->right);  
    }
     
void postorder(struct Node* temp){
    if(temp==NULL){
        return;}
    postorder(temp->left);
    postorder(temp->right);  
    printf("%c ",temp->data);
    } 
   
void inorder(struct Node* temp){
    if(temp==NULL){
        return ;}
    inorder(temp->left);
    printf("%c ",temp->data);
    inorder(temp->right); 
}
void main(){
    int n;
    printf("ENTER YOUR OPTION :\n1.CREATE\n2.PREORDER\n3.POSTORDER\n4.INORDER\n0.EXIT\n");
    printf("Enter :");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                root=create();
                break;
            case 2:
                printf("PREORDER : ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("POSTORDER : ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("INORDER : ");
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Pls enter a valid number !\n");
                break;
            }
            printf("Anything else ? Enter :");
            scanf("%d",&n);
         }
}
        
