class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b)
    {
        unordered_set<char> row[9],col[9],box[9];
        int i,j;
        
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(b[i][j]=='.')
                    continue;
                
                if(b[i][j]<'1' || b[i][j]>'9' || row[i].find(b[i][j])!=row[i].end() || col[j].find(b[i][j])!=col[j].end() || box[i/3*3+j/3].find(b[i][j])!=box[i/3*3+j/3].end())
                    return 0;
                
                row[i].insert(b[i][j]);
                col[j].insert(b[i][j]);
                box[i/3*3+j/3].insert(b[i][j]);
            }
        }
        
        return 1;
    }
    
    /*
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
    */
};