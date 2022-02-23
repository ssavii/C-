#include<stdio.h>
#include<stdlib.h>

struct stack{
	int num;
	struct stack *next; 
}*top,*temp,*p;

void display();
void push();
int pop();

int main(){
	int choice,x;
	top=NULL;
	do{
		printf("\nEnter operation to be performed : 1.Push 2.Pop 3.Display 4.Exit ");
		scanf("%d",&choice);
		switch(choice){
			case 1: push();
					break;
			case 2: x=pop();
					if(x==0){
						printf("\nStack is empty!");
					} 
					else{
						printf("\nPopped element is :%d",x);
					}
					break;
			case 3: display();
					break;
			case 4: continue;
			default:printf("\nInvalid choice!");			
		}
	}while(choice!=4);
}


void push(){
	p=(struct stack*)malloc(sizeof(struct stack));
	if(top==NULL){
		printf("\nEnter data : ");
		scanf("%d",&p->num);
		top=p;
		p->next=NULL;	
	}
	else{
		printf("\nEnter data : ");
		scanf("%d",&p->num);
		p->next=top;
		top=p;	
	}
	display();	
}
int pop(){
	int x;
	if(top==NULL){
		return 0;	
	}
	else{
		temp=top;
		x=top->num;
		top=top->next;
		free(temp);
		return x;
	}
}
void display(){
	temp=top;
	printf("\nThe stack is : \n");
	if(temp==NULL){
		printf("\nStack is empty!");
	}
	while(temp!=NULL){
		printf("%d\n",temp->num);
		temp=temp->next;
	}	
}
