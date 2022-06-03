class NumMatrix {
public:
    vector<vector<int>> a;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        a=matrix;
        int m=a.size(),n=a[0].size();
        int i,j;
        a.push_back({0});
        
        for(i=0;i<m;i++)
            a[i].push_back(0);
        
        for(j=0;j<n;j++)
            a[i].push_back(0);
        
        for(i=m-1;i>=0;i--)
            for(j=n-1;j>=0;j--)
                    a[i][j]+=a[i+1][j]+a[i][j+1]-a[i+1][j+1];
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return a[r1][c1]-a[r1][c2+1]-a[r2+1][c1]+a[r2+1][c2+1];
    }
};


/*
class NumMatrix {
public:
    vector<vector<int>> a;
    
    NumMatrix(vector<vector<int>>& matrix) {
        a=matrix;
        int m=a.size(),n=a[0].size();
        int i,j;
        
        for(i=0;i<m;i++)
            for(j=1;j<n;j++)
                a[i][j]+=a[i][j-1];
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum=0;
        
        for(int i=r1;i<=r2;i++)
        {
            sum+=a[i][c2];
            if(c1>0)
                sum-=a[i][c1-1];
        }
        
        return sum;
    }
};
*/

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */