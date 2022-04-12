class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    
    bool isvalid(int i,int j,int m,int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    
    int check(vector<vector<int>>& b,int i,int j,int m,int n)
    {
        int k,c=0;
        
        for(k=0;k<8;k++)
        {
            if(isvalid(i+dx[k],j+dy[k],m,n) && b[i+dx[k]][j+dy[k]]==1)
                c++;
        }
        
        if(b[i][j]==0)
        {
            if(c==3)
                return 1;
            else
                return 0;
        }
        else
        {
            if(c<2 || c>3)
                return 0;
            else
                return 1;
        }
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& b) {
        int m=b.size(),n=b[0].size();
        vector<vector<int>> ans(m,vector<int> (n));
        int i,j;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                ans[i][j]=check(b,i,j,m,n);
            }
        }
        
        b=ans;
    }
};