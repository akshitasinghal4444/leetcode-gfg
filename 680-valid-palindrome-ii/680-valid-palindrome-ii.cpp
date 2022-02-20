class Solution {
public:
    bool validPalindrome(string s,bool f=0) {
        int j=s.length()-1;
        int i=0;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else if(f)
                return 0;
            else
            {
                return validPalindrome(s.substr(i,j-1-i+1),1) || validPalindrome(s.substr(i+1,j-i-1+1),1);
            }
        }
        return 1;
    }
};

