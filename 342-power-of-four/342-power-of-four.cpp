class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if(n<=0)
            return 0;
        
        while(n>1)
        {
            if(n%4!=0)
                return 0;
            
            n=n/4;
        }
        
        return 1;    
    }
    
    /*
    bool isPowerOfFour(int n)
    {
        if(n<=0)
            return 0;
        
        long n1=1;
        while(n1<n)
            n1*=4;
        
        return n1==n;    
    }
    */
    
    /*
    bool isPowerOfFour(int n) {
        if(n<=0)
            return 0;
        
        double x=log(n)/log(4);
        
        return (long)x==x;
    }
    */
    
};