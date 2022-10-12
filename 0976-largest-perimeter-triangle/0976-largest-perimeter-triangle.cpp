class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int i,n=a.size();        
        sort(a.begin(),a.end());
        
        for(i=n-1;i>1;i--)
        {
            if(a[i-2]+a[i-1]>a[i])
                return a[i-2]+a[i-1]+a[i];
        }
        
        return 0;
    }
};