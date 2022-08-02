class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0,b=a[0];
        
        for(int n:a)
        {
            b=min(b,n);
            ans=max(ans,n-b);
        }
        
        return ans;
    }
};