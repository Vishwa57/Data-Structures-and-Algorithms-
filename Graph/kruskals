// Adjacency List graph representation
// Minimum Spanning Tree
// Kruskals Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char mstset[16];
int length1;
int costarray[20];
int length2;

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
    int flag;
    struct Node* next;
};

struct Node* ptr[15]={NULL};
struct Node* kruskal[15]={NULL};

struct Node* newnode(char ch , int value)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->vertex=ch;
    temp->cost=value;
    temp->flag=0;
    temp->next=NULL;
    return temp;
}

void push(int k , char ch , int value,int h)
{
    struct Node* temp1=NULL;
    if(h==1)    
        temp1=ptr[k];
    else
        temp1=kruskal[k];    
    if(temp1==NULL)
    {
        temp1=newnode(ch,value);
        if(h==1)    
            ptr[k]=temp1;
        else
            kruskal[k]=temp1;
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
    
int checkcycle(char ch,char start)
{
    if(ch==start)
        return 1;
    int t=0;
    struct str* temp=check(ch);
    if(temp->flag == 0)
    {
        pushin(ch);
        temp->flag=1;
    }
    struct str* temp1=NULL;
    struct Node* temp2=NULL;
    for(temp2=kruskal[ch-65];temp2!=NULL;temp2=temp2->next)
    {
       temp1=check(temp2->vertex);
       if(temp1->flag == 0)
       {
          t=1;
          pushin(temp1->vertex);
          temp1->flag=1;
          break;
       }
    }
    if(t==0)
    {
        pop();
        if(head!=NULL) {
            checkcycle(head->vertex,start);}
    }
    else
    {
        checkcycle(temp1->vertex,start);
    }
}


void mst()
{
    int i,k,j=0;
    struct str* temp1=NULL;
    struct Node* temp2=NULL;
    struct Node* temp3=NULL;
    struct str* temp4=NULL;
    for(i=0;i<length2;i++)
    {   
        k=costarray[i];
        for(temp1=root;temp1!=NULL;temp1=temp1->next)
        {
            j=0;
            for(temp2=ptr[temp1->vertex-65];temp2!=NULL;temp2=temp2->next)
            {
                if(temp2->cost==k && temp2->flag==0)
                {
                    k=0;
                    temp2->flag=1;
                    for(temp3=ptr[temp2->vertex-65];temp3!=NULL;temp3=temp3->next)
                    {
                        if(temp3->vertex == temp1->vertex)
                            temp3->flag=1;
                    }
                    k=checkcycle(temp1->vertex,temp2->vertex);
                    if(k!=1){
                        push(temp1->vertex-65,temp2->vertex,temp2->cost,2);
                        push(temp2->vertex-65,temp1->vertex,temp2->cost,2);
                        }
                    for(temp4=root;temp4!=NULL;temp4=temp4->next)
                        temp4->flag=0;
                    while(head!=NULL)
                        pop();
                    j=1;
                    break;
                }
            }
            if(j==1) break;
        }
    }
}
                        

void sort()
{
    int i,j,k;
    for(i=0;i<length2;i++)
    {
        for(j=0;j<length2-1;j++)
        {
            if(costarray[j]>costarray[j+1])
            {
                k=costarray[j];
                costarray[j]=costarray[j+1];
                costarray[j+1]=k;
            }
        }
    }
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
            costarray[length2]=i;
            length2++;
        }
        push(start-65,end,i,1);
        if(m==0 && start!=end) push(end-65,start,i,1);
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
    printf("Cost of the edges : ");
    for(i=0;i<length2;i++)
        printf("%d ",costarray[i]);
    printf("\n");
    sort();//to sort the costs
    printf("Sorted Order : ");
    for(i=0;i<length2;i++)
        printf("%d ",costarray[i]);
    printf("\n");
    mst();
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    temp1=root;
    for(i=0;i<n;i++)
    {
        printf("%c\t",temp1->vertex);
        temp1=temp1->next;
        for(temp=kruskal[i];temp!=NULL;temp=temp->next)
        {
            if(temp!=NULL)
                printf("%c , %d \t",temp->vertex,temp->cost);
        }
        printf("\n");
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); 
} 
