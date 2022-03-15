class Solution {
public:
    string simplifyPath(string p)
    {
        if(p.back()!='/')
            p+='/';
        
        int i,n=p.length();
        string s="";
        int flag=0;
        
        for(i=n-2;i>=0;i--)
        {
            if(p[i]=='/' && (p[i+1]=='/' || s.back()=='/'))
                continue;
            else if(p[i]=='.' && p[i+1]=='/')
            {
                int c=0;
                while(i>=0 && p[i]=='.')
                {
                    c++;
                    i--;
                }
                
                if((i>=0 && p[i]!='/') || c>2)
                {
                    while(c--)
                        s+='.';
                }
                else if(c==2)
                    flag++;
                
                i++;
            }
            else if(flag>0 && p[i]!='/')
            {
                while(i>=0 && p[i]!='/')
                    i--;
                
                flag--;
            }
            else
                s+=p[i];
        }
        
        reverse(s.begin(),s.end());
        
        if(s.back()=='/' && s.size()>1)
            s.pop_back();
            
        if(s.size()==0)
            return "/";
        
        return s;
    }
    
    /*
    string simplifyPath(string p)
    {
        int i,n=p.length();
        string s="/";
        
        for(i=1;i<n;i++)
        {
            if(p[i]=='/' && (p[i-1]=='/' || s.back()=='/'))
                continue;
            else if(p[i]=='.' && p[i-1]=='/')
            {
                int c=0;
                while(i<n && p[i]=='.')
                {
                    i++;
                    c++;
                }
                
                if(c>2 || (i<n && p[i]!='/'))
                {
                    while(c--)
                        s+='.';
                }                
                else if(c==2 && s.size()>1)
                {
                    s.pop_back();
                    
                    while(s.back()!='/')
                        s.pop_back();
                }

                i--;
            }
            else
                s+=p[i];
        }
        
        if(s.size()>1 && s.back()=='/')
            s.pop_back();
        
        return s;
    }
    */
    
    /*
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/')    
                continue;
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
			// pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        }
        
		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
    */
};