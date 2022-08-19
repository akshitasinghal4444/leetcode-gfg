class Solution {
public:
    int fib(int n) {
        
        if(n<=1)
            return n;
        
        int f0=0,f1=1,f;
        
        for(int i=2;i<=n;i++)
        {
            f=f0+f1;
            f0=f1;
            f1=f;
        }
        
        return f;
    }
};