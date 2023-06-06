//Ajdacent Matrix graph representation
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,i,k,j,m;
    char start,end;
    int a[15][15]={0};
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
        printf("Enter the edge between vertices !\n");
        printf("Enter starting Index :");
        scanf(" %c",&start);
        printf("Enter the ending Index :");
        scanf(" %c",&end);
        if(j) 
        {
            printf("Enter cost of the edge :");
            scanf("%d",&i);
        }
        a[start-65][end-65]=i;
        if(m==0) a[end-65][start-65]=i;
        printf("Any further links ? if yes Press 1 ,else 0 :");
        scanf("%d",&k);
    }
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("  \t");
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c\t",str[i]);
    }
    printf("\n\n");
    k=0;
    for(i=0;i<n;i++)
    {
        printf("%c \t",str[k]);
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
        k++;
    }
    printf("\n");
   
}
    
        
