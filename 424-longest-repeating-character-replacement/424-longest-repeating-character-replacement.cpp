class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i,j,st;
        int ans=1,maxf=0;
        int f[26]={0};
        
        for(i=0,st=0;i<n;i++)
        {
            f[s[i]-'A']++;
            maxf=max(maxf,f[s[i]-'A']);
            
            int len=i-st+1;
            if(len-maxf>k)
            {
                f[s[st]-'A']--;
                st++;
            }
            else
                ans=max(ans,len);
        }
        
        return ans;
    }
};