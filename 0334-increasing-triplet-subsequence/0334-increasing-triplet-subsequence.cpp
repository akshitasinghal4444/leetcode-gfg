class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n1=INT_MAX,n2=INT_MAX;
        
        for(int x:a)
        {
            if(x>n2)
                return 1;
            
            if(x<=n1)
                n1=x;
            else if(x<n2)
                n2=x;
        }
        
        return 0;
    }
};