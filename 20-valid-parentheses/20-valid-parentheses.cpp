class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        
        for(char c:s)
        {
            switch(c)
            {
                case '(':st.push(')');
                          break;
                case '{':st.push('}');
                          break;
                case '[':st.push(']');
                          break;
                    
                case ')':
                case '}':
                case ']':if(st.empty() || st.top()!=c)
                            return 0;
                         else
                             st.pop();
                             
            }
        }
        return st.empty();
    }
    
    /*
    bool isValid(string s) {
        int n=s.length();
        if(n%2!=0)
            return false;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            switch(s[i])
            {
                case '(':st.push(')');
                    break;
                case '{':st.push('}');
                    break;
                case  '[':st.push(']');
                    break;
                case ')':
                case '}':
                case ']':if(st.empty() || st.top()!=s[i])
                            return false;
                         st.pop();
            }
        }
        
        if(st.empty())
        return 1;
        return 0;
    }
    */
};