class Solution {
public:
    int singleNumber(vector<int>& a) {
        int x=0;
        for(int n:a)
            x=x^n;
        return x;
    }
};