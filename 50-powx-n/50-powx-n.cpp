class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        if(n<0)
        {
            if(n==INT_MIN)
                return 1/x*myPow((1/x),abs(n+1));
            return myPow((1/x),abs(n));
        }
            
        
        if(n%2==0)
            return myPow(x*x,n/2);
        else
            return x*myPow(x,n-1);
    }
};