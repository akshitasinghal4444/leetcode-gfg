class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n=2 * 1e4+1;
        
        vector<int> f(n,0);
        int inc=0,exc=0;
        
        for(int x:a)
            f[x]++;
        
        for(int i=1;i<n;i++)
        {
            int ninc,nexc;
            ninc=exc+(i*f[i]);
            nexc=max(inc,exc);
            
            inc=ninc;
            exc=nexc;
        }
        
        return max(inc,exc);
    }
};