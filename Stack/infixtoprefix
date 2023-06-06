#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node{
char data;
struct Node* next;
};
struct Node* head=NULL;
struct Node* newnode=NULL;

struct Node1{
	int data;
	struct Node1* next;
};
struct Node1* top=NULL;
struct Node1* node=NULL;

void pusht(int t){
node=(struct Node1*)malloc(sizeof(struct Node1));
node->data=t;
if(top==NULL){
    node->next=NULL;
	top=node;}
else{
	node->next=top;
	top=node;}
}

int popt(){
int t;
struct Node1* temp1=top;
t=top->data;
top=top->next;
free(temp1);
return t;}

void push(char t){
newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=t;
if(head==NULL){
    newnode->next=NULL;
	head=newnode;}
else{
	newnode->next=head;
	head=newnode;}
}

char pop(){
char t;
struct Node* temp=head;
t=head->data;
head=head->next;
free(temp);
return t;}

int pr(char a){
if(a=='+'){ return 1;}
else if(a=='-'){ return 1;}
else if(a=='*'){ return 2;}
else if(a=='/'){ return 2;}
else if(a=='^'){ return 3;}
else { return -1;}
}

void preeval(char *p1){
	int i=0,a,b,d;
	strrev(p1);
	while(*(p1+i)!='\0'){
		if(*(p1+i)!='*' && *(p1+i)!='+' && *(p1+i)!='-' && *(p1+i)!='/' && *(p1+i)!='^' && *(p1+i)!=','){
			d=((int)*(p1+i))-48;
			pusht(d); i++;
		}
		else if(*(p1+i)==','){
			i++;
		}
		else{
			a=popt(); 
			b=popt(); 
			if(*(p1+i)=='*'){ pusht(a*b); }
			else if(*(p1+i)=='+'){ pusht(a+b); }
			else if(*(p1+i)=='-'){ pusht(a-b); }
			else if(*(p1+i)=='/'){ pusht(a/b); }
			else if(*(p1+i)=='^'){ pusht(a^b); }
			i++;
		}
	}
	if(top->next==NULL){
		printf("ANSWER : %d\n",top->data);
	}
}

void intopre(char *p){
char s[50];
int i=0,j=0,r;
while(*(p+i)!='\0')
{
if(*(p+i)!='*' && *(p+i)!='+' && *(p+i)!='-' && *(p+i)!='/' && *(p+i)!='^' && *(p+i)!='(' && *(p+i)!=')')
{
        *(s+j)=*(p+i);
        i++; j++; 
}
else
{
		if(*(p+i)!=')'){
        *(s+j)=',';
        j++;}
        if(head==NULL){
        	push(*(p+i)); i++;
		}
        else{
        	if(*(p+i)=='('){
        		while(head->data!=')'){
        			*(s+j)=pop(); j++;
        			if(head->data!=')'){
        				*(s+j)=',';
        				j++; 
					}
				}
				pop(); i++;
			}
           else if((*(p+i)==')') || (head->data==')') || (pr(*(p+i)) >= pr(head->data) && head->data!=')') ) 
           {
           push(*(p+i)); i++;
           }
           else
           {
           while(head->data!='(' && pr(*(p+i))<pr(head->data))
           {
           *(s+j)=pop(); j++;
           *(s+j)=','; j++;
           if(head==NULL){ break;}
           }
           push(*(p+i)); i++;}}}}
           *(s+j)=','; j++;
           while(head!=NULL){
          *(s+j)=pop(); j++;
          if(head==NULL){
          	break;
		  }
		  *(s+j)=',';  j++;}   
          *(s+j)='\0';
          printf("Prefix expression :");
          strrev(s);
          for(r=0;*(s+r)!='\0';r++){
          	if(*(s+r)!='(' && *(s+r)!=')')
          		printf("%c",*(s+r));
		  }
		  printf("\n");
		  preeval(s);
}




void main(){
char p[50];
int i=0,n;
printf("Enter the expression :");
do{
scanf("%c",&(*(p+i)));
i++;
}while(*(p+(i-1))!='\n');
*(p+(i-1))='\0';
strrev(p);
puts(p);
intopre(p);
}
