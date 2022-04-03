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
            if(a[i]>a[in] && a[i]<a[j])
                j=i;
        }
        
        swap(a[in],a[j]);
        sort(a.begin()+in+1,a.end());
    }
    
    /*
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        int i,j,ind=-1;
        for(i=n-1;i>0;i--)
        {
            if(a[i]>a[i-1])
            {
                ind=i-1;
                break;
            }
        }
        if(ind==-1)
        {
            reverse(a.begin(),a.end());
            return;
        }
        for(i=ind+2,j=ind+1;i<n;i++)
        {
            if(a[i]>a[ind] && a[i]<a[j])
                j=i;
        }
        
        int t=a[j];
        a[j]=a[ind];
        a[ind]=t;
        
        sort(a.begin()+ind+1,a.end());
    }
    */
};