class Solution {
public:
    int largestRectangleArea(vector<int>& a)
    {
        int n=a.size();
        int i;
        
        stack<int> s;
        vector<int> lmin(n),rmin(n);
        
        for(i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                rmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())
        {
            rmin[s.top()]=n;
            s.pop();
        }
        
        for(i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                lmin[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            lmin[s.top()]=-1;
            s.pop();
        }
        
        int ans=0;
        for(i=0;i<n;i++)
            ans=max(ans,(rmin[i]-lmin[i]-1)*a[i]);
        
        return ans;
    }
};