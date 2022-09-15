class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        int i;
        vector<int> t;
        
        k=k%n;
        
        for(i=n-k;i<n;i++)
            t.push_back(a[i]);
        
        for(i=n-k-1;i>=0;i--)
            a[i+k]=a[i];
        
        for(i=0;i<k;i++)
            a[i]=t[i];
         
    }
};