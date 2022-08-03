class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        
        int s=a[0][0],e=a[0][1];
        vector<vector<int>> ans;
        
        for(auto v:a)
        {
            if(v[0]>e)
            {
                ans.push_back({s,e});
                s=v[0];
                e=v[1];
            }
            else
                e=max(e,v[1]);
        
        }
        ans.push_back({s,e});
        return ans;
    }
};