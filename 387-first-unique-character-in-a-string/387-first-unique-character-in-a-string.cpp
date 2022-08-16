class Solution {
public:
    int firstUniqChar(string s) {
        int i,n=s.length();
        int f[26]={0};
        
        for(i=0;i<n;i++)
            f[s[i]-'a']++;
            
        for(i=0;i<n;i++)
        {
            if(f[s[i]-'a']==1)
                return i;
        }
        
        return -1;;
    }
};