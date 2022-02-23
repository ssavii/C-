#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct bstree  // Structure template for tree node
{ 
int data;
struct bstree *lchild,*rchild;
}node;


typedef struct// Structure template for stack
{
node *item[max];
int top;
}stack;

stack s;


node *createbstree(node *);
node *getnode();
node *search(node *,int);
void inorder_rec(node*);
void preorder_rec(node*);
void postorder_rec(node*);
void push(node*);
int checkfull();
node *pop();
int checkempty();
void inorder_nonrec(node*);
void preorder_nonrec(node *);
node *del(node*);


int main()
{
node *root=NULL,*temp;
int ch=0,srno=0;
printf("\nCreate the BST\n");
root=createbstree(root);
 do
 {
  
  printf("\n1.inorder with recursion");
  printf("\n2.preorder with recursion");
  printf("\n3.postorder with recursion");
  printf("\n4.inorder without recursion");
  printf("\n5.preorder without recursion");
  printf("\n6.search the node");
  printf("\n7.Delete node");
  printf("\n8.exit");
  printf("\nenter your choice:");
  scanf("%d",&ch);
  switch(ch)
	{		
		case 1:printf("\n Inorder with recursion\n");
			   inorder_rec(root);
       	break;
		case 2:printf("\n Preorder with recursion\n");
			   preorder_rec(root);
       	break;
		case 3:printf("\n Postorder with recursion\n");
			   postorder_rec(root);
       	break;
		case 4:printf("\n Inorder without recursion\n");
			   s.top=-1; // initialise top=-1
       		   inorder_nonrec(root);
       	break;
		case 5:printf("\n Preorder without recursion\n");
			   s.top=-1; // initialise top=-1
      		   preorder_nonrec(root);
       	break;
		case 6:printf("\nEnter the search data:");
       			scanf("%d",&srno);
       			temp=search(root,srno);
       			if(temp==NULL)
					printf("\n Node is not found in the tree\n");
				else
					printf("\n The node having data %d is found\n",temp->data);
       	break;
		case 7:root=del(root);
			   inorder_rec(root);// call inorder
       	break;
		default: exit(0);
	}// end of switch...case

  } while(ch!=8); // end of do...while
  return 0;
} // end of main



// Creation of tree
 node *createbstree(node *root)
 {
 node *newnode=NULL,*oldnode=NULL;
 char ch;
 do
 {
  newnode=getnode();
  if(root==NULL)
  	root=newnode;
  
  else
  {
   oldnode=root;
   while(1)
   {
   	if(newnode->data < oldnode->data)
   	{
   		if(oldnode->lchild==NULL)
   		{
   			oldnode->lchild=newnode;
   			break;
   		}
   		else
   			oldnode=oldnode->lchild;	
   	}
   	else
   	{
   		if(newnode->data > oldnode->data)
   		{
   			if(oldnode->rchild==NULL)
   			{
   				oldnode->rchild=newnode;
   				break;
   			}
   			else
   				oldnode=oldnode->rchild;
   			
   		}
		else
		{
			printf("\nDuplicate node cant be created!");
			break;
		}
     }//end of else
   }//end of while
  }//end of outer else
   printf("\nDo you want to add more nodes?(y/n)");
   scanf(" %c",&ch);
 }while(ch!='n');//end of do...while
   return root;
}//end of  Creation of tree function

// get the node
node *getnode()
{
   node *temp=NULL;
   temp=(node*)malloc(sizeof(node));

    if(temp==NULL)
    {
   	printf("\nmemory allocation error!");
   	exit(0);
    }
    else
    {
   	temp->lchild=NULL;
	temp->rchild=NULL;
	printf("\nenter the data:");
	scanf("%d",&temp->data);
    }
   return temp;
}// end of get node function

// search the node
   node *search(node *pt,int srno)
   {
	   if(pt==NULL)
			return NULL;
		while(pt)
		{
			if(srno==pt->data)
				return pt;
			else if(srno < pt->data)
				pt=pt->lchild;
			else
				pt=pt->rchild;
		}
	return NULL;
	}// end of search fuction


// Inorder traversing using recursive function
void inorder_rec(node *pt)
{
	if(pt!=NULL)
	{
		inorder_rec(pt->lchild);
		printf("\t%d",pt->data);
		inorder_rec(pt->rchild);
	}
}

// Preorder traversing using recursive function
void preorder_rec(node *pt)
{
	  if(pt!=NULL)
	  {
	  	printf("\t%d",pt->data);
	  	preorder_rec(pt->lchild);
	  	preorder_rec(pt->rchild);
	  }
}

// Postorder traversing using recursive function
void postorder_rec(node *pt)
{
	  if(pt!=NULL)
	  {
	  	postorder_rec(pt->lchild);
	  	postorder_rec(pt->rchild);
	  	printf("\t%d",pt->data);
	  }
}

// Push function 
void push(node *pt)
{
	  if(checkfull())
	  	printf("overflow!");
	  else
	  {
	  	s.top++;
	  	s.item[s.top]=pt;
	  }
}

// Pop function 
node *pop()
{
 node *pt=NULL;
 if(checkempty())
	  printf("underflow!");
 else
 {
	  pt=s.item[s.top];
	  s.top--;
 }
return pt;
}

// stack empty function
int checkempty()
{
	  if(s.top== -1)
	  	return 1;
	  else
	  	return 0;
}

// stack full function
int checkfull()
{
	  if(s.top==max-1)
	  	return 1;
	  else
	  	return 0;
}

// Inorder traversing using non-recursive function
void inorder_nonrec(node *root)
{
 node *pt=NULL;
 if(root==NULL)
	printf("\n tree is empty!");
 else
 {	  
	pt=root;
	while(1)
	{
		while(pt!=NULL)
	  	{
	  		push(pt);
	  		pt=pt->lchild;
	  	}
	  	if(checkempty())
	  		break;
	  	pt=pop();
	  	printf("\t%d",pt->data);
	  	pt=pt->rchild;
	}
  }
}

// Preorder traversing using non-recursive function
void preorder_nonrec(node *root)
{
 node *pt=NULL;
 if(root==NULL)
	printf("\n tree is empty!");
 else
 {	 
	pt=root;
	while(1)
	{
		while(pt!=NULL)
	  	{
	  		printf("\t%d",pt->data);
	  		push(pt);
	  		pt=pt->lchild;
	  	}
	  	if(checkempty())
	  		break;
	  	pt=pop(); 
	  	pt=pt->rchild;
	}
  }
}


// Delete the node
node *del(node *root)
{
int no;
node *temp,*prev,*x,*succ;
printf("\n\t enter the data to be deleted:");
scanf("%d",&no);
temp=root;
prev=temp;
 while(temp!=NULL)  // loop is used to search the node to be deleted and its parent
 {
	if(temp->data==no)
		break;
	prev=temp;
	if(no < temp->data)
	 	temp=temp->lchild;
	else	 
	  	temp=temp->rchild;
 }//end of while
	  
 if(temp->lchild==NULL &&temp->rchild==NULL)
 {
   	if(prev->lchild==temp)
		prev->lchild=NULL;
	else
		prev->rchild=NULL;
  printf("\n Leaf node is deleted\n");
 }	  
 else if(temp->rchild!=NULL && temp->lchild==NULL)
 {
	  if(prev->lchild==temp)
		prev->lchild=temp->rchild;
	  else
		prev->rchild=temp->rchild;
  printf("\n Node with right subtree is deleted\n");
 }	  
 else if(temp->rchild==NULL && temp->lchild!=NULL)
 {
	  if(prev->lchild==temp)
		prev->lchild=temp->lchild;
	  else
		prev->rchild=temp->lchild;
   printf("\n Node with left subtree is deleted\n");	  
 }  	
else if(temp->lchild!=NULL && temp->rchild!=NULL)
{ 
 succ=temp;
 x=temp->rchild;
 	while(x!=NULL)
 	{
		prev=succ;
		succ=x;
		x=x->lchild;
	}
	temp->data=succ->data;
	if(temp->rchild!=succ)
		prev->lchild=succ->rchild; 
		
	else
		prev->rchild=succ->rchild;
			
	temp=succ;
   printf("\n Node with both subtree is deleted using inoreder successor method\n");
 }
 
free(temp);

return root;
 
}
