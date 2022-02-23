#include<stdio.h>
#include<stdlib.h>


int main(){
	int n,i,temp,k,arr[100],choice,mid,max,min=0,key,pos,cmp=0,flag=0,con=1,j=1;
	do{
		printf("\nEnter number of elements :");
		scanf("%d",&n);
		max=n-1;
		mid=(min+max)/2;
		printf("\nEnter array elements: ");
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		printf("\nEnter element to be searched: ");
		scanf("%d",&key);
		printf("\nEnter the type of searching algo to be used - 1.Binary Search 2.Linear Search: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				cmp=flag=0;
				for(i=0;i<n;i++){
					for(k=0;k<n-i;k++){
						if(arr[k]>arr[k+1]){
							temp=arr[k+1];
							arr[k+1]=arr[k];
							arr[k]=temp;
						}
					}
				}
				while(1){
					cmp++;
					//How to exit while loop if element is absent?
					if(min>max){
						break;
					}
					else if(arr[mid]==key){
						flag=1;
						pos=mid;
						printf("\nKey is present at position : %d",pos);
						printf("\nTotal number of comparisons : %d",cmp);
						break;	
					}
					else if(arr[mid]<key){
						min=mid+1;
						mid=(min+max)/2;
					}
					else
					{
						max=mid-1;
						mid=(min+max)/2;
					}	
				}
				if(flag==0){
					printf("\nElement not found!");
				}


				break;

			case 2: 
				cmp=flag=0;
				
				for(i=0;i<n;i++){
					cmp++;
					if(key==arr[i]){
						flag=1;
						pos=i;
						printf("\nKey is present at position : %d",pos);
						printf("\nTotal number of comparisons : %d",cmp);
						break;
					}	
				}
				if(flag==0){
					printf("\nElement not found!");
				}
				break;
			default:printf("\nIncorrect opt.! Try again.");
		}
		printf("\nWant to continue? 1-Yes 2-No : ");
		scanf("%d",&con);	
	}while(con==1);

}
