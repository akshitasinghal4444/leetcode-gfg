class Solution {
public:
    int reverse(int x)
    {
        int ans=0;
        while(x)
        {
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
                return 0;
            
            ans=ans*10+x%10;
            x=x/10;
        }
        return ans;
    }
    
    /*
    int reverse(int x) {
        long ans=0;
        bool p=0;
        if(x<0)
            p=1;
        
        x=abs(x);
        while(x>0)
        {
            ans=ans*10+x%10;
            x=x/10;
            
            if(p==0 && ans>INT_MAX)
                return 0;
            if(p==1 && -ans<INT_MIN)
                return 0;
            
        }
        if(!p)
        return ans;
        
        return -ans;
    }
    */
};