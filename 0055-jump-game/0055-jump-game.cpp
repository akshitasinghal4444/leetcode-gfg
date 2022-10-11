class Solution {
public:
    bool canJump(vector<int>& a) {
        int i,j,n=a.size();
        
        int mx=0;
        
        for(i=0;i<n;i++)
        {
            if(i>mx)
                return 0;
            
            mx=max(mx,a[i]+i);
            
            if(mx>=n-1)
                return 1;
        }
        
        return 0;
    }
};