class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l=0,r=0;
        string t="";
        stack<char> st;
        
        for(char ch:s)
        {
            if(ch=='(')
            {
                l++;
                st.push('(');
            }
            else if(ch==')')
            {
                if(l>r)
                { 
                    r++;
                    st.push(')');
                }
            }
            else 
                st.push(ch);
        }
        
        l=0;
        r=0;
        
        while(!st.empty())
        {
            char ch=st.top();
            st.pop();
            
            if(ch==')')
            {
                r++;
                t+=ch;
            }
            else if(ch=='(')
            {
                if(r>l)
                {
                    l++;
                    t+=ch;
                }  
            }
            else
               t+=ch; 
        }
        
        reverse(t.begin(),t.end());
        return t;
    }
};