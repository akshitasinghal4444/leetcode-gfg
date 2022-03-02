class Solution {
public:
    int findUnsortedSubarray(vector<int>& a)
    {
        int n=a.size(),i;
        int s=-1,e=n;
        int mn=INT_MAX,mx=INT_MIN;
        
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<=mn)
                mn=a[i];
            else
                s=i;
        }
        
        if(s==-1)
            return 0;
        
        for(i=0;i<n;i++)
        {
            if(a[i]>=mx)
                mx=a[i];
            else
                e=i;
        }
        
        return e-s+1;
    }
    
    /*
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> a2=a;
        sort(a2.begin(),a2.end());
        
        int n=a.size();
        int s=0,e=n-1;
        
        while(s<n && a[s]==a2[s])
            s++;
        
        if(s==n)
            return 0;
        
        while(e>=0 && a[e]==a2[e])
            e--;
        
        return e-s+1;
    }
    */
};