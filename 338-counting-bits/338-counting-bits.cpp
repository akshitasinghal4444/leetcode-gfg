class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> a(n+1);
        a[0]=0;
        
        for(int i=0;i<=n/2;i++)
        {
            a[2*i]=a[i];
            
            if(2*i+1<=n)
                a[2*i+1]=a[i]+1;
        }
        
        return a;
    }
    
};