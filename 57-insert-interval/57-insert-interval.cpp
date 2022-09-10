class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& x) {
        int i,n=a.size();
        vector<vector<int>> ans;
        int st,end;
        
        a.push_back(x);
        sort(a.begin(),a.end());
        
        st=a[0][0],end=a[0][1];
        
        for(i=1;i<=n;i++)
        {
            if(a[i][0]>end)
            {
                ans.push_back({st,end});
                st=a[i][0];
                end=a[i][1];
            }
            else
                end=max(end,a[i][1]);
        }
        
        ans.push_back({st,end});
        
        return ans;
    }
};