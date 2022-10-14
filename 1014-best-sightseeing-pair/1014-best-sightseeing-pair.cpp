class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int i,n=a.size();
        int score=a[0]+0;
        int ans=INT_MIN;
        
        for(i=1;i<n;i++)
        {
            ans=max(ans,score+a[i]-i);
            score=max(score,a[i]+i);
        }
        
        return ans;
    }
};