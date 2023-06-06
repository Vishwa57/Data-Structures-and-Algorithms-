// Adjacency List graph representation
// Minimum Spanning Tree
// Prims Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char mstset[16];
int length;

struct str
{
    char vertex;
    int key;
    int flag;
    char change;
    struct str* next;
};

struct str* root=NULL;

void insert(char ch)
{
    struct str* temp=(struct str*)malloc(sizeof(struct str));
    temp->vertex=ch;
    temp->key=65536;
    temp->flag=0;
    temp->change='\0';
    temp->next=NULL;
    if(root==NULL) root=temp;
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
    int flag;
    struct Node* next;
};

struct Node* ptr[15]={NULL};

struct Node* newnode(char ch , int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->vertex=ch;
    temp->cost=value;
    temp->flag=0;
    temp->next=NULL;
    return temp;
}

void push(int k , char ch , int value)
{
    if(ptr[k]==NULL)
    {
        ptr[k]=newnode(ch,value);
    }
    else
    {
        struct Node* temp=ptr[k];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode(ch,value);
    }
}

struct str* check(char ch)
{
    struct str* temp=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        if(temp->vertex==ch)
        {   
            return temp;
        }
    }
}

char small()
{
    int s=65536;
    char ch='\0';
    struct str* temp=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        if(temp->flag==0)
        {
            if(temp->key < s)
            {
                s=temp->key;
                ch=temp->vertex;
             }
         }
     }
     return ch;
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

void deletion()
{
    struct str* temp=NULL;
    struct Node* temp1=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        for(temp1=ptr[temp->vertex-65];temp1!=NULL;temp1=temp1->next)
        {
            if(temp1->flag == 0)
            {
                del(temp->vertex,temp1->vertex,temp1->cost);
            }
        }
    }
}

void fc()
{
    
    struct str* temp=NULL;
    struct Node* temp1=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        if(temp->change!='\0')
        {   
            for(temp1=ptr[temp->vertex-65];temp1!=NULL;temp1=temp1->next)
            {   
                if(temp1->vertex == temp->change)
                {
                temp1->flag=1;
                break;
                 }
            }
            for(temp1=ptr[temp->change-65];temp1!=NULL;temp1=temp1->next)
            {   
                if(temp1->vertex == temp->vertex)
                {
                    temp1->flag=1;
                    break;
                }
            }
       }
     }
}
    

void mst(char ch)
{
    char s;
    struct str* temp=check(ch);
    temp->flag=1;
    if(ch==root->vertex)    temp->key=0;
    mstset[length]=ch;
    length++;
    struct Node* temp1=NULL;
    for(temp1=ptr[ch-65];temp1!=NULL;temp1=temp1->next)
    {
        temp=check(temp1->vertex);
        if((temp->key > temp1->cost) && (temp->flag==0))
        {
            struct Node* temp2=NULL;
            temp->key=temp1->cost;
            temp->change=ch;
        }
    }
    s=small();
    if(s!='\0') mst(s);
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
                
                    
    

void main()
{
    int n,i,k,j,m;
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
        push(start-65,end,i);
        if(m==0 && start!=end) push(end-65,start,i);
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
            printf("%c , %d \t",temp->vertex,temp->cost);
        }
        printf("\n");
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    clear();//it removes all selfloops and parallel edges
    mst(root->vertex);
    printf("Vertices----Keys----Change\n");
    for(temp1=root;temp1!=NULL;temp1=temp1->next)
    {   
        printf("%c           %d       %c\n",temp1->vertex,temp1->key,temp1->change);
    }
    printf("MST_SET : ");
    for(i=0;i<length;i++){
        printf("%c ",mstset[i]);}
    printf("\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    fc();
    deletion();
    temp1=root;
    for(i=0;i<n;i++)
    {
        printf("%c\t",temp1->vertex);
        temp1=temp1->next;
        for(temp=ptr[i];temp!=NULL;temp=temp->next)
        {
            if(temp!=NULL)
                printf("%c , %d \t",temp->vertex,temp->cost);
        }
        printf("\n");
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); 
} 
