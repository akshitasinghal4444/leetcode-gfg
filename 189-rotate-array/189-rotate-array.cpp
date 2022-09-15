class Solution {
public:
    void rotate(vector<int>& a, int k)
    {
        int i,n=a.size();
        k=k%n;
        
        if(k==0)
            return;
        
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
    }
    
    /*
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
    */
};