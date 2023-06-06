#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    };
    
struct Node* root=NULL;

int p[20];
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
        t--;
        return temp1;}
    else if(start < end){
        return NULL;}
    else{
    int i;
    for(i=start; i>=end ;i--){
        if(in[i]==p[t]){
            t--;
            break;}
       }
   struct Node* temp=newnode(in[i]);
   temp->right=tree(start,i+1);
   temp->left=tree(i-1,end);
   return temp;}
   }
             
void preorder(struct Node* temp){
    if(temp==NULL){
        return;
        }
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
    }
    

void main(){
    int j,n;
    printf("Enter the length of the input :");
    scanf("%d",&n);
    printf("Enter the postorder :\n");
    for(j=0;j<n;j++){
        scanf("%d",&p[j]);
        }
    printf("Enter the inorder :\n");
    for(j=0;j<n;j++){
        scanf("%d",&in[j]);
        }
    t=n-1;
    root=tree(n-1,0);
    printf("Preorder :");
    preorder(root);
    printf("\n");
    }
    
