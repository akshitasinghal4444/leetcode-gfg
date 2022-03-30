class Solution {
public:
    vector<int> ans;
    
    bool topo_sort(vector<int> *g,int in,vector<int> &vis)
    {
        vis[in]=1;
        int n=g[in].size();
        
        for(int i=0;i<n;i++)
        {
            if(vis[g[in][i]]==1)
                return 0;
            if(vis[g[in][i]]==0 && !topo_sort(g,g[in][i],vis))
                return 0;
        }
        
        ans.push_back(in);
        vis[in]=2;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a)
    {
        vector<int> g[n];
        vector<int> vis(n,0);
        
        int i;
        ans={};
        
        for(auto v:a)
            g[v[1]].push_back(v[0]);
        
        for(i=0;i<n;i++)
        {
            if(vis[i]==0 && !topo_sort(g,i,vis))
                return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    /*
    bool dfs(int i,vector<int> *g,vector<int> &vis,vector<int> &ans)
    {
        vis[i]=1;
        
        for(int x:g[i])
        {
            if(vis[x]==1)
                return 0;
            if(vis[x]==0 && !dfs(x,g,vis,ans))
                return 0;
        }
        
        vis[i]=2;
        ans.push_back(i);
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a)
    {
        vector<int> g[n],ans;
        vector<int> vis(n,0);
        bool f=0;
        
        int i;
        for(i=0;i<a.size();i++)
            g[a[i][0]].push_back(a[i][1]);
        
        for(i=0;i<n;i++)
        if(!vis[i])
        {
            if(!dfs(i,g,vis,ans))
                return {};
        }
            
        return ans;
    }
    */
    
    /*
    bool dfs(vector<int> *g,int n,int i,vector<int> &vis,stack<int> &st)
    {
        vis[i]=1;
        int j;
        for(j=0;j<g[i].size();j++)
            if(vis[g[i][j]]==1)
                return 1;
            else if(vis[g[i][j]]==0)
                if(dfs(g,n,g[i][j],vis,st)) return 1;
        
        st.push(i);
        vis[i]=2;
        return 0;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int> ans,g[numCourses];
        vector<int> vis(numCourses,0);
        stack<int> st;
        bool x;
        int i,j;
        for(i=0;i<n;i++)
        {
           g[pre[i][1]].push_back(pre[i][0]);

        }
        
        for(i=0;i<numCourses;i++)
            if(!vis[i])
                if(dfs(g,numCourses,i,vis,st)) return {};
        
        
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
            
    }
    */
};