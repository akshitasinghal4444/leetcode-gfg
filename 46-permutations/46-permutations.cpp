class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    void permute(vector<int>& a,int n,int in)
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
            
            permute(a,n,in+1);
            
            swap(a[i],a[in]);
            t.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        permute(a,a.size(),0);
        return ans;
    }
};