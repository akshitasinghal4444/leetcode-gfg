class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    bool is_safe(vector<vector<int>> &a,int r,int c,int n)
    {
        int i,j;
        
        //col
        for(i=0;i<n;i++)
        {
            if(a[i][c])
                return 0;
        }
        
        //left diagnol
        for(i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(a[i][j])
                return 0;
        }
        
        //right diagnol
        for(i=r-1,j=c+1;i>=0 && j<n;i--,j++)
        {
            if(a[i][j])
                return 0;
        }
        
        return 1;
    }
                 
    
    void solve(vector<vector<int>> &a,int n,int r)
    {
        if(r==n)
        {
            ans.push_back(t);
            return;
        }
                  
        string s(n,'.');
        int i;
        
        for(i=0;i<n;i++)
        {
            if(is_safe(a,r,i,n))
            {
                s[i]='Q';
                a[r][i]=1;
                t.push_back(s);
                
                solve(a,n,r+1);
                
                s[i]='.';
                a[r][i]=0;
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> a(n,vector<int>(n,0));
        solve(a,n,0);
        return ans;
    }
};