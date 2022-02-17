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
    
    /*
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
    */
};