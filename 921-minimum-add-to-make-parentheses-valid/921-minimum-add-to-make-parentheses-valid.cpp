class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int c=0,ans=0;
        
        for(char ch:s)
        {
            if(ch=='(')
                c++;
            else
            {
                if(c>0)
                    c--;
                else
                    ans++;
            }
        }
        ans+=c;
        return ans;
    }
    
    /*
    int minAddToMakeValid(string s) {
        stack<int> st;
        
        for(char ch:s)
        {
            if(ch==')' && !st.empty() && st.top()=='(')
                st.pop();
            else
                st.push(ch);
        }
        
        return st.size();
    }
    */
};