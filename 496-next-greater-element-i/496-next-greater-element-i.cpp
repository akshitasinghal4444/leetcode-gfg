class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {

        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> m;
        
        for(int n:a2)
        {
            while(!st.empty() && st.top()<n)
            {
                m[st.top()]=n;
                st.pop();
            }
            
            st.push(n);
        }
        
        for(int n:a1)
        {
            if(m.find(n)==m.end())
                ans.push_back(-1);
            else
                ans.push_back(m[n]);
        }
        
        return ans;
    }
};