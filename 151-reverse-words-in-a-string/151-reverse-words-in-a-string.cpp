class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string t="",ans="";
        
        for(char c:s)
        {
            if(c==' ')
            {
                if(!t.empty())
                    st.push(t);
                t="";
            }
            else
             t+=c;
        }
        
        if(!t.empty())
            st.push(t);
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        
        ans.pop_back();
        return ans;
    }
};