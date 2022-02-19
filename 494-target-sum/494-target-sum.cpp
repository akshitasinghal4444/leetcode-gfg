class Solution {
public:
    int c;
    
    void count(vector<int>& a, int n,int t,int in,int s)
    {
        if(in==n)
        {
            if(s==t)
                c++;
            return;
        }
        
        count(a,n,t,in+1,s+a[in]);
        count(a,n,t,in+1,s-a[in]);
    }
    
    int findTargetSumWays(vector<int>& a, int t) {
        int n=a.size();
        c=0;
        count(a,n,t,0,0);
        return c;
    }
};