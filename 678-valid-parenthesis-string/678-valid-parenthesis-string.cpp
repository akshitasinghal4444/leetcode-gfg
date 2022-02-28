class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1,s2;
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='(') 
                s1.push(i);
            else if(s[i]=='*')
                s2.push(i);
            else
            {
                if(!s1.empty())
                    s1.pop();
                else if(!s2.empty())
                    s2.pop();
                else
                    return 0;
            }
        }
        
        while(!s1.empty())
        {
            if(!s2.empty() && s2.top()>s1.top())
            {
                s2.pop();
                s1.pop();
            }
            else
                return 0;
        }
        return 1;
    }
};

