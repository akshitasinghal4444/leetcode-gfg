class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a)
    {
        int n=a.size(),i;
        vector<int> ans(n,1);
        
        for(i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*a[i-1];
        }
        
        int r=1;
        for(i=n-2;i>=0;i--)
        {
            r=r*a[i+1];
            ans[i]*=r;
        }
        return ans;
    }
    
    /*
    vector<int> productExceptSelf(vector<int>& a)
    {
        int n=a.size(),i;
        int l[n],r[n];
        vector<int> ans(n);
        
        l[0]=a[0];
        r[n-1]=a[n-1];
        
        for(i=1;i<n;i++)
            l[i]=l[i-1]*a[i];
        
        for(i=n-2;i>=0;i--)
            r[i]=r[i+1]*a[i];
        
        ans[0]=r[1];
        ans[n-1]=l[n-2];
        
        for(i=1;i<n-1;i++)
        {
            ans[i]=l[i-1]*r[i+1];
        }
        
        return ans;
    }
    */
    
    /*
    vector<int> productExceptSelf(vector<int>& a) {
        int z=0;
        vector<int> ans;
        long p=1;
        
        for(int n:a)
        {
            if(n==0)
                z++;
            else
                p*=n;
        }
        
        for(int n:a)
        {
            if(z>=2)
            ans.push_back(0);
            else if(z==1)
            {
                if(n==0)
                    ans.push_back(p);
                else
                    ans.push_back(0);
            }
            else
                ans.push_back(p/n);
        }
        return ans;
    }
    */
};