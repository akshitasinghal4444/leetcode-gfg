class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int i,j;
        int m=g.size(),n=g[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        k=k%(m*n);
        // cout<<k<<endl;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                int ni,nj;
                nj=(j+(k%n))%n;
                ni=i+(k/n);
                
                if(nj<j)
                    ni++;
                
                ni=ni%m;
                ans[ni][nj]=g[i][j];
                
                // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
            }
        }
        return ans;
    }
};