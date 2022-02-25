class Solution {
public:
    int score(vector<int>& a,int l,int r)
    {
        if(l>r)
            return 0;
        return max(a[l]-score(a,l+1,r),a[r]-score(a,l,r-1));
        
        // if(turn==0)
        // {
        //     return max(a[l]-score(a,l+1,r,!turn),a[r]-score(a,l,r-1,!turn));
        // }
        // else
        //     return min(a[l]-score(a,l+1,r,!turn),a[r]-score(a,l,r-1,!turn));        
    }
    
    bool PredictTheWinner(vector<int>& a) {
        return score(a,0,a.size()-1)>=0;
    }
    
    /*
    int score(vector<int>& a,int l,int r,bool turn)
    {
        if(l>r)
            return 0;
        
        if(turn==0)
        {
            return max(a[l]+score(a,l+1,r,!turn),a[r]+score(a,l,r-1,!turn));
        }
        else
            return min(-a[l]+score(a,l+1,r,!turn),-a[r]+score(a,l,r-1,!turn));        
    }
    
    bool PredictTheWinner(vector<int>& a) {
        return score(a,0,a.size()-1,0)>=0;
    }
    
    */
};