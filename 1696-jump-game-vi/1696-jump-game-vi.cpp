class Solution {
public:
    
    int maxResult(vector<int>& a, int k)
    {
        int i,j,n=a.size();
        vector<int> dp(n,INT_MIN);
        multiset<int> s;
        
        dp[0]=a[0];
        s.insert(a[0]);
        
        for(i=1;i<n;i++)
        {
            // cout<<(*s.rbegin())<<endl;
            dp[i]=a[i]+(*s.rbegin());
            s.insert(dp[i]);
            
            if(s.size()>k)
                s.erase(s.find(dp[i-k]));
        }
        
        return dp[n-1];
    }
    
    /*
    //tle
    
    int maxResult(vector<int>& a, int k) {
        int i,j,n=a.size();
        vector<int> dp(n,INT_MIN);
        dp[0]=a[0];
        
        for(i=0;i<n;i++)
            for(j=1;j<=k && i-j>=0;j++)
                dp[i]=max(dp[i],a[i]+dp[i-j]);
        
        return dp[n-1];
    }
    */
};