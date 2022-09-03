class Solution {
public:
    vector<int> ans;
    
    void helper(int digit,int n,int k,int num)
    {
        if(n==0)
        {
            if(num!=0)
                ans.push_back(num);
            
            return;
        }
        
        if(digit-k>=0)
            helper(digit-k,n-1,k,num*10+digit-k);
        
        if(digit+k<=9 && k!=0)
            helper(digit+k,n-1,k,num*10+digit+k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++)
        helper(i,n-1,k,i);
        
        return ans;
    }
};