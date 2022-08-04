class Solution {
public:
    int ans;
    
    void merge(vector<int> &a,int l,int mid,int r)
    {
        int n1=mid-l+1,n2=r-mid;
        int a1[n1],a2[n2];
        int i,j,k;
        
        i=0;
        for(i=0,j=l;i<n1;i++,j++)
            a1[i]=a[j];
        for(i=0;i<n2;i++,j++)
            a2[i]=a[j];
        
        for(i=0,j=0;i<n1;i++)
        {
            while(j<n2 && (long)2*a2[j]<a1[i])
                j++;
            
            ans+=j;
        }
        
        i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(a1[i]<=a2[j])
            {
                a[k++]=a1[i++];
            }
            else
            {
                a[k++]=a2[j++];
            }
        }
        
        while(i<n1)
            a[k++]=a1[i++];
        
        while(j<n2)
            a[k++]=a2[j++];
            
    }
    
    void mergesort(vector<int> &a,int l,int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            mergesort(a,l,mid);
            mergesort(a,mid+1,r);
            merge(a,l,mid,r);
        }
    }
    
    int reversePairs(vector<int>& a) {      
        ans=0;
        mergesort(a,0,a.size()-1);
        return ans;
    }
};