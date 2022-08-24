class Solution {
public:
    
    bool isPowerOfThree(int n)
    {
        if(n<=0)
            return 0;
        
        // 3^19=1162261467
        return 1162261467%n==0;
    }
    
    /*
    bool isPowerOfThree(int n)
    {
        if(n==1 || n==3)
            return 1;
        
        if(n<=0 || n%3!=0)
            return 0;
        
        double x=log(n)/log(3);
        
        cout<<(int)x;
        return (int)x==x;
    }
    */
    
    /*
    bool isPowerOfThree(int n)
    {
        if(n==1 || n==3)
            return 1;
        
        if(n<=0 || n%3!=0)
            return 0;
        
        long x=1;
        
        while(x<n)
            x*=3;
        
        return x==n;
    }
    */
    
    /*
    bool isPowerOfThree(int n) {
        if(n==1 || n==3)
            return 1;
        
        if(n<=0 || n%3!=0)
            return 0;
        
        return isPowerOfThree(n/3);
    }
    */
};