class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int x=0;
        for(int n:a)
            x^=n;
        
        return x;
    }
};