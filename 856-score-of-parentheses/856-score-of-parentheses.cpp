class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int pwr=0;
        int ans=0;
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                pwr++;
            else 
            {
                pwr--;
                if(s[i-1]=='(')
                    ans+=(1<<pwr);
            }
        }
        return ans;
    }
    
    /*
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
    */
};
