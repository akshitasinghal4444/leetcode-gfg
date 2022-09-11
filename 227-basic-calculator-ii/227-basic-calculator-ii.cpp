class Solution {
public:
    int calc(int a,int b,char op)
    {
        if(op=='+')
            return a+b;
        else if(op=='-')
            return a-b;
        else if(op=='*')
            return a*b;
        else
            return a/b;
        
    }
    
    int calculate(string s) {
        stack<char> s1;
        stack<int> s2;
        string t="";
        unordered_map<char,int> m={{'-',0},{'+',0},{'*',1},{'/',1}};
        
        for(char c:s)
        {
            if(c>='0' && c<='9')
                t+=c;
            else if(c!=' ')
            {
                s2.push(stoi(t));
                t="";
                
                while(!s1.empty() && m[s1.top()]>=m[c])
                {
                    int a,b;
                    char op=s1.top();
                    
                    s1.pop();
                    
                    b=s2.top();
                    s2.pop();
                    
                    a=s2.top();
                    s2.pop();
                    
                    s2.push(calc(a,b,op));
                }
                
                s1.push(c);
            }
        }
        
        if(!t.empty())
            s2.push(stoi(t));
        
        while(!s1.empty())
        {
            int a,b;
            char op=s1.top();
            s1.pop();
            
            b=s2.top();
            s2.pop();
                    
            a=s2.top();
            s2.pop();
                    
            s2.push(calc(a,b,op));
        }
        
        return s2.top();
        
    }
};