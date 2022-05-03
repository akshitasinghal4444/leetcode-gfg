class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& a)
    {
        int i=0,j=a.size()-1;
        int mx=INT_MIN,mn=INT_MAX;
        int s=-1,e=j+1;
        
        for(;j>=0;j--,i++)
        {
            if(a[j]<=mn)
                mn=a[j];
            else
                s=j;
            
            if(a[i]>=mx)
                mx=a[i];
            else
                e=i;
        }
        
        if(s==-1)
            return 0;
        
        return e-s+1;
    }
    
    /*
    int findUnsortedSubarray(vector<int>& a)
    {
        int n=a.size(),i,j;
        int s=-1,e=n;
        int mn=INT_MAX,mx=INT_MIN;
        
        for(i=n-1,j=0;i>=0;i--,j++)
        {
            if(a[i]<=mn)
                mn=a[i];
            else
                s=i;
            
            if(a[j]>=mx)
                mx=a[j];
            else
                e=j;
        }
        
        if(s==-1)
            return 0;
        
        return e-s+1;
    }
    */
    
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