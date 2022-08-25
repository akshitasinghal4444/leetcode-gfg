class Solution {
public:
    vector<int> findBall(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        long i,j,k;
        vector<int> ans;
        
        for(k=0;k<n;k++)
        {
            j=k;
            
            for(i=0;i<m;i++)
            {
                if(j<n-1 && a[i][j]==1 && a[i][j+1]==-1)
                   break;
                
                if(j>0 && a[i][j]==-1 && a[i][j-1]==1)
                   break;
                
                j+=a[i][j];
                if(j<0 || j>=n)
                    break;
                
            }
            if(i!=m || j<0 || j==n)
                ans.push_back(-1);
            else
                ans.push_back(j);
        }
        
        return ans;
    }
};