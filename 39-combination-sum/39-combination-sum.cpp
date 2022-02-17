class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void helper(vector<int>& a, int in,int sum,int n,int t)
    {
        if(sum==t)
        {
            ans.push_back(v);
            return;
        }
        
        if(in==n)
            return;
        
        helper(a,in+1,sum,n,t);
        
        if(sum+a[in]<=t)
        {
            v.push_back(a[in]);
            helper(a,in,sum+a[in],n,t);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t)
    {
        int n=a.size();
        ans={};
        v={};
        
        helper(a,0,0,n,t);
        
        return ans;
    }
    
    /*
    vector<vector<int>> combinationSum(vector<int>& a, int t)
    {
        int n=a.size();
        int i,j;
        vector<vector<int>> dp[t+1];
        dp[0]={};
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=t;j++)
            {
                if(a[i]==j)
                {
                    dp[j].push_back({a[i]});
                }
                else if(a[i]<j)
                {
                    for(vector<int> v:dp[j-a[i]])
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
    
    /*
    vector<int> x;
    void helper(vector<int>& a,int n,int t,int i,vector<vector<int>> &ans)
    {
        if(t==0)
        {
            ans.push_back(x);
            return;
        }
        
        if(i==n || t<0)
            return;

        helper(a,n,t,i+1,ans);
        x.push_back(a[i]);
        helper(a,n,t-a[i],i,ans);
        x.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t)
    {
        int n=a.size();
        vector<vector<int>> ans;
        helper(a,n,t,0,ans);
        return ans;
    }
    
    */
};