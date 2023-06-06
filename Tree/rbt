/*RED BLACK TREE :
    it is a self balancing binary search tree
    it is roughly balancing tree while avl is strictly balancing tree
    RULES:
        root and null always be black
        two consecutive nodes can't be red
        from root to leaf all path should contain same no. of black nodes*/
        
#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define BLACK 1 


struct Node{
    int data;
    int colour;
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
    temp->colour=RED;
    return temp;
    }

struct Node* insert(struct Node* temp,struct Node* pt,int k){
    if(temp==NULL){
        struct Node* ptr=newnode(k);
        ptr->parent=pt;
        if(root==NULL){
            ptr->colour=BLACK;}
        checkptr=ptr;
        return ptr;
        }
    else if(temp->data > k){
        temp->left=insert(temp->left,temp,k);}
    else if(temp->data < k){
        temp->right=insert(temp->right,temp,k);}
    return temp;
    }

    
void leftrotation(struct Node* temp){
    struct Node* temp1=temp->left->right;
    if(temp->parent==NULL){
        root=temp->left;
        root->colour=BLACK;}
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
        root=temp->right;
        root->colour=BLACK;}
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
    
void check(struct Node* temp){
    if(temp->colour==BLACK || temp->parent==NULL || temp->parent->colour==BLACK){
        return;}
    else if(temp->parent->colour==RED){
        if(temp->parent->parent->right==temp->parent){
            if(temp->parent->parent->left==NULL || temp->parent->parent->left->colour==BLACK){
                if(temp->parent->right==temp){
                    checkptr=temp->parent;
                    temp->parent->colour=BLACK;
                    temp->parent->parent->colour=RED;
                    rightrotation(temp->parent->parent);
                    }
                else if(temp->parent->left==temp){
                    checkptr=temp;
                    temp->colour=BLACK;
                    temp->parent->parent->colour=RED;
                    leftrotation(temp->parent);
                    rightrotation(temp->parent);
                    }
              }         
            else if(temp->parent->parent->left->colour==RED){
                temp->parent->colour=BLACK;
                temp->parent->parent->left->colour=BLACK;
                if(temp->parent->parent!=root){ temp->parent->parent->colour=RED; }
                checkptr=temp->parent->parent;}
                }
         else if(temp->parent->parent->left==temp->parent){
            if(temp->parent->parent->right==NULL || temp->parent->parent->right->colour==BLACK){
                if(temp->parent->left==temp){
                    checkptr=temp->parent;
                    temp->parent->colour=BLACK;
                    temp->parent->parent->colour=RED;
                    leftrotation(temp->parent->parent);
                    }
                else if(temp->parent->right==temp){
                    checkptr=temp;
                    temp->colour=BLACK;
                    temp->parent->parent->colour=RED;
                    rightrotation(temp->parent);
                    leftrotation(temp->parent);
                    }
                }
            else if(temp->parent->parent->right->colour==RED){
                temp->parent->colour=BLACK;
                temp->parent->parent->right->colour=BLACK;
                if(temp->parent->parent!=root){ temp->parent->parent->colour=RED; }
                checkptr=temp->parent->parent;}
                }
          check(checkptr);
          }
     }
     
void delete(struct Node* temp,int k){
    if(temp==NULL) { printf("The element is not found\n"); }
    else if(temp->data > k) 
    {
        delete(temp->left,k);
    }
    else if(temp->data < k) 
    {
        delete(temp->right,k);
    }
    else{
        if(temp->left==NULL && temp->right==NULL){
            checkptr=temp;}
        else if(temp->left!=NULL && temp->right==NULL){
            temp->data=temp->left->data;
            checkptr=temp->left;}
        else if(temp->left==NULL && temp->right!=NULL){
            temp->data=temp->right->data;
            checkptr=temp->right;}
        else{
            struct Node* temp1=temp->left;
            struct Node* ptr=temp1;
            while(temp1->right!=NULL){
                if(temp1->right->right==NULL){
                    ptr=temp1->right;
                    break;}
               }
            temp->data=ptr->data;
            checkptr=ptr;
            if(ptr->left!=NULL){
                ptr->data=ptr->left->data;
                checkptr=ptr->left;}
            }
         if(checkptr==root){
            free(checkptr);
            root=NULL;
            return;}
         again:
         if(checkptr->parent->left==checkptr){
            if(checkptr->colour==RED){
                checkptr->parent->left=NULL;
                free(checkptr);
                return;}
            else if(checkptr->colour==BLACK){
                if(checkptr->parent->colour==BLACK){
                    if(checkptr->parent->right==NULL){
                        checkptr=checkptr->parent;
                        goto again;}
                    else if(checkptr->parent->right->colour==RED)
                    {
                        checkptr->parent->colour=RED;
                        checkptr->parent->right->colour=BLACK;
                        rightrotation(checkptr->parent);
                    }
                    else if(checkptr->parent->right->colour==BLACK){
                        if((checkptr->parent->right->left==NULL && checkptr->parent->right->right==NULL) ||
                            ((checkptr->parent->right->left!=NULL && checkptr->parent->right->left->colour==BLACK )&&       (checkptr->parent->right->right!=NULL && checkptr->parent->right->right->colour==BLACK)))
                        {
                            checkptr->parent->right->colour=RED;
                            checkptr=checkptr->parent;
                            free(checkptr->left);
                            checkptr->left=NULL;
                            if(checkptr!=root){goto again;}
                            else return;
                         }
                        else if((checkptr->parent->right->left!=NULL && checkptr->parent->right->left->colour==RED) && ((checkptr->parent->right->right==NULL) || (checkptr->parent->right->right->colour==BLACK)))
                        {
                            checkptr->parent->right->colour=RED;
                            checkptr->parent->right->left->colour=BLACK;
                            leftrotation(checkptr->parent->right);
                        }
                        if(checkptr->parent->right->right!=NULL)
                        {
                            if(checkptr->parent->right->right->colour==RED)
                            {
                                checkptr->parent->right->right->colour=BLACK;
                                rightrotation(checkptr->parent);
                            }
                        }
                    }
                 }                   
                else if(checkptr->parent->colour==RED){
                    if(checkptr->parent->right==NULL){
                        checkptr->parent->colour=BLACK;
                        }
                    else{
                        if((checkptr->parent->right->left==NULL && checkptr->parent->right->right==NULL) ||
                           ((checkptr->parent->right->left!=NULL && checkptr->parent->right->left->colour==BLACK)&& 
                           (checkptr->parent->right->right!=NULL && checkptr->parent->right->right->colour==BLACK)))
                        {
                               checkptr->parent->right->colour=RED;
                               checkptr->parent->colour=BLACK;
                        }
                        else if((checkptr->parent->right->left!=NULL && checkptr->parent->right->left->colour==RED) && 
                        (checkptr->parent->right->right!=NULL && checkptr->parent->right->right->colour==BLACK))
                        {
                            checkptr->parent->right->left->colour=BLACK;
                            checkptr->parent->right->colour=RED;
                            leftrotation(checkptr->parent->right);
                        }
                        if(checkptr->parent->right->right!=NULL){
                            if(checkptr->parent->right->right->colour==RED)
                            {
                              checkptr->parent->right->right->colour=BLACK;
                              checkptr->parent->colour=BLACK;
                              checkptr->parent->right->colour=RED;
                              rightrotation(checkptr->parent);
                        }}
                        }
                   }
               checkptr->parent->left=NULL;
               free(checkptr);
               return;
               }
         }
         else if(checkptr->parent->right==checkptr){ 
            if(checkptr->colour==RED){
                checkptr->parent->right=NULL;
                free(checkptr);
                return;}
            else if(checkptr->colour==BLACK){
                if(checkptr->parent->colour==BLACK){
                    if(checkptr->parent->left==NULL){
                        checkptr=checkptr->parent;
                        goto again;}
                    else if(checkptr->parent->left->colour==RED)
                    {
                        checkptr->parent->colour=RED;
                        checkptr->parent->right->colour=BLACK;
                        leftrotation(checkptr->parent);
                    }
                    else if(checkptr->parent->left->colour==BLACK){
                        if((checkptr->parent->left->left==NULL && checkptr->parent->left->right==NULL) ||
                            ((checkptr->parent->left->left!=NULL && checkptr->parent->left->left->colour==BLACK ) && (checkptr->parent->left->right!=NULL && checkptr->parent->left->right->colour==BLACK)))
                        {
                            checkptr->parent->left->colour=RED;
                            checkptr=checkptr->parent;
                            free(checkptr->right);
                            checkptr->right=NULL;
                            if(checkptr!=root) {goto again;}
                            else return;
                         }
                        else if((checkptr->parent->left->left!=NULL && checkptr->parent->left->left->colour==BLACK) && 
                        (checkptr->parent->left->right!=NULL && checkptr->parent->left->right->colour==RED))
                        {
                            checkptr->parent->left->colour=RED;
                            checkptr->parent->left->right->colour=BLACK;
                            rightrotation(checkptr->parent->left);
                        }
                        if(checkptr->parent->left->right!=NULL)
                        {
                            if(checkptr->parent->left->right->colour==RED)
                            {
                                checkptr->parent->left->right->colour=BLACK;
                                leftrotation(checkptr->parent);
                            }
                         }
                    }
                 }                   
                else if(checkptr->parent->colour==RED){
                    if(checkptr->parent->left==NULL){
                        checkptr->parent->colour=BLACK;
                        }
                    else{
                        if((checkptr->parent->left->left==NULL && checkptr->parent->left->right==NULL) ||
                           ((checkptr->parent->left->left!=NULL && checkptr->parent->left->left->colour==BLACK) && 
                           (checkptr->parent->left->right!=NULL && checkptr->parent->left->right->colour==BLACK)))
                        {
                               checkptr->parent->left->colour=RED;
                               checkptr->parent->colour=BLACK;
                        }
                        else if(((checkptr->parent->left->left==NULL) || (checkptr->parent->left->left->colour==BLACK))&&      checkptr->parent->left->right->colour==RED)
                        {
                            checkptr->parent->left->right->colour=BLACK;
                            checkptr->parent->left->colour=RED;
                            rightrotation(checkptr->parent->left);
                        }
                        if(checkptr->parent->left->left!=NULL)
                        {
                            if(checkptr->parent->left->left->colour==RED)
                            {
                                checkptr->parent->left->left->colour=BLACK;
                                checkptr->parent->colour=BLACK;
                                checkptr->parent->left->colour=RED;
                                leftrotation(checkptr->parent);
                            }
                        }
                       }
                   }
               checkptr->parent->right=NULL;
               free(checkptr);
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
    printf("%u - %d - %u - %u - %s\n",temp->left,temp->data,temp->right,temp->parent,temp->colour ? "BLACK" : "RED");
    print(temp->left);
    print(temp->right);}              
        

void main(){
    int k,n;
    printf("RED BLACK TREE :\n 1.INSERTION\n 2.DELETION\n 0.EXIT\n");
    printf("Enter your option : ");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&k);
                root=insert(root,NULL,k);
                check(checkptr);
                printf("Root->data %d\n",root->data);
                print(root);
                break;
            case 2:
                printf("Enter the element to be deleted : ");
                scanf("%d",&k);
                delete(root,k);
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
