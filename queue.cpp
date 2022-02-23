#include<stdio.h>  
#include<stdlib.h>  
#define MAX 5  
struct queue  
{  
 int rear,front;  
 int a[MAX];  
}q1;  
void add();  
void delete();  
void display();  
int empty();  
int full();  
int main()  
{  
 int ch;  
 q1.rear=-1;  
 q1.front=0;  
 do{  
 printf("\n\t****MENU****");  
 printf("\n\t1.ADD\n\t2.DELETE\n\t3.EXIT"); 
 printf("Enter your choice:");   scanf("%d",&ch);  
 switch(ch)  
 {  
 case 1:  
 add();  
 display();  
 break;  
 case 2:  
 delete();  
 display();  
 break;  
 default :  
 exit(0);  
 }  
 }while(ch!=3);  
 return 0;  
}  
int full()  
{  
 if(q1.rear==MAX-1)  
 {  
 return(1);  
 }  
 else  
 {  
 return(0);  
 }  
} 
int empty()  
{  
 if(q1.front==q1.rear+1)  
 {  
 return(1);  
 }  
 else  
 {  
 return(0);  
 }  
}  
void add()  
{  
 int x;  
 if(full()==1)  
 {  
 printf("\n\tTHE QUEUE IS FULL");   }  
 else  
 {  
 printf("\n\tENTER THE ELEMENT");   scanf("%d",&x);  
 q1.rear++;  
 q1.a[q1.rear]=x;  
 }  
}  
void delete() 
{  
 int x;  
 if(empty()==1)  
 {  
 printf("\n\tTHE QUEUE IS EMPTY");   }  
 else  
 {  
 x=q1.a[q1.front];  
 printf("\n\tTHE ELEMENT DELETED IS : %d",x);   q1.front++;  
 }  
}  
void display()  
{  
 int i;  
 if (empty()==1)  
 {  
 printf("\n\tTHE QUEUE IS EMPTY");   }  
 else  
 {  
 printf("\n");  
 for(i=q1.front;i<q1.rear;i++)  
 {  
 printf("\t%d",q1.a[i]);  
 }  
 }  
} 
