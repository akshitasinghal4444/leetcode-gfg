class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        int i,in,j;
        
        for(i=n-1;i>0;i--)
        {
            if(a[i-1]<a[i])
                break;
        }
        
        if(i==0)
        {
            reverse(a.begin(),a.end());
            return;
        }
        
        in=i-1;
        j=i;
        
        for(i=i+1;i<n;i++)
        {
            if(a[i]<=a[j] && a[i]>a[in])
                j=i;
        }
        
        swap(a[in],a[j]);
        sort(a.begin()+in+1,a.end());
        
    }
};