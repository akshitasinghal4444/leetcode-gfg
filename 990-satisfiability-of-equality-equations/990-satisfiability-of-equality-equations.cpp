class Solution {
public:
    
    int find(int n,vector<int> &parent)
    {
        if(parent[n]<0)
            return n;
        
        return parent[n]=find(parent[n],parent);
    }
    
    void unionByWt(int u,int v,vector<int> &parent)
    {
        int pu=find(u,parent),pv=find(v,parent);
        
        if(pu==pv)
            return;
        
        if(parent[pu]<=parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26,-1);
        
        for(auto s:equations)
        {
            if(s[1]=='!')
                continue;
            
            unionByWt(s[0]-'a',s[3]-'a',parent);
        }
        
        for(auto s:equations)
        {
            if(s[1]=='!' && find(s[0]-'a',parent)==find(s[3]-'a',parent))
                return 0;
        }
        
        return 1;
    }
};