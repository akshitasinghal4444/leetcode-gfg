//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int n) {
        // code here
        unordered_map<int,vector<pair<int,int>>> m;
        int i,j;
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int s=a[i]+a[j];
                
                if(m[s].empty() || (m[s].back().second!=i && m[s].back().first!=i))
                m[s].push_back({i,j});
            }
        }
        
        for(auto it:m)
        {
            if(it.second.size()>1)
            {
                vector<int> t;
                t.push_back(it.second[0].first);
                t.push_back(it.second[0].second);
                t.push_back(it.second[1].first);
                t.push_back(it.second[1].second);
                
                if(ans.empty() || t<ans)
                ans=t;
            }
        }
        
        if(ans.empty())
        return {-1,-1,-1,-1};
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends