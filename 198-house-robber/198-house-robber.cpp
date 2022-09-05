class Solution {
public:
    int rob(vector<int>& a) {
        int inc=0,exc=0;
        int n_inc,n_exc;
        
        for(int n:a)
        {
            n_inc=exc+n;
            n_exc=max(inc,exc);
            
            inc=n_inc,exc=n_exc;
        }
        
        return max(inc,exc);
    }
};