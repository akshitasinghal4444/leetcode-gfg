class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        
        while(n>0)
        {
            // cout<<n<<" ";
            if(n%2)
                c++;
            // cout<<c<<endl;
            n=n/2;
        }
        return c;
    }
};