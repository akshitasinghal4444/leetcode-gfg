class Solution {
public:
    string reverseParentheses(string s) {
        
        string ans="";
        for(char ch:s)
        {
            if(ch==')')
            {
                string t="";
                while(ans.back()!='(')
                {
                    t+=ans.back();
                    ans.pop_back();
                }
                ans.pop_back();
                
                for(char c:t)
                    ans+=c;
            }
            else
                ans+=ch;
        }

        return ans;
    }
    
    /*
    string reverseParentheses(string s) {
        stack<char> st;
        string ans="";
        
        for(char ch:s)
        {
            if(ch==')')
            {
                string t="";
                while(!st.empty() && st.top()!='(')
                {
                    t+=st.top();
                    st.pop();
                }
                st.pop();
                
                for(char c:t)
                    st.push(c);
            }
            else
                st.push(ch);
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    */
};