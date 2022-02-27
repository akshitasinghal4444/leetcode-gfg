class Solution {
public:
    int maxProfit(vector<int>& a, int f)
    {
        int ans=0;
        int b=-a[0],s=0;
        int i,n=a.size();
        
        for(i=1;i<n;i++)
        {
            int nb,ns;
            nb=s-a[i];
            ns=a[i]+b-f;
            
            b=max(b,nb);
            s=max(s,ns);
        }
        
        return max(b,s);
    }
};