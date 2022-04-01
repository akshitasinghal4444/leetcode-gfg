// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *a , int n) 
    { 
        // Complete the function
        if(n<3)
        return {-1};
        
        int i;
        long long p=1;
        vector<int> ans(1,-1);
        
        int rmax[n];
        rmax[n-1]=a[n-1];
        for(i=n-2;i>=0;i--)
        rmax[i]=max(rmax[i+1],a[i]);
        
        set<long long> s;
        for(i=0;i<n;i++)
        {
            auto x=s.insert(a[i]);
            auto it=x.first;
            
            if(it!=s.begin() && i!=n-1 && rmax[i+1]>a[i])
            {
                --it;
                if((*it)*a[i]*rmax[i+1]>p)
                {
                    p=(*it)*a[i]*rmax[i+1];
                    ans={*it,a[i],rmax[i+1]};
                }
            }
        }
        
        return ans;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends