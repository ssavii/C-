#include <stdio.h>

int main()
{
    

        int arr[10],i=0,j=0,n=0,k=0,ch,cc=0,sc=0,pos,temp,small,index;
    printf("\n1: BUBBLE SORT \n2: SELECTION SORT\n3: INSERTION SORT");
    printf("\nEnter the choice :");
    scanf("%d",&ch);
    
    switch (ch)
    {
        case 1: cc=0,sc=0;
        printf("Enter the number of elements of the array");
        scanf("%d",&n);
        printf("Enter the array");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Given array \n");
        for(i=0;i<n;i++)
        {
            printf("arr[%d]=%d\t",i,arr[i]);
        }
        printf("\n----------------------BUBBLE SORT--------------------\n");
        
        for (i=0;i<n-1;i++)
        {
            for (j=0 ; j<n-1-i; j++)
            {
                printf("\n");
                cc++;
                if (arr[j] > arr[j+1])
                { 
                    sc++;
                    temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp;
                    
                }
                
            }
            
        }
        for(k=0;k<n;k++)
        {
            printf("arr[%d]=%d\t",k,arr[k]);
        }
        printf("\nComparison count - %d\n Swapping count - %d",cc,sc);
        break;
        
        case 2: cc=0,sc=0;
        printf("Enter the number of elements of the array");
        scanf("%d",&n);
        printf("Enter the array");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Given array \n");
        for(i=0;i<n;i++)
        {
            printf("arr[%d]=%d\t",i,arr[i]);
        }
        printf("\n----------------------SELECTION SORT--------------------\n");
        for(i =0;i<n-1;i++)
        {
            small=arr[i];
            pos=i;
            for (j =i+1; j<n; j++) 
            {
                printf("\n");
                cc++;
                if (arr[j] < small)
                {
                    small=arr[j];
                    pos=j;
                }
                
            }
            temp=arr[pos]; 
            arr[pos]=arr[i];
            arr[i]=temp;
            sc++;
        }
            for(k=0;k<n;k++)
        {
            printf("arr[%d]=%d\t",k,arr[k]);
        }
        printf("\nComparison count - %d\nSwapping count - %d",cc,sc);
        break;
        
        case 3: cc=0,sc=0;
        printf("Enter the number of elements of the array");
        scanf("%d",&n);
        printf("Enter the array");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("Given array \n ");
        for(i=0;i<n;i++)
        {
            printf("arr[%d]=%d\t",i,arr[i]);
        }
        printf("\n----------------------INSERTION SORT--------------------\n");
        for (i = 1;i<n;i++)
        {
            index = arr[i];
            for(j=i-1;j>=0;j--)
            {
                cc++;
                if(arr[j] > index)
                {
                    arr[j+1]=arr[j];
                    sc++;
                }
                else
                break;
            }
                arr[j+1]=index;
        }
         for(k=0;k<n;k++)
        {
            printf("arr[%d]=%d\t",k,arr[k]);
        }
        printf("\nComparison count - %d\n Swapping count - %d",cc,sc);
        break;

    }


}
