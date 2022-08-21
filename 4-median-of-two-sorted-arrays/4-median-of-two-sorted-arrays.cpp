class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2)
    {
        int n1=a1.size(),n2=a2.size();
        if((n1+n2)==1)
        {
            if(n1)
                return a1[0];
            return a2[0];
        }
        
        int mid=(n1+n2)/2;
        int i=0,j=0,c=-1;
        int m1,m2;
        
        while((i<n1 || j<n2) && c<mid-1)
        {
            c++;
            if(i==n1)
                m1=a2[j++];
            else if(j==n2)
                m1=a1[i++];
            else if(a1[i]<=a2[j])
                m1=a1[i++];
            else
                m1=a2[j++];
        }
        
        if(i==n1)
            m2=a2[j++];
        else if(j==n2)
            m2=a1[i++];
        else if(a1[i]<=a2[j])
            m2=a1[i++];
        else
            m2=a2[j++];
        
        
        if((n1+n2)%2==0)
            return double(m1+m2)/2;
        else
            return m2;
    }
    
    /*
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        int n1=a1.size(),n2=a2.size();
        if(n1>n2)
            return findMedianSortedArrays(a2,a1);
        
        int mid=(n1+n2)/2;
        double ans=-1;
        int l=0,r=min(n1,mid);
        
        while(l<=r)
        {
            int cut1=(l+r)/2;
            int cut2=mid-cut1;
            
            int l1,l2,r1,r2;
            l1=(cut1==0)?INT_MIN:a1[cut1-1];
            l2=(cut2==0)?INT_MIN:a2[cut2-1];
            r1=(cut1>=n1)?INT_MAX:a1[cut1];
            r2=(cut2>=n2)?INT_MAX:a2[cut2];
            
            if(l1>r2)
                r=cut1-1;
            else if(l2>r1)
                l=cut1+1;
            else
            {
                if((n1+n2)%2==0)
                    ans=((double)max(l1,l2)+min(r1,r2))/2;
                else
                    ans=min(r1,r2);
                
                return ans;
            }
        }
        
        return ans;
    }
    */
};