class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int i,j,n=a.size();
        
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
                break;
        }
        
        if(i==-1)
        {
            for(i=0,j=n-1;i<j;i++,j--)
                swap(a[i],a[j]);
            
            return;
        }
        
        int k=i+1;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>a[i] && a[j]<=a[k])
                k=j;
        }
        
        swap(a[i],a[k]);
        sort(a.begin()+i+1,a.end());
    }
};