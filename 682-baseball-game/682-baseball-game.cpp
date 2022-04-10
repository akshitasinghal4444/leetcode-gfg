class Solution {
public:
    int calPoints(vector<string>& ops)
    {
        vector<int> a;
        int j=-1;
        
        for(string s:ops)
        {
            if(s=="C")
            {
                a.pop_back();
                j--;
            }
            else if(s=="D")
            {
                a.push_back(2*a[j]);
                j++;
            }
            else if(s=="+")
            {
                a.push_back(a[j]+a[j-1]);
                j++;
            }
            else
            {
                a.push_back(stoi(s));
                j++;
            }
        }
        
        int ans=0;
        
        while(j>=0)
            ans+=a[j--];
        
        return ans;
    }
    
    /*
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(string s:ops)
        {
            if(s=="C")
                st.pop();
            else if(s=="D")
                st.push(2*st.top());
            else if(s=="+")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                
                st.push(x+y);
            }
            else
                st.push(stoi(s));
        }
        
        int ans=0;
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
    */
};