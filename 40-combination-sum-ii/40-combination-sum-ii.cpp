class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void combination(vector<int>& a, int t,int in,int n)
    {
        if(in==n)
        {
            if(t==0)
                ans.push_back(v);
            return;
        }
        
        if(t<0)
            return;
        
        if(v.empty() || v.back()!=a[in])
            combination(a,t,in+1,n);
        
        v.push_back(a[in]);
        combination(a,t-a[in],in+1,n);
        v.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(),a.end());
        combination(a,t,0,a.size());
        
        return ans;
    }
};