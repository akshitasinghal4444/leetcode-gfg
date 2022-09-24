class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void combine(int in,int n,int k)
    {        
        if(k==0)
        {
            ans.push_back(t);
            return;
        }
        
        if(in>n)
            return;
        
        combine(in+1,n,k);
        
        t.push_back(in);
        combine(in+1,n,k-1);
        t.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        combine(1,n,k);
        return ans;
    }
};