class Solution {
public:
    int minPartitions(string s) {
        char c='0';
        
        for(char ch:s)
            c=max(ch,c);
        
        return c-'0';
    }
};