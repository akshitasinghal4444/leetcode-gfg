class Solution {
public:
    int twoEggDrop(int n) {
        int x=0;
        while(n>0)
        {
            x++;
            n-=x;
        }
        return x;
    }
};