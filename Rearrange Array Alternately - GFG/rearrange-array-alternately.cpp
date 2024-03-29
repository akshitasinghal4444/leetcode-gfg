//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    
    void rearrange(long long *a, int n) 
    {
        int i,maxi=n-1,mini=0;
        long long mx=a[n-1]+1;
        
        for(i=0;i<n;i++)
        {
            if(i%2==0)
            {
                a[i]=a[i]+(a[maxi]%mx)*mx;
                maxi--;
            }
            else
            {
                a[i]=a[i]+(a[mini]%mx)*mx;
                mini++;
            }
        }
        
        for(i=0;i<n;i++)
        a[i]/=mx;
    }
    
    /*
    void rearrange(long long *a, int n) 
    { 
    	// Your code here
    	vector<long long> t(a,a+n);
    	int i,j;
    	
    	for(i=0,j=n-1;i<n;i+=2,j--)
    	a[i]=t[j];
    	
    	for(i=1,j=0;i<n;i+=2,j++)
    	a[i]=t[j];
    }
    */
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends