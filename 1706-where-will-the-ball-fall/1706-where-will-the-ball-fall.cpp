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
                int next=j+a[i][j];
                
                if(next<0 || next>=n || a[i][j]!=a[i][next])
                {
                    ans.push_back(-1);
                    break;
                }
                
                j=next;
            }
            
            if(i==m)
            ans.push_back(j);
        }
        
        return ans;
    }
    
    /*
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
                
                j+=a[i][j];
            }
            
            if(i==m)
            ans.push_back(j);
        }
        
        return ans;
    }
    */
};