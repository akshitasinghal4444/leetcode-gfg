class Solution {
public:
    bool closeStrings(string s1, string s2) {
        
        if(s1.length()!=s2.length())
            return 0;
        
        int f1[26]={0},f2[26]={0};
        unordered_map<int,int> m;
        
        for(char c:s1)
            f1[c-'a']++;
        
        for(char c:s2)
            f2[c-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if((f1[i]==0 && f2[i]!=0) || (f1[i]!=0 && f2[i]==0))
                return 0;
            
            if(f1[i])
            {
                m[f1[i]]++;
                m[f2[i]]--;
            }
        }
         
        for(auto it:m)
        {
            if(it.second)
                return 0;
        }
        
        return 1;
    }
};