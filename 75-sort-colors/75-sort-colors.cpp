class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int i,l,r;
        
        l=0,r=n-1;
        for(i=0;i<=r;i++)
        {
            if(a[i]==0)
            {
                swap(a[i],a[l]);
                l++;
                
            }
            else if(a[i]==2)
            {
                swap(a[i],a[r]);
                r--;
                i--;
            }
        }
        
    }
};