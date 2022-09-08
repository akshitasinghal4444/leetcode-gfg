class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> in(n,0);
        queue<int> q;
        int i,c=0;
        
        for(auto v:a)
        {
            in[v[1]]++;
            g[v[0]].push_back(v[1]);
        }
        
        for(i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            c++;
            
            for(int x:g[i])
            {
                in[x]--;
                if(in[x]==0)
                    q.push(x);
            }
        }
        
        return c==n;
    }
};