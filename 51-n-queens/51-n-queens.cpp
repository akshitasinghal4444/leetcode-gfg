class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    
    bool isSafe(vector<vector<int>> &a,int n,int r,int c)
    {
        int i,j;
        
        //same col
        for(i=r-1,j=c;i>=0;i--)
        {
            if(a[i][j]==1)
                return 0;
        }
        
        //left diagnol
        for(i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
        {
            if(a[i][j]==1)
                return 0;
        }
        
        //right diagnol
        for(i=r-1,j=c+1;i>=0 && j<n;i--,j++)
        {
            if(a[i][j]==1)
                return 0;
        }
        
        return 1;
    }
    
    void solve(vector<vector<int>> &a,int n,int r)
    {
        if(r==n)
        {
            ans.push_back(t);
            return ;
        }
        
        int i;
        string s="";
        
        for(int i=0;i<n;i++)
            s+='.';

        for(i=0;i<n;i++)
        {
            if(isSafe(a,n,r,i))
            {
                s[i]='Q';
                t.push_back(s);
                a[r][i]=1;
                
                solve(a,n,r+1); 
                
                a[r][i]=0;
                t.pop_back();
                s[i]='.';
            }

        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> a(n,vector<int>(n,0));
        ans={};
        t={};
        
         
        solve(a,n,0);
        
        return ans;
    }
};