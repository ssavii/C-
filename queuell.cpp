#include<stdio.h>  
#include<stdlib.h>  
struct queue  
{  
 int data;  
 struct queue *next;  
}*front,*rear,*q,*p;  
void add();  
void delete();  
void display();  
int main()  
{  
 int ch;  
 rear=NULL;  
 front=NULL;  
 do{  
 printf("\n\t****MENU****");  
 printf("\n\t1.ADD\n\t2.DELETE\n\t3.EXIT");  
 printf("Enter your choice:");  
 scanf("%d",&ch);  
 switch(ch) 
 {  
 case 1:  
 add();  
 display();  
 break;  
 case 2:  
 delete();  
 printf("\n");  
 display();  
 break;  
 default :  
 exit(0);  
 }  
 }while(ch!=3);  
 return 0;  
}  
void add()  
{  
 p=(struct queue*)malloc(sizeof(struct queue));   printf("\n\tENTER THE DATA :");  
 scanf("%d",&p->data);  
 p->next=NULL;  
 if(rear==NULL)  
 {  
 rear=p;  
 front=p;  
 }  
 else  
 { 
 rear->next=p;  
 rear=rear->next;  
 }  
}  
void delete()  
{  
 q=front;  
 if(q==NULL)  
 {  
 printf("\n\tTHE QUEUE IS EMPTY");  
 }  
 else  
 {  
 printf("\n\tTHE NUMBER DELETED IS : %d",front->data);   front=front->next;  
 q->next=NULL;  
 free(q);  
 }  
}  
void display()  
{  
 q=front;  
 if (q==NULL)  
 {  
 printf("\n\tTHE QUEUE IS EMPTY");  
 }  
 else  
 { 
 while(q!=NULL)  
 {  
 printf("\t%d",q->data);  
 q=q->next;  
 }  
 }  
}  
