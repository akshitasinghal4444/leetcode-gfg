class Solution {
public:
    int maxProfit(vector<int>& a) {
        int minp=a[0];
        int maxp=0;
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            minp=min(minp,a[i]);
            maxp=max(maxp,a[i]-minp);
        }
        return maxp;
    }
};