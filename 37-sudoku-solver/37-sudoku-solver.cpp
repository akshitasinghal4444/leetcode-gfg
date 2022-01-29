class Solution {
public:
    bool issafe(vector<vector<char>>& a,int r,int c,char k)
    {
        int i,j;
        
        //row && col
        for(i=0;i<9;i++)
        {
            if(a[r][i]==k)
                return 0;
            
            if(a[i][c]==k)
                return 0;
        }
        
        //box
        int x=r%3,y=c%3;
        
        if(x==0)
            x=r;
        else if(x==1)
            x=r-1;
        else
            x=r-2;
        
        if(y==0)
            y=c;
        else if(y==1)
            y=c-1;
        else
            y=c-2;
        
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(a[i+x][j+y]==k)
                    return 0;
            }
        }
        return 1;
    }
    
    bool solve(vector<vector<char>>& a,int r,int c)
    {
        bool f=0;
        if(a[r][c]=='.')
        {
            int i,j;
            char k;
            
            for(k='1';k<='9';k++)
            {
                if(issafe(a,r,c,k))
                {
                    a[r][c]=k;
                    if(r==8 && c==8)
                        return 1;
                    
                    if(c<8)
                        f=solve(a,r,c+1);
                    else
                        f=solve(a,r+1,0);
                
                    if(f)
                        return 1;
                    a[r][c]='.';
                }
            }
            return 0;
        }
        else
        {
            if(r==8 && c==8)
                return 1;
                    
            if(c<8)
                f=solve(a,r,c+1);
            else
                f=solve(a,r+1,0);
            
            if(f)
                return 1;
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& a) {
        int i,j;
        bool f;
        f=solve(a,0,0);
    }
};