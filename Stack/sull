#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

struct Node* head=NULL;
struct Node* newnode=NULL;


void push(){
newnode=(struct Node*)malloc(sizeof(sizeof(struct Node)));
printf("Enter the element :");
scanf("%d",&newnode->data);
if(newnode==NULL){
perror("Stack Overflow\n");
exit(1);}
else{
if(head==NULL){
head=newnode;
newnode->next=NULL;}
else{
newnode->next=head;
head=newnode;}}}


void pop(){
struct Node* temp=NULL;
temp=head;
head=head->next;
free(temp);}


void print(){
if(head==NULL){
printf("List is empty!\n");}
else{
struct Node* temp=NULL;
for(temp=head;temp!=NULL;temp=temp->next){
printf("%d ",temp->data);}
printf("\n");}}


void main(){
int n;
printf("1.PUSH\n2.POP\n0.EXIT\n");
printf("Enter : ");
scanf("%d",&n);
while(n){
switch(n){
case 1: push(); print(); break;
case 2: pop();  print(); break;
default: printf("Pls enter valid number\n"); break;
}
printf("Anything else ? Enter :");
scanf("%d",&n);
}}
