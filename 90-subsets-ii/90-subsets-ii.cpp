class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void subsets(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            ans.push_back(t);
            return ;
        }
        
        if(t.empty() || t.back()!=a[in])
            subsets(a,in+1,n);
        
        t.push_back(a[in]);
        subsets(a,in+1,n);
        t.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(),a.end());
        
        subsets(a,0,a.size());
        
        return ans;
    }
};