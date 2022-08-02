class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m,n,i,j;
        m=a.size(),n=a[0].size();
        
        bool r0=0,c0=0;
        for(i=0;i<m;i++)
        {
            if(a[i][0]==0)
                c0=1;
        }
        
        for(j=0;j<n;j++)
        {
            if(a[0][j]==0)
                r0=1;
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    a[0][j]=0;
                    a[i][0]=0;
                }
            }
        }
        
        for(i=1;i<m;i++)
        {
            if(a[i][0]==0)
            {
                for(j=1;j<n;j++)
                    a[i][j]=0;
            }
        }
        
        for(j=1;j<n;j++)
        {
            if(a[0][j]==0)
            {
                for(i=0;i<m;i++)
                    a[i][j]=0;
            }
        }
        
        if(r0)
        {
            for(j=0;j<n;j++)
                a[0][j]=0;
        }
        
        if(c0)
        {
            for(i=0;i<m;i++)
                a[i][0]=0;
        }
    }
};