class Solution {
public:
    bool canConstruct(string r, string m) {
        int f[26]={0};
        
        for(char c:m)
            f[c-'a']++;
        
        for(char c:r)
        {
            f[c-'a']--;
            if(f[c-'a']<0)
                return 0;
        }
        
        return 1;
    }
};