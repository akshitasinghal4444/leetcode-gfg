class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1,t1;
        
        for(char c:s)
        {
            if(c=='#')
            {
                if(s1.size())
                    s1.pop_back();
            }
            else
                s1+=c;
        }
        
        for(char c:t)
        {
            if(c=='#')
            {
                if(t1.size())
                    t1.pop_back();
            }
            else
                t1+=c;
        }
        
        return s1==t1;
    }
};