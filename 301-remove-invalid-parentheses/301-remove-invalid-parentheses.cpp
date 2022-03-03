class Solution {
public:
    int l,r;
    unordered_set<string> st,vis;
    
    void countmin(string &s)
    {
        stack<int> st;
        
        for(char ch:s)
        {
            if(ch=='(')
                st.push(ch);
            else if(ch==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(ch);
            }
        }
        
        while(!st.empty())
        {
            if(st.top()==')')
                r++;
            else
                l++;
            
            st.pop();
        }
    }
    
    void removemin(string s,int l,int r)
    {
        if(vis.find(s)==vis.end())
            vis.insert(s);
        else 
            return;
        
        if(l==0 && r==0)
        {
            st.insert(s);
            return;
        }
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                removemin(s.substr(0,i)+s.substr(i+1),l-1,r);
            }
            else if(s[i]==')')
            {
                removemin(s.substr(0,i)+s.substr(i+1),l,r-1);
            }
        }     
    }
    
    bool isValid(string s)
    {
        int c=0;
        
        for(char ch:s)
        {
            if(ch=='(')
                c++;
            else if(ch==')')
            {
                if(c>0)
                    c--;
                else return 0;
            }
        }
        return c==0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        l=0;
        r=0;
        vector<string> ans;
        countmin(s);
        
        removemin(s,l,r);
        
        for(string str:st)
        {
            // cout<<str<<endl;
            if(isValid(str))
                ans.push_back(str);
        }
        
        return ans;
    }
    
    /*
    int l,r;
    unordered_set<string> st,vis;
    
    void countmin(string &s)
    {
        stack<int> st;
        
        for(char ch:s)
        {
            if(ch=='(')
                st.push(ch);
            else if(ch==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(ch);
            }
        }
        
        while(!st.empty())
        {
            if(st.top()==')')
                r++;
            else
                l++;
            
            st.pop();
        }
    }
    
    void removemin(string s,int c)
    {
        if(vis.find(s)==vis.end())
            vis.insert(s);
        else
            return;

        
        if(c==0)
        {
            st.insert(s);
            return;
        }
                
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            removemin(s.substr(0,i)+s.substr(i+1),c-1);
        }     
    }
    
    bool isValid(string s)
    {
        int c=0;
        
        for(char ch:s)
        {
            if(ch=='(')
                c++;
            else if(ch==')')
            {
                if(c>0)
                    c--;
                else return 0;
            }
        }
        return c==0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        l=0;
        r=0;
        vector<string> ans;
        countmin(s);
        
        removemin(s,l+r);
        
        for(string str:st)
        {
            // cout<<str<<endl;
            if(isValid(str))
                ans.push_back(str);
        }
        
        return ans;
    }
    
    */
};