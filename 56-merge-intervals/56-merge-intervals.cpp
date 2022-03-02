class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        
        int s,e,i;
        s=a[0][0];
        e=a[0][1];
        
        for(i=1;i<n;i++)
        {
            if(a[i][0]<=e)
                e=max(e,a[i][1]);
            else
            {
                ans.push_back({s,e});
                s=a[i][0];
                e=a[i][1];
            }                
        }
        ans.push_back({s,e});
        return ans;
    }
};