// Adjacency List graph representation
// Topological sorting graph traversal

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

struct Stack* head1=NULL;
struct Stack* head2=NULL;

void pushin(char ch , int k)
{
    struct Stack* head=NULL;
    if(k==1) head=head1;
    else if(k==2)    head=head2;
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
    if(k==1)    head1=head;
    else if(k==2)    head2=head;
}

char pop(int k)
{   
    struct Stack* head=NULL;
    if(k==1) head=head1;
    else if(k==2)   head=head2;
    if(head!=NULL)
    {
        struct Stack* temp=head;
        char ch=head->vertex;
        head=head->link;
        free(temp);
        if(k==1)    head1=head;
        else if(k==2)     head2=head;
        return ch;
    }
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
        pushin(ch,1);
        temp->flag=1;
    }
    struct str* temp1=NULL;
    struct Node* temp2=NULL;
    if(ptr[ch-65]==NULL)
    {
        pushin(ch,2);
        pop(1);
        if(head1!=NULL) print(head1->vertex);
        else
        {
            struct str* temp3=NULL;
            for(temp3=root;temp3!=NULL;temp3=temp3->next)
            {
                if(temp3->flag==0)
                {
                    print(temp3->vertex);
                    return;
                }
            }
        }
        return;
    }
    else
    {
        for(temp2=ptr[ch-65];temp2!=NULL;temp2=temp2->next)
        {
           temp1=check(temp2->vertex);
           if(temp1->flag == 0)
           {
              t=1;
              pushin(temp1->vertex,1);
              temp1->flag=1;
              break;
           }
        }
    }
    if(t==0)
    {
        pushin(ch,2);
        pop(1);
        if(head1!=NULL) print(head1->vertex);
        else
        {
            struct str* temp3=NULL;
            for(temp3=root;temp3!=NULL;temp3=temp3->next)
            {
                if(temp3->flag==0)
                {
                    print(temp3->vertex);
                    return;
                }
            }
        }
    }
    else if(t==1)
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
    if(m==0)
        printf("Toplogical Sorting can be only applied in DAG");
    else
    {
        printf("Topological Order : ");
        print(root->vertex);
        while(head2!=NULL){
            printf("%c ",pop(2));}
        /*struct Stack* temp=NULL;
        for(temp=head2;temp!=NULL;temp=temp->link)
        {
            printf("%c ",temp->vertex);
        }*/
    }
    printf("\n");
} 
