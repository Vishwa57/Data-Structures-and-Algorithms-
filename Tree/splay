#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    };

struct Node* root=NULL;
struct Node* checkptr=NULL;
void print(struct Node*);
struct Node* newnode(int k){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=k;
    temp->left=temp->right=temp->parent=NULL;
    return temp;
    }

    
void leftrotation(struct Node* temp){
    struct Node* temp1=temp->left->right;
    if(temp->parent==NULL){
        root=temp->left;}
    else if(temp->parent->left==temp){
        temp->parent->left=temp->left;}
    else if(temp->parent->right==temp){
        temp->parent->right=temp->left;}
    temp->left->parent=temp->parent;
    temp->parent=temp->left;
    if(temp1!=NULL){ temp1->parent=temp; }
    temp->left->right=temp;
    temp->left=temp1;
    }
    
void rightrotation(struct Node* temp){
    struct Node* temp1=temp->right->left;
    if(temp->parent==NULL){
        root=temp->right;}
    else if(temp->parent->left==temp){
        temp->parent->left=temp->right;}
    else if(temp->parent->right==temp){
        temp->parent->right=temp->right;}
    temp->right->parent=temp->parent;
    temp->parent=temp->right;
    if(temp1!=NULL){ temp1->parent=temp; }
    temp->right->left=temp; 
    if(temp->right->left!=NULL)
    temp->right=temp1;
    }
    
struct Node* insert(struct Node* temp,struct Node* pt,int k){
    if(temp==NULL){
        struct Node* ptr=newnode(k);
        ptr->parent=pt;
        checkptr=ptr;
        return ptr;
        }
    else if(temp->data > k){
        temp->left=insert(temp->left,temp,k);}
    else if(temp->data < k){
        temp->right=insert(temp->right,temp,k);}
    return temp;
    }  

    
void splay(struct Node* temp){
    if(temp->parent!=NULL)
    {
        if(temp->parent->parent==NULL)
        {
            if(temp->parent->left==temp){ leftrotation(temp->parent);}
            else if(temp->parent->right==temp){ 
            rightrotation(temp->parent);}
        }
        else if(temp->parent->parent!=NULL)
        {
            if(temp->parent->parent->left==temp->parent)
            {
                if(temp->parent->left==temp)
                {
                    leftrotation(temp->parent->parent);
                    leftrotation(temp->parent);
                }
                else if(temp->parent->right==temp)
                {
                    rightrotation(temp->parent);
                    leftrotation(temp->parent);
                }
             }
             else if(temp->parent->parent->right==temp->parent)
             {
                if(temp->parent->left==temp)
                {
                    leftrotation(temp->parent);
                    rightrotation(temp->parent);
                }
                else if(temp->parent->right==temp)
                {
                    rightrotation(temp->parent->parent);
                    rightrotation(temp->parent);
                }
             }
          }
          
      }
      if(temp!=root) splay(temp);
      return;
  }
  
void bottomupdel(struct Node* temp,int k){
    if(temp==NULL) return;
    else if(temp->data == k){
        checkptr=temp->parent; 
        if(temp->left==NULL && temp->right==NULL){
            if(temp->parent==NULL) root=NULL;
            else if(temp->parent->left==temp) temp->parent->left=NULL;
            else if(temp->parent->right==temp) temp->parent->right=NULL;
            free(temp);
            }
        else if(temp->left!=NULL && temp->right==NULL){
            if(temp->parent==NULL) root=temp->left;
            else if(temp->parent->left==temp) temp->parent->left=temp->left;
            else if(temp->parent->right==temp) temp->parent->right=temp->left;
            temp->left->parent=temp->parent;
            free(temp);
            }
        else if(temp->left==NULL && temp->right!=NULL){
            if(temp->parent==NULL) root=temp->right;
            else if(temp->parent->left==temp) temp->parent->left=temp->right;
            else if(temp->parent->right==temp) temp->parent->right=temp->right;
            temp->right->parent=temp->parent;
            free(temp);
            }
        else{
            struct Node* temp1=temp->left;
            struct Node* ptr=temp1;
            while(temp1->right!=NULL){
                if(temp1->right->right==NULL){
                    ptr=temp1->right;
                    temp1->right=temp1->right->left;
                    ptr->left=temp->left;
                    break;
                }
                temp1=temp1->right;
             }
             if(temp->parent==NULL) root=ptr;
             else if(temp->parent->left==temp) temp->parent->left=ptr;
             else if(temp->parent->right==temp) temp->parent->right=ptr;
             ptr->parent=temp->parent;
             ptr->right=temp->right;
             ptr->right->parent=ptr;
             if(ptr->left!=NULL){ ptr->left->parent=ptr; }
             free(temp);
            } 
        if(checkptr!=NULL) splay(checkptr);
    }
    else if(temp->data > k)
    {
        if(temp->left==NULL) 
        {
            printf("The data is not found in the tree\n");
            splay(temp);
            return;
        }
        bottomupdel(temp->left,k);
    }
    else if(temp->data < k)
    {
        if(temp->right==NULL)
        {
            printf("The data is not found in the tree\n");
            splay(temp);
            return;
        }
        bottomupdel(temp->right,k);
    }
    return;
    } 



   
void topdowndel(struct Node* temp,int k){
    if(temp==NULL) return;
    else 
    {
        if(temp->data > k)
        {
            if(temp->left==NULL)
            {
                printf("The data is not found in the tree\n");
                splay(temp);
                return;
            }
            topdowndel(temp->left,k);
        }
        else if(temp->data < k)
        {
            if(temp->right==NULL)
            {
                printf("The data is not found in the tree\n");
                splay(temp);
                return;
            }
            topdowndel(temp->right,k);
        }
        else if(temp->data == k)
        {
            splay(temp);
            struct Node* head=root;
            struct Node* p1=root->left;
            struct Node* q1=root->right;
            if(p1==NULL && q1==NULL)
            {
                free(head);
                root=NULL;
                return;
            }
            else if(p1==NULL && q1!=NULL)
            {
                free(head);
                root=q1;
                q1->parent=NULL;
                return;
            }
            else if(p1!=NULL){
            struct Node* temp1=root->left;
            struct Node* ptr=root->left;
            p1->parent=NULL;
            root=p1;
            while(temp1->right!=NULL)
            {
                if(temp1->right->right==NULL)
                {
                    ptr=temp1->right;
                    break;
                }
                temp1=temp1->right;
            }
            splay(ptr);
            ptr->right=q1;
            if(q1!=NULL) q1->parent=ptr;
            free(head);
            return;
            }
       }
    }
 }
     
            
     
void print(struct Node* temp){
    if(temp==NULL){
        if(root==NULL){
            printf("TREE IS EMPTY\n");}
        return;}
    printf("%u - %d - %u - %u\n",temp->left,temp->data,temp->right,temp->parent);
    print(temp->left);
    print(temp->right);}              
        

void main(){
    int k,n,m;
    printf("SPLAY TREE :\n 1.INSERTION\n 2.DELETION\n 0.EXIT\n");
    printf("Enter your option : ");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&k);
                root=insert(root,NULL,k);
                splay(checkptr);
                printf("Root->data %d\n",root->data);
                print(root);
                break;
            case 2:
                printf("Enter the element to be deleted : ");
                scanf("%d",&k);
                printf("In which method? 1.Topdown 2.bottomup\n");
                printf("Enter :");
                scanf("%d",&m);
                if(m==1) topdowndel(root,k);
                else bottomupdel(root,k);
                print(root);
                break;
            default:
                printf("Pls enter a valid number!\n");
                break;
            }
            printf("Anything else ? Enter : ");
            scanf("%d",&n);
      }
}
