class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1,n2;
        n1=s.length();
        n2=p.length();
        if(n2>n1)
            return {};
        vector<int> h1(26,0),h2(26,0);
        vector<int> ans;
        int i,st=0;
        for(i=0;i<n2;i++)
            h1[p[i]-'a']++;
        
        for(i=0;i<n2;i++)
            h2[s[i]-'a']++;
        if(h1==h2)
            ans.push_back(st);
        
        for(i;i<n1;i++)
        {
            h2[s[st]-'a']--;
            st++;
            h2[s[i]-'a']++;
            if(h1==h2)
            ans.push_back(st);
        }
        return ans;
    }
};