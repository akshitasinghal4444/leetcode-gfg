class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0)
            return 0;
        
        long x=1<<31;        
        return x%n==0;
    }
};