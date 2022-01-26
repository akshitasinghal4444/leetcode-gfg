class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int i,j,mp=0;
        for(i=0;i<n;i++)
        {
            j=i+1;
            while(j<n && a[j]>a[j-1])
                j++;
            mp+=a[j-1]-a[i];
            i=j-1;
        }
        return mp;
    }
};