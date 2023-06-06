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
printf("Enter the Number of elements : ");
scanf("%d",&n);
for(i=0;i<n;i++){
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the element : ");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL){
head=newnode;
tail=newnode;
length++;}
else{
//for(temp=head;temp->next!=NULL;temp=temp->next);
//temp->next=newnode;
tail->next=newnode;
tail=tail->next;
length++;}
}}


void disp(){
if(head==NULL){printf("List is empty.\n");}
else{
for(temp=head;temp!=NULL;temp=temp->next){
printf("%d ",temp->data);}
printf("\n");
printf("Length : %d\n",length);}
}


void insert(){
int i;
printf("At which index ? :");
scanf("%d",&i);
newnode=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the element :");
scanf("%d",&newnode->data);
if(i==0){
if(head==NULL){
head=newnode;
newnode->next=NULL;
length++;
}
else{
newnode->next=head;
head=newnode;
length++;}}
else if(i>=length){
//for(temp=head;temp->next!=NULL;temp=temp->next);
tail->next=newnode;
newnode->next=NULL;
tail=newnode;
length++;}
else{
int k=0;
temp=head;
while(k<i-1){
temp=temp->next;k++;}
newnode->next=temp->next;
temp->next=newnode;length++;}
}


void delete(){
if(head==NULL){
printf("List is already empty \n");
}
else{
int i;
printf("At which index ? :");
scanf("%d",&i);
if(i==0){
temp=head;
head=head->next;
free(temp);
length--;}
else if(i==length-1){
for(temp=head;temp->next->next!=NULL;temp=temp->next);
ptr=temp->next;
temp->next=NULL;
free(ptr);
length--;}
else if(i>0 && i<length-1){
int k=0;
temp=head;
while(k<i-1){
temp=temp->next;k++;}
ptr=temp->next;
temp->next=temp->next->next;
free(ptr);length--;}
else{printf("Enter valid index.\n");
}}}


void delentire(){
if(head==NULL){printf("List is already empty.\n");}
else{
temp=head;
while(temp!=NULL){
ptr=temp;
temp=temp->next;
free(ptr);
length--;}
head=NULL;}}


void search(){
if(head!=NULL){
int k,i=0;
printf("Enter the element to be searched :");
scanf("%d",&k);
for(temp=head;temp!=NULL;temp=temp->next){
if(temp->data==k){
printf("The element is found at the index %d\n",i);}
i++;}}
else{
printf("List is empty !\n");}}


void reverse(){
struct Node* prev=NULL;
temp=head;
while(temp!=NULL){
ptr=temp->next;
temp->next=prev;
prev=temp;
temp=ptr;}
head=prev;
}


//we can reverse the list using recursion 
/*
reverse(head);   //in main
void reverse(struct Node* temp1){
if(temp1->next==NULL){
head=temp1;
return;}
reverse(temp1->next);
struct Node* p = temp1->next;
p->next=temp1;
temp1->next=NULL;}
*/


void reverseprint(struct Node* temp1){
if(temp1==NULL){
return ;}
reverseprint(temp1->next);
printf("%d ",temp1->data);}


void sort(){
int m;
struct Node* t=NULL;
struct Node* r=tail;
for(temp=head;temp!=NULL;temp=temp->next){
ptr=head;
while(ptr!=r){
if(ptr->data > ptr->next->data){
m=ptr->data;
ptr->data=ptr->next->data;
ptr->next->data=m;}
if(ptr->next==r){
t=ptr;}
ptr=ptr->next;}
r=t;}}


void main(){
int n;
printf("Enter what you want !\n1.CREATE A LIST\n2.DISPLAY THE LIST\n3.INSERT AN ELEMENT\n4.DELETE AN ELEMENT\n5.DELETE ENTIRE LIST\n6.SEARCH\n7.REVERSE THE LIST \n8.DISPLAY THE LIST IN REVERSE ORDER\n9.SORT\n10.EXIT\n");
printf("Enter : ");
scanf("%d",&n);
while(n!=10){
switch(n){
case 1: create();    break;
case 2: disp();      break;
case 3: insert();    break;
case 4: delete();    break;
case 5: delentire(); break;
case 6: search();    break;
case 7: reverse();   break;
case 8: reverseprint(head); printf("\n"); break;
case 9: sort(); break;
default:
printf("please enter a valid number.\n"); break;
}
printf("Anything else ? Enter :");
scanf("%d",&n);
}}

