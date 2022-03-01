class Solution {
public:
    int longestValidParentheses(string s)
    {
        int l=0,r=0,ans=0;
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            
            if(l==r)
                ans=max(ans,2*r);
            else if(r>l)
                l=r=0;
        }
        
        l=r=0;
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                l++;
            else
                r++;
            
            if(l==r)
                ans=max(ans,2*l);
            else if(l>r)
                l=r=0;
        }
        return ans;
    }
    
    /*
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int i,n=s.length();
        int ans=0;
        
        st.push(-1);
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    ans=max(ans,i-st.top());
            }
        }
        return ans;
    }
    */
    
    /*
    int longestValidParentheses(string s) {
        
        stack<char> s1;
        stack<int> s2;
        int ans=0;
        int i,n=s.length();
        
        s2.push(-1);
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                s1.push('(');
                s2.push(i);   
            }
            else
            {
                if(!s1.empty())
                {
                    s1.pop();
                    s2.pop();
                    
                    ans=max(ans,i-s2.top());
                }
                else
                    s2.push(i);
            }
        }
        return ans;
    }
    */
};