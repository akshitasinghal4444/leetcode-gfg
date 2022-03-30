class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2)
    {
        unordered_map<int,int> m;
        stack<int> s;
        vector<int> ans;
        
        for(int n:a2)
        {
            while(!s.empty() && n>s.top())
            {
                m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        
        for(int n:a1)
        {
            if(m.count(n))
                ans.push_back(m[n]);
            else
                ans.push_back(-1);
        }
        
        return ans;
    }
    
    /*
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
    */
};