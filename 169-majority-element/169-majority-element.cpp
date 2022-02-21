class Solution {
public:
    int majorityElement(vector<int>& a) 
    {
        int c=0,m=a[0];
        
        for(int n:a)
        {
            if(n==m)
                c++;
            else
                c--;
            
            if(c==0)
            {
                m=n;
                c=1;
            }
        }
        return m;
    }
    
    /*    
    int majorityElement(vector<int>& a) {
        int n=a.size();
        if(n==1)
            return a[0];
        sort(a.begin(),a.end());
        int c=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                c++;
            }
            else
            {
                if(c>n/2)
                return a[i-1];
                c=1;
            }
            
        }
        if(c>n/2)
        return a[n-1];
                
        return 0;
    }
    */
};