class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        int i,j;
        
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                ans[j][i]=a[i][j];
        
        return ans;
    }
};