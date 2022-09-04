class Solution {
public:
    
    int bfs(vector<vector<int>>& routes, int s, int t,unordered_map<int,vector<int>> &m)
    {
        unordered_set<int> vis1,vis2;
        int ans=0;
        queue<int> q;
        
        vis1.insert(s);
        q.push(s);
        
        while(!q.empty())
        {
            ans++;
            int n=q.size();
            
            while(n--)
            {
                s=q.front();
                q.pop();
               
                for(int y:m[s])
                {
                    if(vis2.find(y)!=vis2.end())
                        continue;
                    
                    vis2.insert(y);
                    
                    for(int x:routes[y])
                    {
                        if(x==t)
                            return ans;
                        
                        if(vis1.find(x)==vis1.end())
                        {
                            vis1.insert(x);
                            q.push(x);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        int n=routes.size();
        
        if(n==0 || s==t)
            return 0;
        
        unordered_map<int,vector<int>> m;
        int i,j;
        
        for(i=0;i<n;i++)
        {
            for(int x:routes[i])
                m[x].push_back(i);
        }
        
        return bfs(routes,s,t,m);
    }
};