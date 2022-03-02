class Solution {
public:
    int findDuplicate(vector<int>& a)
    {
        int i,n=a.size();
        
        for(i=0;i<n;i++)
        {
            int x;
            if(a[i]<n)
                x=a[i];
            else
                x=a[i]%n;
            
            if(a[x]>n)
                return x;
            a[x]+=n;
        }
        
        return -1;
    }
    
    /*
    int findDuplicate(vector<int>& a) {
        int n=a.size();
        int i;
        for(i=0;i<n;i++)
        {
            int in=abs(a[i])-1;
            if(a[in]<0)
                return abs(a[i]);
            a[in]*=-1;
        }
        return 0;
    }
    */
};