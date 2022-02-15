class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
        unordered_map<int,int> m;
        stack<int> st;
        vector<int> ans;
        
        for(int x:a2)
        {
            while(!st.empty() && st.top()<x)
            {
                m[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        
        while(!st.empty())
        {
            m[st.top()]=-1;
            st.pop();
        }
        
        for(int x:a1)
        {
            ans.push_back(m[x]);
        }
        
        return ans;
    }
};