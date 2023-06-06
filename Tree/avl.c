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


struct Node* newnode(int k){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=k;
    temp->left=temp->right=temp->parent=NULL;
    return temp;}

struct Node* insert(struct Node* temp,struct Node* pt,int k){
    if(temp==NULL){
        struct Node* temp1=newnode(k);
        temp1->parent=pt;
        checkptr=temp1;
        return temp1;}
    else if(temp->data >= k){
        temp->left=insert(temp->left,temp,k);}
    else if(temp->data < k){
        temp->right=insert(temp->right,temp,k);}
    return temp;
    }

void checkdel(struct Node* );
   
struct Node* delete(struct Node* temp,int k){
    if(temp->data == k){
        checkptr=temp->parent;
        struct Node* ptr=NULL;
        if(temp->left==NULL && temp->right==NULL){
            free(temp);
            return NULL;
            }
        else if(temp->left!=NULL && temp->right==NULL){
            ptr=temp->left;
            ptr->parent=temp->parent;
            free(temp);
            return ptr;
            }
        else if(temp->left==NULL && temp->right!=NULL){
            ptr=temp->right;
            ptr->parent=temp->parent;
            free(temp);
            return ptr;
            }
        else{
            struct Node* temp1=temp->left;
            ptr=temp1;
            while(temp1->right!=NULL){
                if(temp1->right->right==NULL){
                    ptr=temp1->right;
                    ptr->left=temp->left;
                    temp1->right=temp1->right->left;
                    break;
                }
                temp1=temp1->right;
             }
             ptr->parent=temp->parent;
             ptr->right=temp->right;
             ptr->right->parent=ptr;
             if(ptr->left!=NULL){ ptr->left->parent=ptr; }
             checkptr=ptr;
             free(temp);
             return ptr; 
            } 
    }
    else if(temp->data > k){
        temp->left=delete(temp->left,k);}
    else if(temp->data < k){
        temp->right=delete(temp->right,k);}
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
    temp->right=temp1;
    }
    
    
int Max(int a,int b){
    return a>=b ? a : b;}
    
int h(struct Node* temp){
    if(temp==NULL){
        return -1;}
    return Max(h(temp->left),h(temp->right))+1;}
    
int balance(struct Node* temp){
    return h(temp->left)-h(temp->right);}
    
void checkins(struct Node* temp,struct Node* child){
    if(temp==NULL){
        return ;}
    else if(balance(temp)<2 && balance(temp)>-2){
        checkins(temp->parent,temp);}
    else{
        if(balance(temp)>1 && balance(child)>0){
            leftrotation(temp);}
        else if(balance(temp)>1 && balance(child)<0){
            rightrotation(child);
            leftrotation(temp);}
        else if(balance(temp)<-1 && balance(child)<0){
            rightrotation(temp);}
        else if(balance(temp)<-1 && balance(child)>0){
            leftrotation(child);
            rightrotation(temp);}
        }      
     }
     
void checkdel(struct Node* temp){
    if(balance(temp)>-2 && balance(temp)<2){
        return;}
    else{
        if(balance(temp)>1){
            if(balance(temp->left)>0){
                leftrotation(temp);}
            else{
                rightrotation(temp->left);
                leftrotation(temp);}
            }
        else{
            if(balance(temp->right)<0){
                rightrotation(temp);}
            else{
                leftrotation(temp->right);
                rightrotation(temp);}
            } 
         }
}   
     
void print(struct Node* temp){
    if(temp==NULL){
        return;}
    printf(" %d , %d \n",temp->data,balance(temp));
    print(temp->left);
    print(temp->right);
    }     
    
    
int main(){
    int n,k;
    printf("AVL TREE :\n 1.INSERTION\n 2.DELETION\n 0.EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                printf("Enter the data to be inserted : ");
                scanf("%d",&k);
                root=insert(root,NULL,k);
                checkins(checkptr,NULL);
                print(root);
                break;
            case 2:
                printf("Enter the data to be deleted : ");
                scanf("%d",&k);
                root=delete(root,k);
                struct Node* ptr=checkptr;
                struct Node* ptr1=NULL;
                while(ptr!=NULL){
                    ptr1=ptr->parent;
                    checkdel(ptr);
                    ptr=ptr1;
                    }
                print(root);
                break;
            default:
                printf("Pls Enter a valid number!\n");
                break;
            }
            printf("Anything else ? Enter :");
            scanf("%d",&n);
         }
   }      
