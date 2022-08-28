class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int i,j,k;
        int m=a.size(),n=a[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        
        for(k=0;k<m;k++)
        {
            vector<int> t;
            
            for(i=k,j=0;i<m && j<n;i++,j++)
                t.push_back(a[i][j]);
            
            sort(t.begin(),t.end());
            
            for(i=k,j=0;i<m && j<n;i++,j++)
                ans[i][j]=t[j];
        }
        
        for(k=1;k<n;k++)
        {
            vector<int> t;
            
            for(i=0,j=k;i<m && j<n;i++,j++)
                t.push_back(a[i][j]);
            
            sort(t.begin(),t.end());
            
            for(i=0,j=k;i<m && j<n;i++,j++)
                ans[i][j]=t[i];
        }
        
        return ans;
    }
};