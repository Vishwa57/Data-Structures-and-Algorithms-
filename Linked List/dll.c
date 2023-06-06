#include<stdio.h>
#include<stdlib.h>


struct Node{
int data;
struct Node* next;
struct Node* prev;
};


int length;
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* newnode=NULL;
struct Node* temp=NULL;


void create(){
int n,i;
printf("How many elements? :");
scanf("%d",&n);
for(i=0;i<n;i++){
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the element :");
scanf("%d",&newnode->data);
if(head==NULL){
head=newnode;
newnode->prev=NULL;
newnode->next=NULL;
length++;
}
else{
for(temp=head;temp->next!=NULL;temp=temp->next);
temp->next=newnode;
newnode->prev=temp;
newnode->next=NULL;
tail=newnode;
length++;}}}


void disp(){
if(head==NULL){printf("List is empty.\n");
printf("Length : %d\n",length);}
else{
for(temp=head;temp!=NULL;temp=temp->next){
printf("%d ",temp->data);}
printf("\n");
printf("Length : %d\n",length);}}


void insert(){
int i;
printf("At which index? :");
scanf("%d",&i);
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the element :");
scanf("%d",&newnode->data);
if(head==NULL){
head=newnode;
newnode->prev=NULL;
newnode->next=NULL;
length++;}
else{
if(i==0){
head->prev=newnode;
newnode->next=head;
newnode->prev=NULL;
head=newnode;
length++;
}
else if(i>=length){
for(temp=head;temp->next!=NULL;temp=temp->next);
temp->next=newnode;
newnode->prev=temp;
newnode->next=NULL;
tail=newnode;
length++;}
else{
int k=0;
temp=head;
while(k<i-1){
temp=temp->next; k++;}
newnode->next=temp->next;
temp->next->prev=newnode;
temp->next=newnode;
newnode->prev=temp;
length++;}}}


void delete(){
int i;
printf("At which index :");
scanf("%d",&i);
if(head==NULL){printf("List is already empty.\n");}
else{
if(i==0){
temp=head;
head=head->next;
head->prev=NULL;
free(temp);
length--;}
else if(i==length-1){
tail=tail->prev;
free(tail->next);
tail->next=NULL;
length--;}
else if(i>0 && i<length-1){
int k=0;
temp=head;
while(k<i){
temp=temp->next; k++;}
temp->next->prev=temp->prev;
temp->prev->next=temp->next;
free(temp);
length--;}
else{printf("Please enter valid index !\n");}}}


void delentire(){
if(head==NULL){printf("List is already empty.\n");}
else{
temp=head;
while(temp!=NULL){
free(temp->prev);
temp=temp->next;
length--;}
head=NULL;}}


void search(){
int k,i=0;
printf("Enter the element to be searched :");
scanf("%d",&k);
for(temp=head;temp!=NULL;temp=temp->next){
if(temp->data==k){
printf("The element is found at the index %d \n",i);}
i++;}}



void reverseprint(){
if(head==NULL){ printf("List is empty !\n");}
else{
for(temp=tail;temp!=NULL;temp=temp->prev){
printf("%d ",temp->data);}}
printf("\n");}


void reverse(){
for(temp=head;temp!=NULL;temp=temp->prev){
newnode=temp->prev;
temp->prev=temp->next;
temp->next=newnode;
}
temp=head;
head=tail;
tail=temp;}


void main(){
int n;
printf("Enter what you want !\n1.CREATE A LIST\n2.DISPLAY THE LIST\n3.INSERT AN ELEMENT\n4.DELETE AN ELEMENT\n5.DELETE ENTIRE LIST\n6.SEARCH\n7.REVERSE THE LIST \n8.DISPLAY THE LIST IN REVERSE ORDER\n9.EXIT\n");
printf("Enter : ");
scanf("%d",&n);
while(n!=9){
switch(n){
case 1: create();    break;
case 2: disp();      break;
case 3: insert();    break;
case 4: delete();    break;
case 5: delentire(); break;
case 6: search();    break;
case 7: reverse();   break;
case 8:reverseprint();  break;
default:
printf("please enter a valid number.\n"); break;
}
printf("Anything else ? Enter :");
scanf("%d",&n);
}}
