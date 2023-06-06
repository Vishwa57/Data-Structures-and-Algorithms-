//Heap datastructure

#include<stdio.h>
#include<stdlib.h>

int n,p;
int a[10];

void insert(int i,int r)
{
    int k;
    if(i==0)
        return;
    else
    {
        if(r==1)
        {
            while(i>0)
            {
                if(a[i] > a[(i-1)/2])
                    return;
                else
                {
                    k=a[(i-1)/2];
                    a[(i-1)/2]=a[i];
                    a[i]=k;
                    i=(i-1)/2;
                }
            }
        }
        else if(r==2)
        {
            while(i>0)
            {
                if(a[i] < a[(i-1)/2])
                    return;
                else
                {
                    k=a[(i-1)/2];
                    a[(i-1)/2]=a[i];
                    a[i]=k;
                    i=(i-1)/2;
                }
            }
        }
     }
} 

void del()
{
    int k,t,i;
    if(n==0)
    {
        printf("Array is already empty!\n");
    } 
    else
    {
        k=a[0];
        a[0]=a[n-1];
        a[n-1]=k;
        n--;
        if(p==1)
        { 
            i=0; 
            while(i<n){
                if(2*i+1 < n && 2*i+2==n)
                {
                    if(a[2*i+1] < a[i]){
                        t=a[2*i+1];
                        a[2*i+1]=a[i];
                        a[i]=t;
                        i=2*i+1;}
                    else
                        return;
                 }
                 else if(2*i+1 < n && 2*i+2 < n)
                 {
                    if(a[2*i+1] < a[2*i+2])
                    {
                        if(a[i]>a[2*i+1])
                        {
                            t=a[2*i+1];
                            a[2*i+1]=a[i];
                            a[i]=t;
                            i=2*i+1;
                        }
                        else 
                            return;
                    }
                    else
                    {
                        if(a[i]>a[2*i+2])
                        {
                            t=a[2*i+2];
                            a[2*i+2]=a[i];
                            a[i]=t;
                            i=2*i+2;
                        }
                        else
                            return;
                    }
                 }
                 else
                    break;
              }
         } 
       else if(p==2)
        { 
            i=0; 
            while(i<n){
                if(2*i+1 < n && 2*i+2==n)
                {
                    if(a[2*i+1] > a[i]){
                        t=a[2*i+1];
                        a[2*i+1]=a[i];
                        a[i]=t;
                        i=2*i+1;}
                    else
                        return;
                 }
                 else if(2*i+1 < n && 2*i+2 < n)
                 {
                    if(a[2*i+1] > a[2*i+2])
                    {
                        if(a[i]<a[2*i+1])
                        {
                            t=a[2*i+1];
                            a[2*i+1]=a[i];
                            a[i]=t;
                            i=2*i+1;
                        }
                        else 
                            return;
                    }
                    else
                    {
                        if(a[i]<a[2*i+2])
                        {
                            t=a[2*i+2];
                            a[2*i+2]=a[i];
                            a[i]=t;
                            i=2*i+2;
                        }
                        else
                            return;
                    }
                 }
                 else
                    break;
            }        
       }
       return;
    }
    
}  

void maxheapify()
{
    int b[10],i,j;
    for(i=0;i<n;i++)
        b[i]=a[i];
    for(i=0;i<n;i++){
        a[i]=b[i];
        insert(i,2);
        for(j=0;j<=i;j++)
            printf("%d ",a[j]);
        printf("\n");}
   
}

void minheapify()
{
    int b[10],i,j;
    for(i=0;i<n;i++)
        b[i]=a[i];
    for(i=0;i<n;i++){
        a[i]=b[i];
        insert(i,1);
        for(j=0;j<=i;j++)
            printf("%d ",a[j]);
        printf("\n");}
}
       
             
int main()
{
    int c,i,j,t,r;    
    printf("Enter your choice :\n");
    printf("1.CREATE\n2.INSERT\n3.DELETE\n4.SORT\n5.PRINT\n0.EXIT\n");
    printf("Enter :");
    scanf("%d",&c);
    while(c)
    {
        switch(c)
        {
            case 1:
                printf("Enter the Number of Nodes :");
                scanf("%d",&n);
                printf("Which type?\n1.MIN HEAP\n2.MAX HEAP\n");
                printf("Enter :");
                scanf("%d",&p);
                j=0;
                while(j<n)
                {
                    printf("Enter the element :");
                    scanf("%d",&a[j]);
                    insert(j,p);
                    j++;
                 }
                 j--;
                 break;
            case 2:
                printf("Enter the element to be inserted :");
                scanf("%d",&i);
                j++;
                n++;
                a[j]=i;
                insert(j,p);
                break;
            case 3:
                t=a[0];
                del();
                if(n!=0)
                    printf("Deleted Element : %d \n",t);
                break;
            case 4: // if once sorting performed , then recreate the array with max/min heap!
                printf("1.Ascending Order\n2.Descending Order\n");
                printf("Enter :");
                scanf("%d",&i);
                r=p;
                if(i==1){
                    if(p==1){
                        maxheapify();
                        p=2;}
                     }
                else if(i==2){
                    if(p==2){
                        minheapify();
                        p=1;}
                        }
                t=n;
                while(n!=0)
                    del();
                 n=t;
                 p=r;
                 break;
            case 5:
                printf("In array : ");
                for(i=0;i<n;i++)
                    printf("%d ",a[i]);
                printf("\n");
                break;
            default:
                printf("Pls Enter a valid Number!\n");
                break;
         }
         printf("If anything else , Enter your choice :");
         scanf("%d",&c);
    }     
                
    return 0;
}
