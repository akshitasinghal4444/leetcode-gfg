class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int c=0;
        string ans="";
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
                c++;
            else if(s[i]==')')
            {
                if(c==0)
                   s[i]='*';
                else
                    c--;
            }
        }
        
        if(c!=0)
        {
            c=0;
            for(i=n-1;i>=0;i--)
            {
                if(s[i]==')')
                    c++;
                else if(s[i]=='(')
                {
                    if(c==0)
                        s[i]='*';
                    else
                        c--;
                }
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(s[i]!='*')
                ans+=s[i];
        }
        
        return ans;
    }
    
    /*
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
    */
};