class Solution {
public:
    
    bool checkrows(vector<vector<char>>& b)
    {
        int i,j;
        
        for(i=0;i<9;i++)
        {
            unordered_set<char> vis;
            
            for(j=0;j<9;j++)
            {
                if(b[i][j]=='.')
                    continue;
                
                if(b[i][j]<'1' || b[i][j]>'9' || vis.find(b[i][j])!=vis.end())
                    return 0;
                
                vis.insert(b[i][j]);
            }
        }
        
        return 1;
    }
    
    bool checkcols(vector<vector<char>>& b)
    {
        int i,j;
        
        for(j=0;j<9;j++)
        {
            unordered_set<char> vis;
            
            for(i=0;i<9;i++)
            {
                if(b[i][j]=='.')
                    continue;
                
                if(b[i][j]<'1' || b[i][j]>'9' || vis.find(b[i][j])!=vis.end())
                    return 0;
                
                vis.insert(b[i][j]);
            }
        }
        
        return 1;
    }
    
    bool checkbox(vector<vector<char>>& b)
    {
        int bi,bj,i,j;
        
        for(bi=0;bi<9;bi+=3)
        {
            for(bj=0;bj<9;bj+=3)
            {
                unordered_set<char> vis;
                
                for(i=bi;i<bi+3;i++)
                {
                    for(j=bj;j<bj+3;j++)
                    {
                        if(b[i][j]=='.')
                            continue;
                
                        if(b[i][j]<'1' || b[i][j]>'9' || vis.find(b[i][j])!=vis.end())
                            return 0;
                
                        vis.insert(b[i][j]);
                    }
                }
            }
        }
        
        return 1;
    }
    
    bool isValidSudoku(vector<vector<char>>& b) {
        return checkrows(b) && checkcols(b) && checkbox(b);
    }
};