class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int i,n=a.size();
        int ans=0;
        vector<int> r(n,n),l(n,-1);
        stack<int> st;
        
        for(i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                r[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        
        for(i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                l[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        for(i=0;i<n;i++)
        ans=max(ans,a[i]*(r[i]-l[i]-1));
        
        return ans;
    }
};