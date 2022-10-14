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
        int i;
        map<int,int> m;
        
        for(i=0;i<n;i++)
            m[a[i]]++;
            
        // for(auto it:m)
        // cout<<it.first<<" "<<it.second<<endl;
        
        for(auto it=m.rbegin();it!=m.rend();)
        {
            
            
            if(it->second<=0)
            {
                it++;
                continue;
            }
            
            
            ans+=it->first;
            
            // cout<<it->first<<endl;
            
            m[it->first]--;
            m[it->first-1]--;

        }
        
        return ans;
    }

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