class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[1]==b[1])
            return a[0]>b[0];
        
        return a[1]<b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),comp);
        
        int c=n;
        int s=a[n-1][0],e=a[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i][0]>=s && a[i][1]<=e)
            {
                c--;
            }
            else if(a[i][0]<=s) 
            {
                s=a[i][0];
                e=a[i][1];
            }
        }
        return c;
    }
};