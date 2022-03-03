class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        
        for(char c:s)
        {
            if(c=='(')
                st.push(-1);
            else
            {
                if(st.top()==-1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int x=0;
                    while(!st.empty() && st.top()!=-1)
                    {
                        x+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*x);
                }
            }
        }
        int x=0;
        while(!st.empty())
        {
            x+=st.top();
            st.pop();
        }
        
        return x;
    }
};
