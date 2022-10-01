class Solution {
public:
    int maxArea(vector<int>& a) {
        int l=0,r=a.size()-1;
        int ans=0;
        
        while(l<r)
        {
            int len=min(a[l],a[r]);
            int br=r-l;
            
            ans=max(ans,len*br);
            
            if(a[l]<=a[r])
                l++;
            else
                r--;
        }
        
        return ans;
    }
};