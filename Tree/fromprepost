#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    };

struct Node* root=NULL;

struct Node* newnode(int k){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
    }
    

int pre[20];
int post[20];
int n,t;

struct Node* tree(int start , int end){
    if(start == end){
        struct Node* temp=newnode(pre[t++]);
        return temp;
        }
    else{
    int i,k=0;
    struct Node* temp=newnode(pre[t++]);
    if(t>=n){
        return temp;}
    for(i=start;i<=end;i++){
        if(pre[t]==post[i]){
            k=1;
            break;
            }
     }
     if(k!=0){
     if(i-1 < start){
        struct Node* temp1=newnode(pre[t++]);
        if(t>=n){
        return temp1;}
        temp->left=temp1;
        temp->right=tree(i+1,end);
        }
     else{
        temp->left=tree(start,i-1);
        temp->right=tree(i+1,end);
        }
     return temp;}
     else{
        return temp;}
        }
}
void inorder(struct Node* temp){
    if(temp==NULL){
        return ;}
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
    }

void main(){
    int i;
    printf("Enter the length :");
    scanf("%d",&n);
    printf("Enter the elements of preorder :\n");
    for(i=0;i<n;i++){
        scanf("%d",&pre[i]);
        }
    printf("Enter the elements of postorder :\n");
    for(i=0;i<n;i++){
        scanf("%d",&post[i]);
        }
    root=tree(0,n-1);
    printf("INORDER : ");
    inorder(root);
    printf("\n");
    }
