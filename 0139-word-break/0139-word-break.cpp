class Solution {
public:
    
    bool wordBreak(string s,unordered_set<string> &words,int in,int n,vector<int> &dp)
    {
        if(in==n)
            return 1;
        
        
        if(dp[in]==-1)
        {
            dp[in]=0;
            string t="";
        
            for(int i=in;i<n;i++)
            {
                t+=s[i];
                if(words.find(t)!=words.end() && wordBreak(s,words,i+1,n,dp))
                {
                    dp[in]=1;
                    break;
                }
            }
        }
              
        return dp[in];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length(),-1);
        
        return wordBreak(s,words,0,s.length(),dp);
    }
};