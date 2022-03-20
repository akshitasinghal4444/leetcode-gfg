class Solution {
public:
    
    bool wordBreak(string &s,int n,int i,unordered_set<string> &words, vector<int> &dp)
    {
        if(i==n)
            return 1;
        
        int j=i;
        if(dp[j]==-1)
        {
            string t="";
            for(i;i<n;i++)
            {
                t+=s[i];
                if(words.find(t)!=words.end())
                {
                    if(wordBreak(s,n,i+1,words,dp))
                    {
                        dp[j]=1;
                        return 1;
                    }
                }
            }
            dp[j]=0;
        }
        
       return dp[j]==1;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        
        int n=s.length();
        vector<int> dp(n+1,-1);
        
        return wordBreak(s,n,0,words,dp);
    }
};