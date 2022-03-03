class Solution {
public:
        int candy(vector<int>& a) {
        int n=a.size();
        int i;
        vector<int> l(n,1);
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                l[i]=l[i-1]+1;
        }
        
        ans+=l[n-1];
        int r=1;
        for(i=n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
                r=r+1;
            else
                r=1;
            
            ans+=max(l[i],r);
        }
        
        return ans;
    }
    
    /*
    int candy(vector<int>& a) {
        int n=a.size();
        int i;
        vector<int> l(n,1),r(n,1);
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
                l[i]=l[i-1]+1;
        }
        
        for(i=n-2;i>=0;i--)
        {
            if(a[i]>a[i+1])
                r[i]=r[i+1]+1;
        }
        
        for(i=0;i<n;i++)
        {
            ans+=max(l[i],r[i]);
        }
        return ans;
    }
    */
};