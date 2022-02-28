class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string t="";
        
        for(char ch:s)
        {
            if(c!=0)
                t+=ch;
            
            if(ch=='(')
                c++;
            else
                c--;
            
            if(c==0)
                t.pop_back();
        }
        
        return t;
    }
};