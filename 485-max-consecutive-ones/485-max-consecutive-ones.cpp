class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int i,n=a.size();
        int ans=0,c=0;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
                c++;
            else
            {
                ans=max(ans,c);
                c=0;
            }
        }
        
        ans=max(ans,c);
        return ans;
    }
};