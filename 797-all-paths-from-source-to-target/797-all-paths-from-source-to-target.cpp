class Solution {
    
public:
    
    vector<vector<int>> ans;
    vector<int> t;
    
    void dfs(vector<vector<int>>& g,int in,int n)
    {
        t.push_back(in);
        
        if(in==n-1)
            ans.push_back(t);
        else
        {
            for(int i:g[in])
                dfs(g,i,n);
        }
        
        t.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {

        dfs(g,0,g.size());        
        return ans;
    }
    
    
};