class Solution {
public:
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
};