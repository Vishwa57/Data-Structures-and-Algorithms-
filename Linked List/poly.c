#include<stdio.h>
#include<stdlib.h>

struct Node{ 
int coeff;
int power;
struct Node* next;
};

struct Node* newnode=NULL;
struct Node* p[2];
int m;

void* create(){
int n,i;
struct Node* tail=NULL;
struct Node* head=NULL;
struct Node* temp=NULL;
printf("Enter the highest power of poly %d :",m+1);
scanf("%d",&n);
for(i=n;i>=0;i--){
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the coeff of x^%d :",i);
scanf("%d",&newnode->coeff);
newnode->power=i;
newnode->next=NULL;
if(i==n){
head=newnode;
tail=newnode;
p[m]=head;
m++;}
else{
tail->next=newnode;
tail=tail->next;}}
for(temp=head;temp!=NULL;temp=temp->next){
printf("%dx^%d ",temp->coeff,temp->power);}
printf("\n");}

void arithematic(int t){
int k,g=0;
struct Node* temp1=NULL;
struct Node* temp2=NULL;
struct Node* x=NULL;
if(p[0]->power > p[1]->power){
temp1=p[0];
x=p[1];
g=1;}
else{
temp1=p[1];
x=p[0];}
temp2=x;
for(;temp1!=NULL;temp1=temp1->next){
for(;temp2!=NULL;temp2=temp2->next){
if(temp1->power==temp2->power){
if(t==2){ printf("%dx^%d ",temp1->coeff + temp2->coeff,temp1->power);}
else if(t==3){ 
if(g){
printf("%dx^%d ",temp1->coeff - temp2->coeff,temp1->power);}
else{
printf("%dx^%d ",temp2->coeff - temp1->coeff,temp1->power);}}
break;}}
if(temp2==NULL){
if(t==2 || t==3 && g==1){
printf("%dx^%d ",temp1->coeff,temp1->power);}
else{
if(t==3 && g==0){
printf("%dx^%d ",-(temp1->coeff),temp1->power);}}
}
temp2=x;}
printf("\n");}


void main(){
int n;
printf("1.Create Polynomial\n2.ADD\n3.SUB\n0.EXIT\n");
printf("Enter :");
scanf("%d",&n);
while(n){
switch(n){
case 1: create(); break;
case 2: arithematic(2);    break;
case 3: arithematic(3);    break;
default: printf("Pls enter valid number\n"); break;}
printf("Anything else ? Enter :");
scanf("%d",&n);}}
