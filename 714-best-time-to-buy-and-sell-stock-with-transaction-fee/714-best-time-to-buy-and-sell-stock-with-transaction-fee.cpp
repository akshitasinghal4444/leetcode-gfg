class Solution {
public:
    int maxProfit(vector<int>& a, int f)
    {
        int n=a.size();
        int b=-a[0],s=0,i;
        
        for(i=1;i<n;i++)
        {
            int nb,ns;
            nb=s-a[i];
            ns=b-f+a[i];
            
            b=max(b,nb);
            s=max(s,ns);
        }
        return s;
    }
};