class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i,n=s.length();
        int len=1<<k;
        unordered_set<string> st;
        
        if(n<len)
            return false;
        
        string t="";
        for(i=0;i<k;i++)
            t+=s[i];
        
        st.insert(t);
        
        for(i;i<n;i++)
        {
            t=t.substr(1)+s[i];
            st.insert(t);
            
            if(st.size()==len)
                return true;
        }
        
        return false;
    }
};