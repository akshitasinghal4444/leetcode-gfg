class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        
        if(n<3)
            return 0;
        
        int i,c=0,d=a[1]-a[0],st=0;
        
        for(i=1;i<n;i++)
        {
            if(d==a[i]-a[i-1])
                continue;
            else
            {
                d=a[i]-a[i-1];
                int x=i-st;
                st=i-1;
                if(x>=3)
                c+=((x+1)*(x-3+1))-((x*(x+1))/2-3);
            }
        }
        int x=i-st;
        if(x>=3)
        c+=((x+1)*(x-3+1))-((x*(x+1))/2-3);
        // cout<<x<<endl;
        return c;
    }
};