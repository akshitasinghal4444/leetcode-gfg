class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    bool isPalindrome(string s)
    {
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return 0;
        }
        
        return 1; 
    }
    
    void partition(string s,int l,int r)
    {
        if(l>r)
        {
            // if(t.size())
            ans.push_back(t);
            return;
        }
        
        for(int i=l;i<=r;i++)
        {
            string s1=s.substr(l,i-l+1);
            if(isPalindrome(s1))
            {
                t.push_back(s1);
                partition(s,i+1,r);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        partition(s,0,s.length()-1);
        return ans;
    }
};