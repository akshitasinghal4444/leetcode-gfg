class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n=g.size();
        if(n<=1)
            return 0;
        
        int dis=0;
        int final=(1<<n)-1;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(final+1,0));
        
        for(int i=0;i<n;i++)
        {
            q.push({i,1<<i});
            vis[i][1<<i]=1;
        }
        
        while(!q.empty())
        {
            dis++;
            int s=q.size();
            
            while(s--)
            {
                int node=q.front().first;
                int path=q.front().second;
                q.pop();

                for(int in:g[node])
                {
                    int newpath=(path | 1<<in);

                    if(vis[in][newpath]==0)
                    {
                        q.push({in,newpath});
                        vis[in][newpath]=1;
                    }
                    
                    if(newpath==final)
                        return dis;
                }
            }
        }
        return -1;
    }
    
};