#include<stdio.h>
#include<stdlib.h>


struct Node{
int data;
struct Node* next;
};


int length;
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* newnode=NULL;
struct Node* temp=NULL;
struct Node* ptr=NULL;


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
head->next=head;
tail=head;
length++;
}
else{
tail->next=newnode;
newnode->next=head;
tail=newnode;
length++;}}}


void disp(){
if(head==NULL){printf("List is empty.\n");
printf("Length : %d\n",length);}
else{
for(temp=head;temp->next!=head;temp=temp->next){
printf("%d ",temp->data);}
printf("%d ",temp->data);
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
newnode->next=head;
tail=head;
length++;}
else{
if(i==0){
tail->next=newnode;
newnode->next=head;
head=newnode;
length++;
}
else if(i>=length){
tail->next=newnode;
newnode->next=head;
tail=newnode;
length++;}
else{
int k=0;
temp=head;
while(k<i-1){
temp=temp->next; k++;}
newnode->next=temp->next;
temp->next=newnode;
length++;}}}


void delete(){
int i;
printf("At which index :");
scanf("%d",&i);
if(head==NULL){printf("List is already empty.\n");}
else{
if(i==0){
temp=head;
tail->next=head->next;
head=head->next;
free(temp);
length--;}
else if(i==length-1){
for(temp=head;temp->next->next!=head;temp=temp->next);
temp->next=head;
free(tail);
tail=temp;
length--;}
else if(i>0 && i<length-1){
int k=0;
temp=head;
while(k<i-1){
temp=temp->next; k++;}
ptr=temp->next;
temp->next=temp->next->next;
free(ptr);
length--;}
else{printf("Please enter valid index !\n");}}}


void delentire(){
if(head==NULL){printf("List is already empty.\n");}
else{
temp=head;
do{
ptr=temp;
temp=temp->next;
tail=temp;
length--;
}while(temp!=head);
head=NULL;
tail=NULL;}}


void search(){
int k,i=0,t=0;
printf("Enter the element to be searched :");
scanf("%d",&k);
temp=head;
do{
if(temp->data==k){
printf("The element is found at the index %d \n",i); t=1;}
temp=temp->next;
i++;
}while(temp!=head);
if(t==0){
printf("The element is not found\n");}
}



void reverseprint(struct Node* temp){
if(head==NULL){ 
printf("List is empty !\n");
return;}
else{
if(temp->next==head){
printf("%d ",temp->data);
return;}
else{
reverseprint(temp->next);
printf("%d ",temp->data);
}}}


void reverse(){
newnode=tail;
temp=head;
do{
ptr=temp->next;
temp->next=newnode;
newnode=temp;
temp=ptr;
}while(temp!=head);
head=newnode;}


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
case 8:reverseprint(head); printf("\n"); break;
default:
printf("please enter a valid number.\n"); break;
}
printf("Anything else ? Enter :");
scanf("%d",&n);
}}
