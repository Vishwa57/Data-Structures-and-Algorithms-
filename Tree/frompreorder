#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    };
    
struct Node* root=NULL;

int pre[20];
int in[20];
int t;

struct Node* newnode(int k){
    struct Node* temp=NULL;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;}

struct Node* tree(int start,int end){
    if(start==end){
        struct Node* temp1=newnode(in[start]);
        t++;
        return temp1;}
    else if(start > end){
        return NULL;}
    else{
    int i;
    for(i=start; i<=end ;i++){
        if(in[i]==pre[t]){
            t++;
            break;}
       }
   struct Node* temp=newnode(in[i]);
   temp->left=tree(start,i-1);
   temp->right=tree(i+1,end);
   return temp;}
   }
             
void postorder(struct Node* temp){
    if(temp==NULL){
        return;
        }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
    }
    

void main(){
    int j,n;
    printf("Enter the length of the input :");
    scanf("%d",&n);
    printf("Enter the preorder :\n");
    for(j=0;j<n;j++){
        scanf("%d",&pre[j]);
        }
    printf("Enter the inorder :\n");
    for(j=0;j<n;j++){
        scanf("%d",&in[j]);
        }
    root=tree(0,n-1);
    printf("Postorder :");
    postorder(root);
    printf("\n");
    }
    
