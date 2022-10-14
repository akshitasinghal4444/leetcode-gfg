class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0;
        int mn=a[0];
        
        for(int x:a)
        {
            mn=min(mn,x);
            ans=max(ans,x-mn);
        }
        
        return ans;
    }
};