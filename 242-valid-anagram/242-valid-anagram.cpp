class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return 0;
        
        int n=s.length();
        int f[26]={0};
        
        for(int i=0;i<n;i++)
        {
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(f[i]!=0)
                return 0;
        }
        return 1;
    }
};