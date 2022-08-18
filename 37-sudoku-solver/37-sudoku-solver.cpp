class Solution {
public:
    bool possible(vector<vector<char>>& b,int r,int c,char x,int n)
    {
        int i,j;
        
        //row && column
        for(i=0;i<n;i++)
        {   if(b[r][i]==x || b[i][c]==x)
                return 0;
        }
        
        //box
        int br=3*(r/3),bc=3*(c/3);
        for(i=br;i<br+3;i++)
        {
            for(j=bc;j<bc+3;j++)
            {
                if(b[i][j]==x)
                    return 0;
            }
        }
        
        return 1;
    }
    
    bool solve(vector<vector<char>>& b,int r,int c,int n)
    {
        if(r==n)
            return 1;
        
        if(c==n)
            return solve(b,r+1,0,n);
        
        if(b[r][c]!='.')
            return solve(b,r,c+1,n);
        
        for(char i='1';i<='9';i++)
        {
            if(possible(b,r,c,i,n))
            {
                b[r][c]=i;
                if(solve(b,r,c+1,n))
                    return 1;
                b[r][c]='.';
            }
        }
        
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        bool x=solve(b,0,0,9);
        return ;
    }
};