class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(string s:ops)
        {
            if(s=="C")
                st.pop();
            else if(s=="D")
                st.push(2*st.top());
            else if(s=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                
                st.push(x+y);
            }
            else
                st.push(stoi(s));
        }
        
        int ans=0;
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};