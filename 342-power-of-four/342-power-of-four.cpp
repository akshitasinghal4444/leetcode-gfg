class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return 0;
        
        double x=log(n)/log(4);
        
        return (long)x==x;
    }
};