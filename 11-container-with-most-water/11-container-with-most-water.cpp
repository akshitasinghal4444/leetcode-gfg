class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int l,r;
        l=0;
        r=n-1;
        int ma=INT_MIN,a;
        while(l<r)
        {
            int x=min(h[l],h[r]);
            int y=r-l;
            a=x*y;
            ma=max(ma,a);
            if(h[l]<h[r])
                l++;
            else
                r--;
        }
        return ma;
    }
};