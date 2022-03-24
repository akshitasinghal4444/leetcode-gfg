class Solution {
public:
    
    int find(int i,vector<int> &parent)
    {
        if(parent[i]<0)
            return i;
        
        return find(parent[i],parent);
    }
    
    bool union_by_weight(int u,int v,vector<int> &parent)
    {
        int pu=find(u,parent),pv=find(v,parent);
        
        if(pu==pv)
            return 0;
        
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n=e.size();
        int i;
        vector<int> parent(n+1,-1);
        
        for(i=0;i<n;i++)
        {
            int u=e[i][0],v=e[i][1];
            
            if(!union_by_weight(u,v,parent))
                return e[i];
        }
        return {};
    }
};