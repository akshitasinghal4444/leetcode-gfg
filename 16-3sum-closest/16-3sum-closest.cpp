class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int n=a.size();
        int ans=a[0]+a[1]+a[2];
        
        sort(a.begin(),a.end());
        int i;
        for(i=0;i<n-2;i++)
        {
            int l,r;
            l=i+1;
            r=n-1;
            
            while(l<r)
            {
                int s=a[i]+a[l]+a[r];
                if(abs(t-s)<abs(t-ans))
                    ans=s;
                
                if(s>t)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};