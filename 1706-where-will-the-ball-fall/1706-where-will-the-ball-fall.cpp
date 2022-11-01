class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int i,j,k;
        vector<int> ans;
        
        for(k=0;k<n;k++)
        {
            for(i=0,j=k;i<m;i++)
            {
                if((j<n-1 && a[i][j]==1 && a[i][j+1]==-1) || (j>0 && a[i][j]==-1 && a[i][j-1]==1) || (j==0 && a[i][j]==-1) || (j==n-1 && a[i][j]==1))
                {
                    ans.push_back(-1);
                    break;
                }
                
                if(a[i][j]==1)
                    j++;
                else
                    j--;
            }
            
            if(i==m)
            ans.push_back(j);
        }
        
        return ans;
    }
};