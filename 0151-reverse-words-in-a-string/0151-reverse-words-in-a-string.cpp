class Solution {
public:
    string reverseWords(string s) {
        string t="",ans="";
        
        for(char c:s)
        {
            if(c==' ')
            {
                if(!t.empty())
                {
                    reverse(t.begin(),t.end());
                    ans+=t;
                    ans+=" ";
                }
                t="";
            }
            else
                t+=c;
        }
        
        if(!t.empty())
        {
            reverse(t.begin(),t.end());
            ans+=t;
            ans+=" ";
        }
        
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    
    /*
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
    */
};