class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1,n2;
        n1=pushed.size();
        n2=popped.size();
        
        if(n1!=n2)
            return 0;
        
        int i,j;
        i=0,j=0;
        
        stack<int> st;

        while(i<n1 && j<n2)
        {
            st.push(pushed[i]);
            i++;
            
            while(j<n2 && !st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
    
    /*
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1,n2;
        n1=pushed.size();
        n2=popped.size();
        
        if(n1!=n2)
            return 0;
        
        int i,j;
        i=0,j=0;
        
        stack<int> st;

        while(i<n1 && j<n2)
        {
            while(i<n1 && (st.empty() || st.top()!=popped[j]))
            {
                st.push(pushed[i]);
                i++;
            }
            
            while(j<n2 && !st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        if(i==n1 && j==n2)
            return 1;
        
        return 0;
    }
    */
};