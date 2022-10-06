class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int i,j,k,c=0;
        
        if(g[0][0]==1 || g[m-1][n-1]==1)
            return -1;
        
        if(m==1 && n==1)
            return 1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        g[0][0]=1;
        
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        
        while(!q.empty())
        {
            c++;
            int s=q.size();
            
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                for(k=0;k<8;k++)
                {
                    if(i+dx[k]>=0 && j+dy[k]>=0 && i+dx[k]<m && j+dy[k]<n && g[i+dx[k]][j+dy[k]]==0)
                    {
                        if(i+dx[k]==m-1 && j+dy[k]==n-1)
                            return c+1;
                        
                        q.push({i+dx[k],j+dy[k]});
                        g[i+dx[k]][j+dy[k]]=1;
                    }
                }
            }
        }
        
        return -1;
    }
};