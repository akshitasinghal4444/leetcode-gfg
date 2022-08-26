class Solution {
public:
    void count(long n, vector<int> &f)
    {
        while(n>0)
        {
            f[n%10]++;
            n=n/10;
        }
    }
    
    bool reorderedPowerOf2(int n) {
        if(n==1)
            return 1;
        
        vector<int> f1(10,0);
        count(n,f1);
        
        long x=1,i;
        for(i=0;i<31;i++)
        {
            vector<int> f2(10,0);
            x*=2;
            count(x,f2);
            
            if(f1==f2)
                return 1;
        }
        
        return 0;
    }
};