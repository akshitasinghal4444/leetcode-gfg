class Solution {
public:
    double champagneTower(int p, int r, int g) {
       if(p==0)
           return 0;
        
        vector<double> a,t;
        double x;
        a.push_back((double)p);
        int row=1;
        while(row<=r)
        {
            if(row==1)
            {
                x=max(0.0,(a[0]-1)/2);
                t.push_back(x);
                t.push_back(x);
            }
            else 
            {
                int c=0;
                if(a[0]==0)
                    c++;
                t.push_back(max(0.0,(a[0]-1)/2));
                for(int i=1;i<a.size();i++)
                {
                    if(a[i]==0)
                    c++;
                    t.push_back(max(0.0,((a[i]-1)/2))+max(0.0,(a[i-1]-1)/2));
                }
                t.push_back(max(0.0,(a[0]-1)/2));
                if(c==a.size())
                    return 0;
            }
            
            a=t;
            t.clear();
            row++;
        }
        return min(1.0,a[g]);
    }
};