class Solution {
public:
    vector<vector<int>> ans;
    vector<int> x;
    
    void sum(vector<int>& a, int t,int in,int n)
    {
        if(in==n)
        {
            if(t==0)
                ans.push_back(x);
            
            return;
        }
        
        if(t<0)
            return;
        
        if(x.empty() || x.back()!=a[in])
        sum(a,t,in+1,n);
        
        x.push_back(a[in]);
        sum(a,t-a[in],in+1,n);
        sum(a,t-a[in],in,n);
        x.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        sum(a,t,0,a.size());
        return ans;
    }
};