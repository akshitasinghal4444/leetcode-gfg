class Solution {
public:

    int change(int amt, vector<int>& a) {
        int n=a.size();
        int i,j;
        
        vector<int> dp(amt+1,0);
        dp[0]=1;
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=amt;j++)
            {
                if(a[i]<=j)
                    dp[j]+=dp[j-a[i]];
            }
        }    
        return dp[amt];
    }
    
};