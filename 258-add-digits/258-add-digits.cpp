class Solution {
public:
    int addDigits(int n)
    {
        if(n==0)
            return 0;
        
        if(n%9==0)
            return 9;
        return n%9;
    }
    
    /*
    int addDigits(int n) {
        int s=0;
        do
        {
            s=0;
            while(n)
            {
                s+=(n%10);
                n=n/10;
            }
            n=s;
            
        }while(s/10>0);
        
        return s;
    }
    */
};