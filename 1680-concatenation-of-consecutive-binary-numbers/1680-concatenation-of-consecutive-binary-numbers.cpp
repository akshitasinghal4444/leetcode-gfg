class Solution {
public:
    

    int concatenatedBinary(int n) {
        
        long ans=0;
        int m=1e9+7;

        for(int i=1;i<=n;i++)
        {
            int bits=log2(i)+1;
            ans=((ans<<bits)%m+i)%m;
        }
        
        return ans;
    }
};