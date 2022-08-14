class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        
        for(char c:s)
            m[c]++;
        
        int ans=0;
        bool odd=0;
        
        for(auto it:m)
        {
            if(it.second%2!=0)
                odd=1;
            
            ans+=(it.second%2==0)?it.second:it.second-1;
        }
        if(odd)
            ans++;
        return ans;
    }
};