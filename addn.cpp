#include<stdio.h>

struct poly{
	int coeff,expo;
}p1[10],p2[10],p3[20];

int main(){
	int n,m,i,j=0,k=0;
	printf("Enter the number of terms in the first polynomial : ");
	scanf("%d",&n);
	printf("\nEnter the number of terms in the second polynomial : ");
	scanf("%d",&m);
	printf("\nEnter the coeffcients and exponents for the first polynomial :- ");
	for(i=0;i<n;i++){
		printf("\nEnter the coeff and expo : ");
		scanf("%d %d",&p1[i].coeff,&p1[i].expo);
	}
	printf("\nFirst polynomial is : ");
	for(i=0;i<n;i++){
		printf("%dx^%d ",p1[i].coeff,p1[i].expo);
		if(i<n-1){
			printf("+ ");
		}
	}
	printf("\nEnter the coeffcients and exponents for the second polynomial :- ");
	for(i=0;i<m;i++){
		printf("\nEnter the coeff and expo : ");
		scanf("%d %d",&p2[i].coeff,&p2[i].expo);
	}
	printf("\nSecond polynomial is : ");
	for(i=0;i<m;i++){
		printf("%dx^%d ",p2[i].coeff,p2[i].expo);
		if(i<m-1){
			printf("+ ");
		}
	}
	i=0;
	while(i<n || j<m){
		if(p1[i].expo==p2[j].expo){
			p3[k].coeff=p1[i].coeff+p2[j].coeff;
			p3[k].expo=p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo){
			p3[k]=p1[i];
			i++;
			k++;
		}
		else{
			p3[k]=p2[j];
			k++;
			j++;
		}
	}
	printf("\nResultant polynomial is : ");
	for(i=0;i<k;i++){
		printf("%dx^%d ",p3[i].coeff,p3[i].expo);
		if(i<k-1){
			printf("+ ");
		}
	}
}
