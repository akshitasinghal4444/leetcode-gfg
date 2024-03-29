class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        
        int i,n=s.length();
        int dp[n];
        dp[0]=1;
        
        for(i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='0' || s[i-1]>'2')
                    return 0;
                
                dp[i]=(i-2>=0)?dp[i-2]:1;
            }
            else
            {
                dp[i]=dp[i-1];
                
                if(s[i-1]!='0')
                {
                    string t="";
                    t+=s[i-1];
                    t+=s[i];
                    if(stoi(t)<=26)
                        dp[i]+=(i-2>=0)?dp[i-2]:1;
                }
                 
            }
        }
        
        return dp[n-1];
    }
};