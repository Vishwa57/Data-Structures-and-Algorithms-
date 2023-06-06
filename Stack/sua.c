#include<stdio.h>

#define N 5

int top=-1;
int stack[N];

int isfull(){
if(top==N-1){
return 1;}
else{
return 0;}}

int isempty(){
if(top==-1){
return 1;}
else{
return 0;}}

void push(){
if(isfull()){ printf("Stack Overflow\n");}
else{
int n;
printf("Enter the element :");
scanf("%d",&n);
top++;
stack[top]=n;}}

void pop(){
if(isempty()){
printf("Stack is empty\n");}
else{
top--;}}

void print(){
if(isempty()){
printf("Stack is empty\n");}
else{
int i;
printf("Stack :");
for(i=0;i<=top;i++){
printf("%d ",stack[i]);}
printf("\n");}}

void main(){
int n;
printf("1.PUSH\n2.POP\n3.EXIT\n");
printf("Enter :");
scanf("%d",&n);
while(n!=3){
switch(n){
case 1: push(); print(); break;
case 2: pop(); print(); break;
default: printf("Enter a valid number.\n"); break;}
printf("Anything else ? enter :");
scanf("%d",&n);}}
