// Adjacency List graph representation
// Depth First Search graph traversal

#include<stdio.h>
#include<stdlib.h>


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
    temp->flag=0;
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
    struct Node* next;
};

struct Node* ptr[15]={NULL};

struct Node* newnode(char ch , int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->vertex=ch;
    temp->cost=value;
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

struct Stack
{
    char vertex;
    struct Stack* link;
};

struct Stack* head=NULL;

void pushin(char ch)
{
    struct Stack* temp=(struct Stack*)malloc(sizeof(struct Stack));
    temp->vertex=ch;
    if(head==NULL)
    {
        head=temp;
        temp->link=NULL;
    }
    else
    {
       temp->link=head;
       head=temp;        
    }
}

void pop()
{
    if(head==NULL) return ;
    struct Stack* temp=head;
    head=head->link;
    free(temp);
    return;
}

struct str* check(char ch)
{
    struct str* temp=NULL;
    for(temp=root;temp!=NULL;temp=temp->next)
    {
        if(temp->vertex==ch) 
            return temp;
    }
}
    
void print(char ch)
{
    int t=0;
    struct str* temp=check(ch);
    if(temp->flag == 0)
    {
        pushin(ch);
        printf("%c ",ch);
        temp->flag=1;
    }
    struct str* temp1=NULL;
    struct Node* temp2=NULL;
    for(temp2=ptr[ch-65];temp2!=NULL;temp2=temp2->next)
    {
       temp1=check(temp2->vertex);
       if(temp1->flag == 0)
       {
          t=1;
          pushin(temp1->vertex);
          printf("%c ",temp1->vertex);
          temp1->flag=1;
          break;
       }
    }
    if(t==0)
    {
        pop();
        if(head!=NULL) print(head->vertex);
    }
    else
    {
        print(temp1->vertex);
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
        if(m==0) push(end-65,start,i);
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
    printf("DFS : ");
    print(root->vertex);
    printf("\n");
} 
