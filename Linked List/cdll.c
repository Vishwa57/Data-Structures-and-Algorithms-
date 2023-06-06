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
newnode->prev=head;
newnode->next=head;
tail=head;
length++;
}
else{
newnode->prev=tail;
newnode->next=head;
tail->next=newnode;
head->prev=newnode;
tail=newnode;
length++;}}}


void disp(){
if(head==NULL){printf("List is empty.\n");
printf("Length : %d\n",length);}
else{
temp=head;
do{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=head);
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
newnode->prev=head;
newnode->next=head;
tail=head;
length++;}
else{
if(i==0){
head->prev=newnode;
newnode->next=head;
newnode->prev=tail;
tail->next=newnode;
head=newnode;
length++;
}
else if(i>=length){
tail->next=newnode;
newnode->prev=tail;
newnode->next=head;
head->prev=newnode;
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
head->prev=tail;
tail->next=head;
free(temp);
length--;}
else if(i==length-1){
temp=tail;
head->prev=tail->prev;
tail=tail->prev;
tail->next=head;
free(temp);
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
do{
if(head==tail){
free(head);
length--;
break;}
newnode=temp;
temp=temp->next;
head=temp;
tail->next=temp;
temp->prev=tail;
free(newnode);
length--;
}while(1);
head=NULL;
tail=NULL;}}


void search(){
if(head==NULL){ printf("List is empty !\n");}
else{
int k,i=0,t=0;
printf("Enter the element to be searched :");
scanf("%d",&k);
temp=head;
do{
if(temp->data==k){
printf("The element is found at the index %d \n",i);
t++;}
temp=temp->next;
i++;
}while(temp!=head);}}



void reverseprint(){
if(head==NULL){ printf("List is empty !\n");}
else{
temp=tail;
do{
printf("%d ",temp->data);
temp=temp->prev;
}while(temp!=tail);}
printf("\n");}


void reverse(){
temp=head;
do{
newnode=temp->prev;
temp->prev=temp->next;
temp->next=newnode;
temp=temp->prev;
}while(temp!=head);
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
