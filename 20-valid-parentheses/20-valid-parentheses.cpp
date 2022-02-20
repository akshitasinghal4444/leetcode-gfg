class Solution {
public:
    bool isValid(string s)
    {
        stack<int> st;
        
        for(char c:s)
        {
            switch(c)
            {
                case '(':st.push(')');
                        break;
                case '[':st.push(']');
                        break;
                case '{':st.push('}');
                        break;
                case ')':
                case ']':
                case '}':if(st.empty() || st.top()!=c)
                            return 0;   
                        else
                            st.pop();        
            }
        }
        return st.empty();
    }
};