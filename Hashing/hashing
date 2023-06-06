//QUADRATIC Probing technique

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,k,m,i,j;
    float f;
    printf("Enter the no of elemets : ");
    scanf("%d",&n);
    f=(1.3*n)+1;
    k=(int)f;
    int a[k];
    for(i=0;i<k;i++)
        a[i]=-65536;
    for(i=0;i<n;i++)
    {
        printf("Enter the element : ");
        scanf("%d",&m);
        if(a[(m%k)]==-65536)
            a[m%k]=m;
        else
        {
            j=0;
            while(a[(m%k+j*j)%k]!=-65536)
                j++;
            a[(m%k+j*j)%k]=m;   
        }
    }
    for(i=0;i<k;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("Enter the element to be searched : ");
    scanf("%d",&m);
    i=0;
    for(j=0;j<k;j++)
    {
        if(a[(m%k+j*j)%k]==m)
        {
            i=1;
            n=(m%k+j*j)%k;
            break;
         }
    }
    if(i==1)
        printf("The element found at %d index\n",n);
    else
        printf("The element is not found\n");
 
}   
