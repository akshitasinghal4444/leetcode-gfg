class Solution {
public:
    vector<string> ans;
    string t;
    
    void generate(int l,int r)
    {
        if(r==0)
        {
            ans.push_back(t);
            return;
        }
        
        if(l>0)
        {
            t.push_back('(');
            generate(l-1,r);
            t.pop_back();
        }
        
        if(l<r)
        {
            t.push_back(')');
            generate(l,r-1);
            t.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        generate(n,n);
        return ans;
    }
};