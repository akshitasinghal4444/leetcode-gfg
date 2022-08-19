class Solution {
public:
    int climbStairs(int n) {
        int fn2=0,fn1=1,fn;
        
        for(int i=1;i<=n;i++)
        {
            fn=fn1+fn2;
            fn2=fn1;
            fn1=fn;
        }
        
        return fn;
    }
};