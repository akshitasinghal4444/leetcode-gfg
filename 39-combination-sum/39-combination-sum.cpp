class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    int s;
    
    void sum(vector<int>& a, int t,int n,int in)
    {
        if(s==t)
        {
            ans.push_back(x);
            return ;
        }
        
        if(in==n || s>t)
            return;
        
        sum(a,t,n,in+1);
        
        x.push_back(a[in]);
        s+=a[in];
        sum(a,t,n,in);
        s-=a[in];
        x.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t)
    {
        int n=a.size();
        s=0;
        sum(a,t,n,0);
        return ans;
    }
    
    /*
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        int i,j,n=a.size();
        vector<vector<int>> ans;
        vector<vector<vector<int>>> dp(t+1);
        dp[0].push_back({});
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=t;j++)
            {
                if(a[i]<=j)
                {
                    for(auto v:dp[j-a[i]])
                    {
                        v.push_back(a[i]);
                        dp[j].push_back(v);
                    }
                }
            }
        }
                                  
        return dp[t]; 
    }
    */
};