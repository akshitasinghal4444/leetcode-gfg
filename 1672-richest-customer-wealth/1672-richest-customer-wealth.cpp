class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        
        int ans=0,mx;
        
        for(i=0;i<m;i++)
        {
            mx=0;
            for(j=0;j<n;j++)
            {
                mx+=a[i][j];
            }
            ans=max(mx,ans);
        }
        return ans;
    }
};