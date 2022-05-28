class Solution {
public:
    int missingNumber(vector<int>& a)
    {
        int i,n=a.size();
        int s=0;
        
        for(i=0;i<n;i++)
            s+=i-a[i];
        
        s+=n;
        
        return s;
    }
    
    /*
    int missingNumber(vector<int>& a) {
        int i,n=a.size();
        
        int x=0;
        for(i=0;i<n;i++)
            x=x^i^a[i];
        
        x=x^n;
        
        return x;
    }
    */
};