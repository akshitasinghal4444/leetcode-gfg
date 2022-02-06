// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

//Function to merge the arrays.
void merge(int a1[], int a2[], int n1, int n2)
{
    int gap=(n1+n2+1)/2;
    
    while(gap>0)
    {
        int i,j;
        i=0;
        j=(i+gap);
        
        while(j<n1)
        {
            if(a1[i]>a1[j])
            {
                int t=a1[i];
                a1[i]=a1[j];
                a1[j]=t;
            }
            i++;
            j++;
        }
        
        j-=n1;
        while(i<n1 && j<n2)
        {
            if(a1[i]>a2[j])
            {
                int t=a1[i];
                a1[i]=a2[j];
                a2[j]=t;
            }
            i++;
            j++;
        }
        
        i=0;
        while(j<n2)
        {
            if(a2[i]>a2[j])
            {
                int t=a2[i];
                a2[i]=a2[j];
                a2[j]=t;
            }
            i++;
            j++;
        }
        
        if(gap==1)
        break;
        
        gap=(gap+1)/2;
    }
}

/*
void merge(int a1[], int a2[], int n1, int n2)
{ 
    //code here
    int i,j;
    j=n2-1;
    
    while(j>=0)
    {
        i=n1-1;
        
        if(a2[j]<=a1[i])
        {
            int t=a1[i];
            i=i-1;
            while(i>=0 && a1[i]>a2[j])
            {
                a1[i+1]=a1[i];
                i--;
            }
            if(i>=-1)
            {
                a1[i+1]=a2[j];
                a2[j]=t;
            }
            
        }
        j--;
    }
}
*/

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}  // } Driver Code Ends