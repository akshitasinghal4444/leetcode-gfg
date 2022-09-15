class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        vector<int> ans;
        int i,n=a.size();
        
        for(i=0;i<n;i++)
            ans.push_back(a[i]*a[i]);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};