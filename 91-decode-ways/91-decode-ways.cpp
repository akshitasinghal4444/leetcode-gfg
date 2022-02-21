class Solution {
public:
    
    int numDecodings(string s)
    {
        if(s[0]=='0')
            return 0;
        
        int n=s.length();
        int dp[n];
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')      //10,20
                    dp[i]=(i-2>=0)?dp[i-2]:1;
                else                                //00,30,40,....
                    return 0;
            }
            else
            {
                dp[i]=dp[i-1];                      //0 !0
                
                if(s[i-1]!='0')
                {
                    string x="";
                    x+=s[i-1];
                    x+=s[i];
                    if(stoi(x)<=26)                 //!0 !0 
                        dp[i]+=(i-2>=0)?dp[i-2]:1;
                }
            }
        }
        return dp[n-1];
    }
    
    /*
    int numDecodings(string s)
    {
        int n=s.length();
        if(n==0 || s[0]=='0')
            return 0;
        
        int i;
        vector<int> dp(n,0);
        dp[0]=1;
        
        for(i=1;i<n;i++)
        {
            if(s[i]=='0' && s[i-1]=='0')
                return 0;
            
            if(s[i]!=0 && s[i-1]=='0')
            {
                dp[i]=dp[i-1];
            }
            else if(s[i]=='0' && s[i-1]!='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                    dp[i]=(i-2>=0)?dp[i-2]:1;
                else
                    return 0;
            }
            else
            {
                dp[i]=dp[i-1];
                
                string x="";
                x+=s[i-1];
                x+=s[i];
                
                if(stoi(x)<=26)
                    dp[i]+=(i-2>=0)?dp[i-2]:1;
            }
        }
        return dp[n-1];
    }
    */
};