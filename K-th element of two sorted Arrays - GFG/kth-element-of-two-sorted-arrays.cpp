// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int a1[], int a2[], int n1, int n2, int k)
    {
        int i=0,j=0;
        
        while(i<n1 && j<n2)
        {
            k--;
            
            if(a1[i]<a2[j])
            {
                if(k==0)
                return a1[i];
                i++;
            }
            else
            {
                if(k==0)
                return a2[j];
                j++;
            }
        }
        
        while(i<n1 && k>0)
        {
            k--;
            if(k==0)
                return a1[i];
            i++;
        }
        while(j<n2 && k>0)
        {
            k--;
            if(k==0)
                return a2[j];
            j++;
        }
        return -1;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends