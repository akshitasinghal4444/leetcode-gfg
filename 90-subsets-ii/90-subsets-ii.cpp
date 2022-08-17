class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void subset(vector<int>& a,int n,int in)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        if(t.empty() || t.back()!=a[in])
            subset(a,n,in+1);
        
        t.push_back(a[in]);
        subset(a,n,in+1);
        t.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        subset(a,a.size(),0);
        return ans;
    }
};