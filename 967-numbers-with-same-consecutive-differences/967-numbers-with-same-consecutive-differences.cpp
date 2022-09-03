class Solution {
public:
    vector<int> ans;
    
    void helper(int in,int n,int k,int t)
    {
        if(n==0)
        {
            if(t!=0)
                ans.push_back(t);
            
            return;
        }
        
        if(in-k>=0)
            helper(in-k,n-1,k,t*10+in-k);
        
        if(in+k<=9 && k!=0)
            helper(in+k,n-1,k,t*10+in+k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i=1;i<=9;i++)
        helper(i,n-1,k,i);
        
        return ans;
    }
};