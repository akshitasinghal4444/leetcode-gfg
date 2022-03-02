class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int z=0;
        vector<int> ans;
        long p=1;
        
        for(int n:a)
        {
            if(n==0)
                z++;
            else
                p*=n;
        }
        
        for(int n:a)
        {
            if(z>=2)
            ans.push_back(0);
            else if(z==1)
            {
                if(n==0)
                    ans.push_back(p);
                else
                    ans.push_back(0);
            }
            else
                ans.push_back(p/n);
        }
        return ans;
    }
};