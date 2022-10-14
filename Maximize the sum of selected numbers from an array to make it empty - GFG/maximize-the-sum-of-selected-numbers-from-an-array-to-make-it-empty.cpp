//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        int ans=0;
        int i,m=1e5+1;
        int f[m]={0};
        
        for(i=0;i<n;i++)
            f[a[i]]++;
        
        for(i=m-1;i>0;)
        {
            if(f[i]<=0)
            {
                i--;
                continue;
            }
            
            ans+=i;
            
            f[i]--;
            f[i-1]--;

        }
        
        return ans;
    }
    
    /*
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        int ans=0;
        int i;
        map<int,int> m;
        
        for(i=0;i<n;i++)
            m[a[i]]++;
            
        
        for(auto it=m.rbegin();it!=m.rend();)
        {
            if(it->second<=0)
            {
                it++;
                continue;
            }
            
            ans+=it->first;
            
            m[it->first]--;
            m[it->first-1]--;

        }
        
        return ans;
    }
    */
};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends