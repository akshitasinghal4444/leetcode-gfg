class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        int i,j;
        
        for(i=0;i<n/2;i++)
        {
            for(j=i;j<n-i-1;j++)
            {
                int t=a[i][j];
                a[i][j]=a[n-j-1][i];
                a[n-j-1][i]=a[n-i-1][n-j-1];
                a[n-i-1][n-j-1]=a[j][n-i-1];
                a[j][n-i-1]=t;
            }
        }
        
    }
};