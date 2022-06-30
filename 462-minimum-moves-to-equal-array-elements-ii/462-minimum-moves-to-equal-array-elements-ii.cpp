class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n=a.size(),ans=0;
        int median;
        sort(a.begin(),a.end());
        
        if(n%2==0)
            median=(a[n/2]+a[n/2-1])/2;
        else
            median=a[n/2];
        
        for(int i=0;i<n;i++)
            ans+=abs(a[i]-median);
        
        return ans;
    }
};