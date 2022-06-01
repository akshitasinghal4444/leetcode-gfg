class Solution {
public:
    vector<int> runningSum(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n,0);
        
        ans[0]=a[0];
        
        for(int i=1;i<n;i++)
            ans[i]=ans[i-1]+a[i];
        
        return ans;
    }
};