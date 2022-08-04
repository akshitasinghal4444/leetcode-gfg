class Solution {
public:
    int majorityElement(vector<int>& a) {
        int i,n=a.size();
        int c=0,m=a[0];
        
        for(i=0;i<n;i++)
        {
            if(a[i]==m)
                c++;
            else
                c--;
            
            if(c==0)
            {
                m=a[i];
                c=1;
            }
        }
        
        return m;
    }
};