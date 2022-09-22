class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int ans=0;
        int i,j;
        
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(a[i][j]==0)
                    continue;
                
                if(i!=m-1 && j!=n-1)
                    a[i][j]=1+min({a[i+1][j],a[i][j+1],a[i+1][j+1]});
                
                ans+=a[i][j];
            }
        }
        
        return ans;
    }
};