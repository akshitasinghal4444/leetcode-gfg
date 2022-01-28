class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<vector<int>>& a)
    {
        return (i>=0 && j>=0 && i<m && j<n && a[i][j]==1);
    }
    
    int orangesRotting(vector<vector<int>>& a) {
        int m,n;
        m=a.size();
        n=a[0].size();
        int i,j;
        queue<vector<int>> q;
        
        int c=0,f=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==2)
                {
                    q.push({i,j});
                    a[i][j]=0;
                }
                if(a[i][j]==1)
                    f++;
            }
        }
        
        if(f==0)
            return 0;
        
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int x=q.front()[0],y=q.front()[1];
                q.pop();
                
                if(isValid(x-1,y,m,n,a))
                {
                    a[x-1][y]=0;
                    q.push({x-1,y});
                    f--;
                }
                if(isValid(x+1,y,m,n,a))
                {
                    a[x+1][y]=0;
                    q.push({x+1,y});
                    f--;
                }
                if(isValid(x,y-1,m,n,a))
                {
                    a[x][y-1]=0;
                    q.push({x,y-1});
                    f--;
                }
                if(isValid(x,y+1,m,n,a))
                {
                    a[x][y+1]=0;
                    q.push({x,y+1});
                    f--;
                }
            }
            c++;
        }
        if(c!=0)
            c=c-1;
        
        if(f>0)
            return -1;
        return c;
    }
};