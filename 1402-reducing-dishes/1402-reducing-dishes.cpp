class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(),a.end());
        int i,j,n,s=0;
        n=a.size();
        
        for(i=n-1;i>=0;i--)
        {
            if(a[i]<0 && s<-a[i])
                break;
            s+=a[i];
        }
        
        s=0;
        j=1;
        for(i=i+1;i<n;i++,j++)
            s+=(a[i]*j);
        
        return s;
        
    }
};