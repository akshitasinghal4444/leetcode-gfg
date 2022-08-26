class Solution {
public:
    
    int largestRectangleArea(vector<int>& a)
    {
        int i,n=a.size();
        int ans=0;
        stack<int> s;
        a.push_back(0);
        
        for(i=0;i<=n;i++)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                int l,r=i;
                int j=s.top();
                s.pop();
                
                if(s.empty())
                    l=-1;
                else
                    l=s.top();
                
                ans=max(ans,a[j]*(r-l-1));
            }
            
            s.push(i);
        }
        return ans;
    }
    
    
    /*
    int largestRectangleArea(vector<int>& a)
    {
        int i,j,n=a.size();
        int ans=0;
        vector<int> r(n,n),l(n,-1);
        
        for(i=1;i<n;i++)
        {
            j=i-1;
            while(j>=0 && a[j]>=a[i])
                j=l[j];
            
            l[i]=j;
        }
        
        for(i=n-2;i>=0;i--)
        {
            j=i+1;
            while(j<n && a[j]>=a[i])
                j=r[j];
            
            r[i]=j;
        }
        
        for(i=0;i<n;i++)
        ans=max(ans,a[i]*(r[i]-l[i]-1));
        
        return ans;
    }
    */
    
    /*
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
    */
};