class Solution {
public:
    void nextPermutation(vector<int>& a)
    {
        int i,j;
        int n=a.size();
        int in=-1;
        
        for(i=n-1;i>0;i--)
        {
            if(a[i]>a[i-1])
            {
                in=i-1;
                break;
            }
        }
        
        if(in==-1)
        {
            reverse(a.begin(),a.end());
            return;
        }
        
        j=in+1;
        for(i=in+2;i<n;i++)
        {
            if(a[i]>a[in] && a[i]<=a[j])
                j=i;
        }
        
        swap(a[in],a[j]);
        reverse(a.begin()+in+1,a.end());
    }
    
};