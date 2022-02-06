class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        
        int n=a.size();
        
        if(n<3)
            return n;
        
        int i;
        int j;
        
        for(i=n-1;i>=2;i--)
        {
            if(a[i]==a[i-1] && a[i]==a[i-2])
                a[i]=INT_MAX;
        }
        
        j=2;
        while(j<n && a[j]!=INT_MAX)
            j++;
        
        if(j==n)
            return n;
        
        for(i=j+1;i<n;i++)
        {
            if(a[i]==INT_MAX)
                continue;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            j++;
        }
        return j;
    }
};