class Solution {
public:
    int calc(int n)
    {
        int ans=0;
        
        while(n>0)
        {
            int x=n%10;
            ans+=x*x;
            n=n/10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        int x=calc(n);
        
        while(x!=1 && x!=89)
            x=calc(x);
        
        return x==1;
    }
    
    /*
    int calc(int n)
    {
        int ans=0;
        
        while(n>0)
        {
            int x=n%10;
            ans+=x*x;
            n=n/10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        unordered_set<int> s;
        int x=calc(n);
        
        while(x!=1)
        {
            if(s.find(x)!=s.end())
                return 0;
            
            s.insert(x);
            
            x=calc(x);
        }
        
        return 1;
    }
    */
};