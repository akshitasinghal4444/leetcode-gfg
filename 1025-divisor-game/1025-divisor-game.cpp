class Solution {
public:
    /*
    vector<int> factors(int n)
    {
        vector<int> a;
        int i;
        
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
                a.push_back(i);
        }
        return a;
    }
    
    bool divisorGame(int n)
    {
        bool dp[n+1];
        dp[0]=0;
        dp[1]=0;
        
        int i,j;
        for(i=2;i<=n;i++)
        {
            vector<int> a;
            a=factors(i);
            
            for(j=0;j<a.size();j++)
            {
                if(dp[i-a[j]]==0)
                {
                    dp[i]=1;
                    break;
                }
                dp[i]=0;
            }
        }
        return dp[n];
    }
    */
   
    bool divisorGame(int n) {
        return (n%2==0);
    }
    
};