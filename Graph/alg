// Adjacency List graph representation

#include<stdio.h>
#include<stdlib.h>


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

void main()
{
    int n,i,k,j,m;
    char start,end;
    char str[15];
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        str[i]=i+65;
    }
    str[i]='\0';
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
    for(i=0;i<n;i++)
    {
        printf("%c\t",str[i]);
        for(temp=ptr[i];temp!=NULL;temp=temp->next)
        {
            printf("%c , %d\t",temp->vertex,temp->cost);
        }
        printf("\n");
    }
}   
