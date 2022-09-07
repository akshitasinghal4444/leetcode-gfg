class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> f(256,-1);
        int i,n=s.length();
        int st=0,ans=0;
        
        for(i=0;i<n;i++)
        {
            if(f[s[i]]==-1 || f[s[i]]<st)
                f[s[i]]=i;
            else
            {
                ans=max(ans,i-st);
                st=f[s[i]]+1;
                f[s[i]]=i;
            }
        }
        
        ans=max(ans,i-st);
        
        return ans;
    }
};