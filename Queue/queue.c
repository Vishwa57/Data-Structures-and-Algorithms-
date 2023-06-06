//array implementation
/*#include<stdio.h>
#define N 4
int front=-1;
int rear=-1;
int a[N];
int i;
int isempty(){
	if(front==-1 && rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(){
	if(front==(rear+1)%N){
		return 1;
	}
	else
		return 0;
}
void enqueue(){
	if(isfull())
	    {
			printf("Queue is full !\n");
		}
	else{
		int n;
		printf("Enter the element :");
		scanf("%d",&n);
		if(isempty()){
        a[i]=n;
		i=(i+1)%N;
		front++;
		rear++;
		}
		else{
			if(rear==N-1 && !isfull()){
				a[i]=n;
				i=(i+1)%N;
				rear=(rear+1)%N;
			}
			else{
			a[i]=n;
			i=(i+1)%N;
			rear=(rear+1)%N;
			}
		}
	}
}
void dequeue(){
	if(isempty()){
		printf("Queue is already empty !\n");
		return ;
	}
	else if(front == rear){
		front=rear=-1;
	}
	else{
		front=(front+1)%N;
	}
}
void top(){
	printf("top : %d\n",a[front]);
	return;
}
void print(){
	int j;
	if(front<=rear){
	for(j=front;j<=rear;j++){
		printf("%d ",a[j]);
	}}
	else{
		for(j=front;j<=N-1;j++){
			printf("%d ",a[j]);
			}
				for(j=0;j<=rear;j++){
					printf("%d ",a[j]);
		}
	}
	printf("\n");
}
void main(){
	int n;
	printf("ENTER THE OPTION \n1.ENQUEUE \n2.DEQUEUE \n3.FRONT\n0.EXIT\n");
	printf("Enter :");
	scanf("%d",&n);
	while(n){
		switch(n){
			case 1:
				enqueue();
				print();
				break;
			case 2:
				dequeue();
				print();
				break;
			case 3:
				top();
				break;
			default:
				printf("Please enter a valid number !\n");
				break;
		}
		printf("Anything else ? Enter :");
		scanf("%d",&n);
	}
	
}*/

//linked list implementation
/*
#include<stdio.h>
#include<stdlib.h>

#define N 4

struct Node{
	int data;
	struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enqueue(){
		struct Node* newnode=NULL;
		newnode=(struct Node*)malloc(sizeof(struct Node));
		printf("Enter the element :");
		scanf("%d",&newnode->data);
		if(front==NULL){
			front=newnode;
			rear=newnode;
			newnode->next=NULL;
		}
		else{
			rear->next=newnode;
			newnode->next=NULL;
			rear=newnode;
		}
}
void dequeue(){
	if(front==NULL){
		printf("Queue is already empty !\n");
		return ;
	}
	else{
		struct Node* temp=front;
		front=front->next;
		free(temp);
	}
}
void print(){
	if(front==NULL){
		printf("Queue is empty !\n");
		return ;
	}
	else{
	struct Node* temp=NULL;
	for(temp=front;temp!=NULL;temp=temp->next){
		printf("%d ",temp->data);
	}
	printf("\n");}
}
void main(){
	int n;
	printf("ENTER THE OPTION \n1.ENQUEUE \n2.DEQUEUE\n0.EXIT\n");
	printf("Enter :");
	scanf("%d",&n);
	while(n){
		switch(n){
			case 1:
				enqueue();
				print();
				break;
			case 2:
				dequeue();
				print();
				break;
			default:
				printf("Please enter a valid number !\n");
				break;
		}
		printf("Anything else ? Enter :");
		scanf("%d",&n);
	}
}*/
