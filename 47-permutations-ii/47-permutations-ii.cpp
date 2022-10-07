class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            ans.push_back(a);
            return;
        }
            
        unordered_set<int> vis;
        
        for(int i=in;i<n;i++)
        {
            if(vis.find(a[i])==vis.end())
            {
                vis.insert(a[i]);
                swap(a[i],a[in]);
                permute(a,in+1,n);
                swap(a[i],a[in]);
            }            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        permute(a,0,a.size());
        
        return ans;
    }
    
    /*
    set<vector<int>> s;
    
    void permute(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            s.insert(a);
            return;
        }
            
        for(int i=in;i<n;i++)
        {
            swap(a[i],a[in]);
            permute(a,in+1,n);
            swap(a[i],a[in]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& a) {
        permute(a,0,a.size());
        
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
    */
};