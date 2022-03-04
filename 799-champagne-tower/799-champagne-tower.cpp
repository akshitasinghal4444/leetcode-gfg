class Solution {
public:
    double champagneTower(int p, int r, int g)
    {
        if(p==0)
            return 0;
        
        vector<double> v1,v2;
        
        v1.push_back(p);
        
        int row=1;
        while(row<=r)
        {
            int empty=0;
            if(v1[0]==0)
                empty++;
            
            v2.push_back(max(0.0,(v1[0]-1)/2));
                   
            int i,n=v1.size();
            for(int i=1;i<n;i++)
            {
                if(v1[i]==0)
                    empty++;
                
                v2.push_back(max(0.0,(v1[i]-1)/2)+max(0.0,(v1[i-1]-1)/2));
            }
            
            v2.push_back(max(0.0,(v1[0]-1)/2));
            
            if(empty==n)
                return 0;
            
            v1=v2;
            v2.clear();
            row++;
        }
        
        return min(v1[g],1.0);
    }
    
    /*
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
    */
};