class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int i,j;
        int f=0,c=0,ans=0;
        queue<pair<int,int>> q;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]==1)
                    f++;
                else if(g[i][j]==2)
                    q.push({i,j});
            }
        }
        
        if(f==0)
            return 0;
        
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                if(i-1>=0 && g[i-1][j]==1)
                {
                    q.push({i-1,j});
                    g[i-1][j]=2;
                    f--;
                }
                
                if(i+1<m && g[i+1][j]==1)
                {
                    q.push({i+1,j});
                    g[i+1][j]=2;
                    f--;
                }
                
                if(j-1>=0 && g[i][j-1]==1)
                {
                    q.push({i,j-1});
                    g[i][j-1]=2;
                    f--;
                }
                
                if(j+1<n && g[i][j+1]==1)
                {
                    q.push({i,j+1});
                    g[i][j+1]=2;
                    f--;
                }
                
                if(f==0)
                return ans;
            }
        }
        
        return -1;
    }
};