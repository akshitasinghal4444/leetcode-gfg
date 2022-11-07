class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        
        return stoi(s);
    }
};