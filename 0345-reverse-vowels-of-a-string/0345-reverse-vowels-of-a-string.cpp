class Solution {
public:
    
    bool vowel(char c)
    {
        c=tolower(c);
        
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(!vowel(s[i]))
                i++;
            else if(!vowel(s[j]))
                j--;
            else
                swap(s[i++],s[j--]);
        }
        
        return s;
    }
};