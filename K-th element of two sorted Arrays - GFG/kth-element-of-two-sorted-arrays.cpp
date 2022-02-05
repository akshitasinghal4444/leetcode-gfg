// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int a1[], int a2[], int n1, int n2, int k)
    {
        if(n1>n2)
        return kthElement(a2,a1,n2,n1,k);
        
        int l,h,cut1,cut2;
        h=min(n1,k);
        if(k<=n2)
        l=0;
        else
        l=k-n2;
        
        while(l<=h)
        {
            cut1=(l+h)/2;
            cut2=k-cut1;
            
            int l1,l2,r1,r2;
            
            l1=(cut1==0)?INT_MIN:a1[cut1-1];
            l2=(cut2==0)?INT_MIN:a2[cut2-1];
            
            r1=(cut1==n1)?INT_MAX:a1[cut1];
            r2=(cut2==n2)?INT_MAX:a2[cut2];
            
            if(l1<=r2 && l2<=r1)
            return max(l1,l2);
            
            if(l1>r2)
            h=cut1-1;
            else
            l=cut1+1;
        }
        return -1;
    }
    
    /*
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
    */
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