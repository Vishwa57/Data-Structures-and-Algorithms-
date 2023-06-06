#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[20];

struct Node{
char data;
struct Node* next;
};

struct Node* head=NULL;
struct Node* newnode=NULL;


void push(char ch){
newnode=(struct Node*)malloc(sizeof(sizeof(struct Node)));
newnode->data=ch;
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

void main(){
int i;
printf("Enter the string :");
fgets(a,sizeof(a),stdin);
for(i=0;i<strlen(a);i++){
if(a[i]=='(' || a[i]=='{' || a[i]=='['){
push(a[i]);}
else if(a[i]==')' || a[i]=='}' || a[i]==']'){
if(head==NULL || (head->data!='(' && a[i]==')') || (head->data!='{' && a[i]=='}') || (head->data!='[' && a[i]==']')){
printf("Paranthesis not matched !\n");
break;}
else{
pop();}}}
if(head==NULL){
printf("Paranthesis matched successfully\n");}}













