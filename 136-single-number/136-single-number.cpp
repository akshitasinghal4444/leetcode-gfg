class Solution {
public:
    int singleNumber(vector<int>& a) {
        int ans=0;
        
        for(int x:a)
            ans^=x;
        
        return ans;
    }
};