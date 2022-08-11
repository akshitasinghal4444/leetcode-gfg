class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i,n=s.length();
        unordered_map<char,char> st,ts;
        
        for(i=0;i<n;i++)
        {
            if(st.find(s[i])==st.end())
            {
                if(ts.find(t[i])==ts.end())
                {
                    st[s[i]]=t[i];
                    ts[t[i]]=s[i];
                }
                else
                    return 0;
            }
            else if(st[s[i]]!=t[i])
            return 0;
        }
        
        return 1;
    }
};