class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int i,n=a.size();
        int m1=-1,m2=-1,c1=0,c2=0;
        vector<int> ans;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==m1)
                c1++;
            else if(a[i]==m2)
                c2++;
            else if(c1==0)
            {
                m1=a[i];
                c1=1;
            }
            else if(c2==0)
            {
                m2=a[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        c1=0,c2=0;
        for(i=0;i<n;i++)
        {
            if(m1==a[i])
                c1++;
            else if(m2==a[i])
                c2++;
        }
        
        if(c1>n/3)
            ans.push_back(m1);
        
        if(c2>n/3)
            ans.push_back(m2);
        
        return ans;
    }
};