class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int ans=0;
        int pwr=0;
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
    int scoreOfParentheses(string s) 
    {
        stack<int> st;
        
        for(char ch:s)
        {
            if(ch=='(')
                st.push(-1);
            else
            {
                int x=0;
                while(!st.empty() && st.top()!=-1)
                {
                    x+=st.top();
                    st.pop();
                }
                
                st.pop();
                
                if(x==0)
                    st.push(1);
                else
                    st.push(2*x);
            }
        }
        
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
    */

};
