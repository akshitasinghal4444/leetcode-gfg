class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns=s.length(),np=p.length();
        vector<int> fs(26,0),fp(26,0);
        int i,j;
        vector<int> ans;
        
        if(ns<np)
            return ans;
        
        for(i=0;i<np;i++)
            fp[p[i]-'a']++;
        
        for(i=0;i<np;i++)
            fs[s[i]-'a']++;
        
        if(fs==fp)
            ans.push_back(0);
        
        for(;i<ns;i++)
        {
            fs[s[i]-'a']++;
            fs[s[i-np]-'a']--;
            
            if(fs==fp)
                ans.push_back(i-np+1);
        }
        
        return ans;
    }
    
    /*
    vector<int> findAnagrams(string s, string p) {
        int ns=s.length(),np=p.length();
        int fs[26]={0},fp[26]={0};
        int i,j;
        vector<int> ans;
        bool same=1;
        
        if(ns<np)
            return ans;
        
        for(i=0;i<np;i++)
            fp[p[i]-'a']++;
        
        for(i=0;i<np;i++)
            fs[s[i]-'a']++;
        
        for(j=0;j<26;j++)
        {
            if(fs[j]!=fp[j])
            {
                same=0;
                break;
            }
        }
        
        if(same)
            ans.push_back(0);
        
        for(;i<ns;i++)
        {
            fs[s[i]-'a']++;
            fs[s[i-np]-'a']--;
            same=1;
            
            for(j=0;j<26;j++)
            {
                if(fs[j]!=fp[j])
                {
                    same=0;
                    break;
                }
            }
        
            if(same)
                ans.push_back(i-np+1);
        }
        
        return ans;
    }
    */
};