/* Binary search tree:
    For each node , the left subtree should contain values lesser than or equal to the node value and right sub tree should contain the values greater than the node value .
    deletion :
        may be node contain 0 child ,1 child ,2 children !
        if two children :
            -> inorder predecessor method ( node should be replaced with largest value in the left subtree )
            -> inorder successor method ( node should be replaced with smallest value in the right subtree )*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    };

struct Node* root=NULL;
struct Node* ptr=NULL;

struct Node* newnode(int k)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=k;
    temp->left=temp->right=NULL;
    return temp;
}

struct Node* insert(struct Node* temp,int k){
    if(temp==NULL){
        struct Node* temp1=newnode(k);
        return temp1;
        }
    else if(temp->data >= k){
        temp->left=insert(temp->left,k);
        }
    else if(temp->data < k){
        temp->right=insert(temp->right,k);
        }
    return temp;
}

struct Node* delete(struct Node* temp,int k){
    if(temp==NULL){
        printf("The data is not found !\n");
        }
    else{
    if(temp->data == k){
        if(temp->left == NULL && temp->right == NULL){
            free(temp);
            return NULL;}
        else if(temp->left == NULL && temp->right != NULL){
            ptr=temp->right;
            free(temp);
            return ptr;
         }
         else if(temp->right == NULL && temp->left!=NULL){
            ptr=temp->left;
            free(temp);
            return ptr;
            }
         //Inorder predecessor method 
         else{
              struct Node* temp1=NULL;
              struct Node* ptr2=temp->left;
              int m=0;
              ptr=temp->left;
              temp1=ptr;
              while(ptr->right!=NULL){
                   m=1;
                   if(ptr->right->right==NULL){
                       temp1=ptr->right;
                       ptr->right=NULL;
                       break;
                      }
                      ptr=ptr->right;
                   }
                   temp1->right=temp->right;
                   if(temp1->left!=NULL){
                        while(temp1->left!=NULL){
                            temp1=temp1->left;}
                        }
                   if(m!=0){
                   temp1->left=ptr2;}
                   free(temp);
                   return temp1;
                    }
             }
    else if(temp->data > k){  
        temp->left=delete(temp->left,k);
        }
    else if(temp->data < k){
        temp->right=delete(temp->right,k);
        }}
    return temp;
}   

void search(struct Node* temp,int m){
    if(temp==NULL)
        printf("The element is not found\n");
    else if(temp->data==m)
        printf("The element is found \n");
    else{
        if(temp->data > m)
            search(temp->left,m);
        else if(temp->data < m)
            search(temp->right,m);
         }
}

int max(int p,int q){
    return (p>q) ? p : q;}

int height(struct Node* temp){
    if(temp==NULL){
        return -1;
        }
    return max(height(temp->left),height(temp->right))+1;
}
    
    
void print(struct Node* temp){
    if(root==NULL){
        printf("Tree is empty ");
    }
    else{
     if(temp==NULL){
          return ;}
     print(temp->left);
     printf("%d ",temp->data);
     print(temp->right);
    }
}

void main(){
    int n,k;
    printf("TREE :\n 1.INSERT\n 2.DELETE\n 3.SEARCH\n 4.HEIGHT OF THE TREE\n 0.EXIT\n");
    printf("\nENTER :");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                printf("Enter the data to be inserted : ");
                scanf("%d",&k);
                root=insert(root,k);
                print(root);
                break;
            case 2:
                printf("Enter the data to be deleted : ");
                scanf("%d",&k);
                root=delete(root,k);
                print(root);
                break;
            case 3:
                printf("Enter the element to be searched : ");
                scanf("%d",&k);
                search(root,k);
                print(root);
                break;
            case 4:
                k=height(root);
                printf("The height of the tree is : %d \n",k);
                break;
            default:
                printf("Pls Enter a valid Number !\n");
                break;
                }
            printf("\nAnything else ? Enter :");
            scanf("%d",&n);
            }
}
                
