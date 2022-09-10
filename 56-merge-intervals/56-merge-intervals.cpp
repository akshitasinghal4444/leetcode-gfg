class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int st,end;
        vector<vector<int>> ans;
        
        sort(a.begin(),a.end());
        st=a[0][0],end=a[0][1];
        
        for(auto v:a)
        {
            if(v[0]>end)
            {
                ans.push_back({st,end});
                st=v[0];
                end=v[1];
            }
            else
                end=max(end,v[1]);
        }
        
        ans.push_back({st,end});
        
        return ans;
    }
};