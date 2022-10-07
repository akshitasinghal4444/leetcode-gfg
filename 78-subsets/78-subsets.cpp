class Solution {
public:
    /*
    vector<vector<int>> ans;
    vector<int> t;
    
    void subsets(vector<int>& a,int in,int n)
    {
        if(in==n)
        {
            ans.push_back(t);
            return;
        }
        
        subsets(a,in+1,n);
        
        t.push_back(a[in]);
        subsets(a,in+1,n);
        t.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& a) {
        subsets(a,0,a.size());
        return ans;
    }
    */
    
    vector<vector<int>> subsets(vector<int>& a)
    {
        int i,j,n=a.size();
        vector<vector<int>> ans;
        int x=(1<<n);
        
        for(i=0;i<x;i++)
        {
            vector<int> t;
            
            for(j=0;j<n;j++)
            {
                if(i & (1<<j))
                    t.push_back(a[j]);
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};