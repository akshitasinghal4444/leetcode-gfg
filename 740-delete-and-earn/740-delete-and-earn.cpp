class Solution {
public:
    int deleteAndEarn(vector<int>& a)
    {
        int mx=*(max_element(a.begin(),a.end()));
        int mn=*(min_element(a.begin(),a.end()));
        int n=mx-mn+1;
                 
        vector<int> dp(n,0);
        
        for(int x:a)
            dp[x-mn]+=x; 
                 
        int inc=0,exc=0;
        
        for(int i=0;i<n;i++)
        {
            int ninc,nexc;
            ninc=exc+dp[i];
            nexc=max(inc,exc);
            
            inc=ninc;
            exc=nexc;
        }
        return max(inc,exc);
    }
    
    /*
    int deleteAndEarn(vector<int>& a) {
        int n=a.size();
        int i,ans=0;
        
        int mx=*(max_element(a.begin(),a.end()));
        int mn=*(min_element(a.begin(),a.end()));
        
        vector<int> dp(mx-mn+1,0);
        for(i=0;i<n;i++)
            dp[a[i]-mn]+=a[i];
        
        n=mx-mn+1;
        if(n>1)
        dp[1]=max(dp[0],dp[1]);
        for(i=2;i<n;i++)
        {
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
    */
};