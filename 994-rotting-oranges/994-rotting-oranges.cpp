class Solution {
public:
    int orangesRotting(vector<vector<int>>& a)
    {
        int m,n,ans=0;
        m=a.size();
        n=a[0].size();
        
        queue<pair<int,int>> q;
        
        int i,j,f=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==2)
                {
                    q.push({i,j});
                    a[i][j]=0;
                }
                else if(a[i][j]==1)
                    f++;
            }
        }
        
        if(q.empty() || f==0)
            return f>0?-1:0;
            
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                if(i-1>=0 && a[i-1][j]==1)
                {
                    q.push({i-1,j});
                    a[i-1][j]=0;
                    f--;
                }
                
                if(j+1<n && a[i][j+1]==1)
                {
                    q.push({i,j+1});
                    a[i][j+1]=0;
                    f--;
                }
                
                if(i+1<m && a[i+1][j]==1)
                {
                    q.push({i+1,j});
                    a[i+1][j]=0;
                    f--;
                }
                
                if(j-1>=0 && a[i][j-1]==1)
                {
                    q.push({i,j-1});
                    a[i][j-1]=0;
                    f--;
                }
            }
        }
        
        if(f==0)
        return ans-1;
        else
            return -1;
    }
};