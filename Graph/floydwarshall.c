// adjacency matrix representation
// shortest path algorithm
// Floyd Warshall's algorithm

#include<stdio.h>
#include<stdio.h>

int main()
{
    int n,i,j,p;
    char start,end;
    printf("Enter the number of nodes :");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=65536;
        }
    }
    printf("If you want links , press 1 ,else 0 :");
    scanf("%d",&p);
    printf("if directed graph press 1,else 0 :");
    scanf("%d",&i);
    while(p)
    {
        printf("Enter the starting vertex :");
        scanf(" %c",&start);
        printf("Enter the ending vertex :");
        scanf(" %c",&end);
        printf("Enter the edge :");
        scanf("%d",&j);
        a[start-65][end-65]=j;
        if(i==0)    a[end-65][start-65]=j;
        printf("If any further links press 1,else 0 :");
        scanf("%d",&p);
   }
   printf("Actual graph :\n");
   printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
   printf(" \t");
   for(i=0;i<n;i++) 
       printf("%c\t",i+65);
   printf("\n");
   for(i=0;i<n;i++)
   {
        printf("%c\t",i+65);
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
   }
   printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
   for(p=0;p<n;p++)
   {
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               if(a[i][j] > a[i][p]+a[p][j])
                   a[i][j]=a[i][p]+a[p][j];
           }
       }
   }
   printf("Shortest Path graph !\n");
   printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
   printf(" \t");
   for(i=0;i<n;i++) 
       printf("%c\t",i+65);
   printf("\n");
   for(i=0;i<n;i++)
   {
        printf("%c\t",i+65);
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
   }
   printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}      
         
         
         
         
         
         
         
         
