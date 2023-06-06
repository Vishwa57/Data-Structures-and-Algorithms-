#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int data;
	int p;
	struct Queue* next;
};
struct Queue* front=NULL;
struct Queue* rear=NULL;
void enqueue(){
		struct Queue* newnode=NULL;
		newnode=(struct Queue*)malloc(sizeof(struct Queue));
		printf("Enter the element :");
		scanf("%d",&newnode->data);
		printf("Enter the priority :");
		scanf("%d",&newnode->p);
		if(front==NULL){
			front=newnode;
			rear=newnode;
			newnode->next=NULL;
		}
		else{
		    if(newnode->p < front->p){
		        newnode->next=front;
		        front=newnode;}
		    else if(newnode->p >= rear->p){
		        rear->next=newnode;
		        newnode->next=NULL;
		        rear=newnode;}
		    else{
			struct Queue* temp=NULL;
			temp=front;
			do{
			    if(temp->next==NULL || temp->next->p > newnode->p){ break;}
			    else{
			        temp=temp->next;
			        }
			  }while(1);
			  newnode->next=temp->next;
			  temp->next=newnode;}		        
		}
}
void dequeue(){
	if(front==NULL){
		printf("Queue is already empty !\n");
		return ;
	}
	else{
		struct Queue* temp=front;
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
	struct Queue* temp=NULL;
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
}
