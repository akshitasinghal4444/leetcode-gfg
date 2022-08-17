class Solution {
public:
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
};