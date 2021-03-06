// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        
        /*
        void merge(long long a1[], long long a2[], int n1, int n2) 
        { 
            // code here 
            int i,j;
            i=n1-1,j=0;
    
            while(i>=0 && j<n2)
            {
                if(a1[i]>a2[j])
                {
                    int t=a1[i];
                    a1[i]=a2[j];
                    a2[j]=t;
            
                    i--;
                    j++;
                }
                else
                    break;
            }
    
            sort(a1,a1+n1);
            sort(a2,a2+n2);
        } 
        */
        
        void merge(long long a1[], long long a2[], int n1, int n2)
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
        
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends