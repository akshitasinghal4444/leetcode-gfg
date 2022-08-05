class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,n=s.length(),ans=0,st=0;
        vector<int> mp(256,-1);
        
        for(i=0;i<n;i++)
        {
            if(mp[s[i]]<st)
                mp[s[i]]=i;
            else
            {
                ans=max(ans,i-st);
                st=mp[s[i]]+1;
                mp[s[i]]=i;
            }
        }
        ans=max(ans,i-st);
        return ans;
    }
};