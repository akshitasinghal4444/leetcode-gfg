class Solution {
public:
    bool isvalid(int i,int j,int m,int n,vector<vector<int>>& a)
    {
        return (i>=0 && j>=0 && i<m && j<n && a[i][j]==0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        int i,j,k,ans=0;
        
        if(a[0][0]==1 || a[m-1][n-1]==1)
            return -1;
        
        if(m==1 && n==1)
            return 1;
        
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                for(k=0;k<8;k++)
                {
                    if(isvalid(i+dx[k],j+dy[k],m,n,a))
                    {
                        if(i+dx[k]==m-1 && j+dy[k]==n-1)
                            return ans+1;
                        
                        q.push({i+dx[k],j+dy[k]});
                        a[i+dx[k]][j+dy[k]]=1;
                    }
                }
            }
        }
        
        return -1;
    }
};