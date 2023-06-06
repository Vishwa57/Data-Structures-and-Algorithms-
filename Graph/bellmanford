// Adjacency List graph representation
// Single Source Shortest path Algorithm
// Bellman Ford Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;

struct str
{
    char vertex;
    int flag;
    struct str* next;
};

struct str* root=NULL;

void insert(char ch)
{  
    struct str* temp=(struct str*)malloc(sizeof(struct str));
    temp->vertex=ch;
    temp->flag=65536;
    temp->next=NULL;
    if(root==NULL) 
        root=temp;
    else
    {
        struct str* temp1=NULL;
        for(temp1=root;temp1->next!=NULL;temp1=temp1->next);
        temp1->next=temp;
    }
}
        
struct Node
{
    char vertex;
    int cost;
    struct Node* next;
};

struct Node* ptr[15]={NULL};
struct Node* sp[15]={NULL};

struct Node* newnode(char ch , int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->vertex=ch;
    temp->cost=value;
    temp->next=NULL;
    return temp;
}

void push(int k , char ch , int value,int h)
{
    struct Node* temp1=NULL;
    if(h==1)
        temp1=ptr[k];
    else
        temp1=sp[k];
    if(temp1==NULL)
    {
        temp1=newnode(ch,value);
        if(h==1)
            ptr[k]=temp1;
        else
            sp[k]=temp1;
    }
    else
    {
        struct Node* temp=temp1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode(ch,value);
    }
}

void pop(int k)
{
    struct Node* temp=NULL;
    struct Node* temp1=NULL;
    for(temp=sp[k];temp!=NULL;)
    {
        temp1=temp->next;
        free(temp);
        temp=temp1;
    }
    sp[k]=NULL;
    return;
}

void del(char start, char value,int k)
{
    struct Node* temp=NULL;
    if(ptr[start-65]->vertex==value && ptr[start-65]->cost==k)
    {
        temp=ptr[start-65];
        ptr[start-65]=ptr[start-65]->next;
        free(temp);
        return;
    }
    else
    {
        struct Node* temp1=NULL;
        temp=ptr[start-65];
        while(temp->next!=NULL)
        {
            if(temp->next->vertex==value)
            {
                if(temp->next->cost==k)
                    break;
            }
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);
        return;
    }
    
}
    

void clear()
{
    char set[10];
    int setv[10];
    int l,k;
    struct str* temp=NULL;
    struct Node* temp1=NULL;
    struct Node* temp2=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        l=0;
        k=0;
        set[0]='\0';
        for(temp1=ptr[temp->vertex-65];temp1!=NULL;)
        {   
            if(temp->vertex == temp1->vertex)
            {
               del(temp->vertex,temp1->vertex,temp1->cost);
               temp1=ptr[temp->vertex-65];
            }
            else 
            {
               if(l!=0) k=(int)(strchr(set,temp1->vertex)-set); 
               if(strchr(set,temp1->vertex)!=NULL)
               {
                   if(setv[k] < temp1->cost)
                   {
                       temp2=temp1->next;
                       del(temp->vertex,temp1->vertex,temp1->cost);
                       temp1=temp2;
                   }
                   else
                   {
                       del(temp->vertex,temp1->vertex,setv[k]);
                       setv[k]=temp1->cost;
                       temp1=temp1->next;
                   }
               }
               else
               {
                   set[l]=temp1->vertex;
                   set[l+1]='\0';
                   setv[l]=temp1->cost;
                   l++;
                   temp1=temp1->next;
               }
            }
         }
     }
}

void shortpath(char ch)
{
    int m,t=0,i;
    struct Node* temp1=NULL;
    struct str* temp2=NULL;
    struct str* temp3=NULL;
    struct Node* temp4=NULL;
    for(i=1;i<n;i++)
    {
        for(temp2=root;temp2!=NULL;temp2=temp2->next)
        {
            for(temp1=ptr[temp2->vertex-65];temp1!=NULL;temp1=temp1->next)
            {
                 for(temp3=root;temp3!=NULL;temp3=temp3->next)
                 {
                    if(temp3->vertex==temp1->vertex)
                        break;
                 }
                 if(temp2->flag+temp1->cost < temp3->flag)
                 {
                    temp3->flag=temp2->flag+temp1->cost;
                        pop(temp3->vertex-65);
                    for(temp4=sp[temp2->vertex-65];temp4!=NULL;temp4=temp4->next)
                    {
                         push(temp3->vertex-65,temp4->vertex,1,2);
                    }
                    push(temp3->vertex-65,temp3->vertex,1,2);
                 }
            }
        }
    }
                            
}

void main()
{
    int i,k,j,m;
    char start,end;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insert(i+65);
    }
    printf("To create the links Press 1 ( else 0 ) :");
    scanf("%d",&k);
    printf("Is it weighted graph ? if yes , Press 1 else 0 :");
    scanf("%d",&j);
    printf("Is it directed graph ? if yes , Press 1 else 0 :");
    scanf("%d",&m);
    i=1;
    while(k)
    {
        printf("Enter the edge between vertices!\n");
        printf("Enter the starting vertex :");
        scanf(" %c",&start);
        printf("Enter the ending vertex :");
        scanf(" %c",&end);
        if(j)
        {
            printf("Enter the cost of the edge :");
            scanf("%d",&i);
        }
        push(start-65,end,i,1);
        if(m==0) push(end-65,start,i,1);
        printf("Any further links ? if yes Press 1 , else 0 :");
        scanf("%d",&k);
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    struct Node* temp=NULL;
    struct str* temp1=root;
    for(i=0;i<n;i++)
    {
        printf("%c\t",temp1->vertex);
        temp1=temp1->next;
        for(temp=ptr[i];temp!=NULL;temp=temp->next)
        {
            printf("%c , %d\t",temp->vertex,temp->cost);
        }
        printf("\n");
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    clear();
    printf("Enter the source : ");
    scanf(" %c",&start);
    temp1=root;
    while(temp1!=NULL)
    {
        push(temp1->vertex-65,start,1,2);
        if(temp1->vertex!=start)
            push(temp1->vertex-65,temp1->vertex,1,2);
        temp1=temp1->next;
    }
    for(temp1=root;temp1!=NULL;temp1=temp1->next)
    {
        if(temp1->vertex==start)
        {
            temp1->flag=0;
            break;
        }
    }
    shortpath(start);
    printf("VERTEX\t\tCOST FORM SOURCE\n");
    for(temp1=root;temp1!=NULL;temp1=temp1->next)
    {
        printf("%c     \t\t%d\n",temp1->vertex,temp1->flag);
    }
    printf("\n");
    printf("Shortest Path from %c !\n",start);
    temp1=root;
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    temp1=root;
    for(i=0;i<n;i++)
    {
        printf("%c\t",temp1->vertex);
        temp1=temp1->next;
        for(temp=sp[i];temp!=NULL;temp=temp->next)
        {
            printf("%c \t",temp->vertex);
        }
        printf("\n");
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    
} 
