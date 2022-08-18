class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    bool possible(int n,int r,int c)
    {
        int m=t.size();
        int i,j;

        
        //column
        for(i=0;i<m;i++)
        {
            if(t[i][c]=='Q')
                return 0;
        }
        
        //left diagnol
        i=r-1,j=c-1;
        while(i>=0 && j>=0)
        {
            if(t[i--][j--]=='Q')
                return 0;
        }
        
        //right diagnol
        i=r-1,j=c+1;
        while(i>=0 && j<n)
        {
            if(t[i--][j++]=='Q')
                return 0;
        }
        
        return 1;
    }
    
    void solve(int n,int r)
    {
        if(r==n)
        {
            ans.push_back(t);
            return;
        }
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
        {
            if(possible(n,r,i))
            {
                s[i]='Q';
                t.push_back(s);
                
                solve(n,r+1);
                
                t.pop_back();
                s[i]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        solve(n,0);
        return ans;
    }
};