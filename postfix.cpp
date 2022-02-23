#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define size 50


struct stack
{
 int data[size];
 int top;
}st;

void init(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);
void display(struct stack *);

int main()
{
 int op1,op2,value=0,i;
 char eq[30];

 printf("\n Enter a postfix expression=");
 scanf("%s",eq);
 printf("\n Entered expression is = %s",eq);
 init(&st);

 for(i=0;eq[i]!='\0';i++)
 {
   if(isalpha(eq[i]))
   {
    printf("\nEnter value of %c=",eq[i]);
    scanf("%d",&value);

    push(&st,value);
   }

   else
   {
    op2=pop(&st);
	op1=pop(&st);

      switch(eq[i])
      {
       case '+': push(&st,op1+op2);
		 break;
       case '-': push(&st,op1-op2);
		 break;
       case '*': push(&st,op1*op2);
		 break;
       case '/': push(&st,op1/op2);
		 break;
       case '$': push(&st,pow(op1,op2));
		 break;
	default: exit(0);

      } // end of switch
   }  // end of else
  }  //end of for

 value=pop(&st);
 printf("\n evaluated output of postfix expression is= %d\n\n",value);
return 0;  
}

void init(struct stack *st)
{
  st->top=-1;
}

void push(struct stack *st, int value)
{
 if(st->top==size-1)
 printf("\n Stack is full");
 else
 {
 st->top++;
 st->data[st->top]=value;
 display(st);
 }
}

int pop(struct stack *st)
{
 int x;
 if(st->top==-1)
 printf("\n Stack is empty");
 else
 {
 x=st->data[st->top];
 st->top--;
 display(st);
 return(x);
 }
}


void display(struct stack *st)
{
	int i;
printf("\n\tDISPLAY");

	   	 if(st->top==-1)
	    	{
			printf("\n\tSTACK IS ENPTY!");
	    	}
	    	else
	    	{
			printf("\n\tTHE STACK IS:");
			for(i=st->top;i>=0;i--)
			{
		    		printf("\n\t%d",st->data[i]);
			}
	   	 }	
}
