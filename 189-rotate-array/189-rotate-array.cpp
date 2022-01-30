class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
    }
    
    /*
    void reverse(vector<int>& a,int l,int r)
    {
        while(l<r)
        {
            int t=a[l];
            a[l]=a[r];
            a[r]=t;
            
            l++;
            r--;
        }
    }
    
    void rotate(vector<int>& a, int k) {
        int n=a.size();
        k=k%n;
        
        reverse(a,0,n-k-1);
        reverse(a,n-k,n-1);
        reverse(a,0,n-1);
    }
    */
};