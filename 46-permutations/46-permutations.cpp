class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void permute(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        for(int i=in;i<n;i++)
        {
            swap(a[i],a[in]);
            t.push_back(a[in]);
            
            permute(a,in+1,n);
            
            t.pop_back();
            swap(a[i],a[in]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        permute(a,0,a.size());
        return ans;
    }
};