class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int i,n=s.length();
        unordered_map<char,char> m;
        
        for(i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i])
                    return 0;
            }
            else
                m[s[i]]=t[i];
        }
        
        m.clear();
        for(i=0;i<n;i++)
        {
            if(m.find(t[i])!=m.end())
            {
                if(m[t[i]]!=s[i])
                    return 0;
            }
            else
                m[t[i]]=s[i];   
        }
        
        return 1;
    }
    
    /*
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
    */
};