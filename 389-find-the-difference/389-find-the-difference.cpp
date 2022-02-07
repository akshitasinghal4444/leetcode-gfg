class Solution {
public:
    char findTheDifference(string s, string t) {
        int f[26]={0};
        
        int n=s.length(),i;
        for(i=0;i<n;i++)
        {
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }
        f[t[i]-'a']--;
        
        for(i=0;i<26;i++)
        {
            if(f[i]==-1)
                return (i+'a');
        }
        return 'a';
    }
};