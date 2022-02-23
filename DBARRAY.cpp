// C-
//Database management using array of structure with operations Create, Display, Modify, Append, Search, Sort.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	int roll, maths, DSA, DE, total;
	char name[10];
	float avg;
}s[10];//,temp;

void display(int);

int main()
{
	int i,n,ch,flag,pos,x,mr,mm,p,j,temp;
	char src[10],mn[10];
	printf("\n Enter total no. of student= ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter roll no= ");
		scanf("%d",&s[i].roll);
		printf("\n Enter name= ");
		scanf("%s",s[i].name);
		printf("\n Enter marks= ");
		scanf("%d%d%d",&s[i].maths,&s[i].DSA,&s[i].DE);
		s[i].total=s[i].maths+s[i].DSA+s[i].DE;
		printf("\n Total=%d", s[i].total);
		s[i].avg=(float)s[i].total/3;
		printf("\n Avg=%.2f",s[i].avg);
	}
	display(n);
	
	do{
		
		printf("\n Menu:\n1.Search by name\n2.Modify\n3.Append\n4.Sort\n5.Exit");
		printf("\n Enter your choice= ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:flag=0;
			printf("\n Enter name of the student to be search= ");
			scanf("%s",src);
			for(i=0;i<n;i++)
			{
				if(strcmp(src,s[i].name)==0)
				{
					flag=1;
					pos=i;
					break;
				}
			}
			if(flag==1)
				printf("\n %d\t %s\t %d\t %d\t %d\t %d\t %.2f",s[pos].roll,s[pos].name,s[pos].maths,s[pos].DSA, s[pos].DE,s[pos].total,s[pos].avg);
			else
				printf("\n Record not found");
			break;
			case 2:
			do{		
				printf("\n Menu:\n1.Modify roll no.\n2.Modify name\n3.Modify maths\n4.Exit");
				printf("\n Enter your choice= ");
				scanf("%d",&x);
				switch(x)
				{
					case 1:
					printf("\n Enter roll no. to be modify= ");
					scanf("%d", &mr);
					for(i=0;i<n;i++)
					{
						if(mr==s[i].roll)
						{
							printf("\n Enter new roll no= ");
							scanf("%d",&s[i].roll);
							display(n);
							break;
						}
					}					
					break;
					case 2:
					printf("\n Enter name of the student to be modify= ");
					scanf("%s",mn);
					for(i=0;i<n;i++)
					{
						if(strcmp(mn,s[i].name)==0)
						{
							printf("\n Enter ner name= ");
							scanf("%s",s[i].name);
							display(n);
							break;
						}
					}	
							
					break;
					case 3:
					printf("\n Enter thr roll no. whose maths marks to be modify= ");
					scanf("%d", &mm);
					for(i=0;i<n;i++)
					{
						if(mm==s[i].roll)
						{
							printf("\n Enter modified maths mark= ");
							scanf("%d", &s[i].maths);
							s[i].total=s[i].maths+s[i].DSA+s[i].DE;
							printf("\n Total=%d", s[i].total);
							s[i].avg=(float)s[i].total/3;
							printf("\n Avg=%.2f",s[i].avg);
							display(n);
							break;
						}
					}
					break;
					default: printf("\n Invalid choice");					
				}
			}while(x!=4);
			break;
			case 3:
			printf("\n Enter no. of students to added in database= ");
			scanf("%d", &p);
			for(i=n;i<n+p;i++)
			{
				printf("\n Enter roll no= ");
				scanf("%d",&s[i].roll);
				printf("\n Enter name= ");
				scanf("%s",s[i].name);
				printf("\n Enter marks= ");
				scanf("%d%d%d",&s[i].maths,&s[i].DSA,&s[i].DE);
				s[i].total=s[i].maths+s[i].DSA+s[i].DE;
				printf("\n Total=%d", s[i].total);
				s[i].avg=(float)s[i].total/3;
				printf("\n Avg=%.2f",s[i].avg);
			}
			n=n+p;
			display(n);
			break;
			case 4:
			printf("\n Bubble sort");
				for ( i = 0 ; i <n-1 ; i++ )// no. passes
				{   	  
					for ( j = 0 ; j < n-1-i ; j++ ) // no. of comparision
					{  
						if ( s[j].roll>s[j+1].roll )
						{
							temp=s[j].roll;
							s[j].roll=s[j+1].roll;
							s[j+1].roll=temp;
						}
					}
				}
				display(n);
			break;
			default:exit(0);
		}
		
		
	}while(ch!=5);
	
	
	return 0;
}

void display(int n)
{
	int i;
	printf("\n Roll\t Name\t maths\t DSA\t DE\t total\t avg");
	for(i=0;i<n;i++)
	{
		printf("\n %d\t %s\t %d\t %d\t %d\t %d\t %.2f",s[i].roll,s[i].name,s[i].maths,s[i].DSA, s[i].DE,s[i].total,s[i].avg);
	}
}
