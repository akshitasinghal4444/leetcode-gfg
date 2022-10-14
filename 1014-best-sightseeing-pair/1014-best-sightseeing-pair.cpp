class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int i,n=a.size();
        int lscore=a[0]+0;
        int ans=INT_MIN;
        
        for(i=1;i<n;i++)
        {
            ans=max(ans,lscore+a[i]-i);
            lscore=max(lscore,a[i]+i);
        }
        
        return ans;
    }
};