class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a)
    {
        vector<int> g[n];
        vector<int> indegree(n,0);
        vector<int> ans;
        int i,j;
        
        for(auto v:a)
        {
            g[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        for(i=0;i<n;i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        
        j=0;
        while(j<ans.size())
        {
            for(int x:g[ans[j]])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    ans.push_back(x);
            }
            
            j++;
        }
        
        if(ans.size()==n)
            return ans;
        
        return {};
    }
    
    /*
    vector<int> ans;
    
    bool topo_sort(vector<int> *g,int n,vector<int> &vis,int in)
    {
        vis[in]=1;
        
        for(int x:g[in])
        {
            if(!vis[x] && !topo_sort(g,n,vis,x))
                return 0;
            
            if(vis[x]==1)
                return 0;
        }
        
        ans.push_back(in);
        vis[in]=2;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> vis(n,0);
        
        for(auto v:a)
            g[v[1]].push_back(v[0]);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && !topo_sort(g,n,vis,i))
                return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    */
};