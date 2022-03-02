class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> a2=a;
        sort(a2.begin(),a2.end());
        
        int n=a.size();
        int s=0,e=n-1;
        
        while(s<n && a[s]==a2[s])
            s++;
        
        if(s==n)
            return 0;
        
        while(e>=0 && a[e]==a2[e])
            e--;
        
        return e-s+1;
    }
};