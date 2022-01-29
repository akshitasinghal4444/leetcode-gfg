class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int> l(n),r(n);
        stack<int> s;
        int i,ans=0;
        for(i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]>=a[i])
                s.pop();
            
            if(s.empty())
                l[i]=0;
            else
                l[i]=s.top()+1;
            
            s.push(i);
        }
        
        while(!s.empty())
        s.pop();
        
        for(i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>=a[i])
                s.pop();
            
            if(s.empty())
                r[i]=n-1;
            else
                r[i]=s.top()-1;
            
            s.push(i);
            
            int w=r[i]-l[i]+1;
            ans=max(ans,a[i]*w);
        }
        

        return ans;
    }
};