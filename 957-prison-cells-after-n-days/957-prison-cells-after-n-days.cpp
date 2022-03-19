class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> a;

        int i;
        
        while(n--)
        {
            vector<int> t(8);
            t[0]=t[7]=0;
            
            for(int j=1;j<7;j++)
            {
                if(cells[j-1]==cells[j+1])
                    t[j]=1;
                else
                    t[j]=0;
            }
            
            if(a.size()>0 && t==a[0])
                return a[n%a.size()];
            else
                a.push_back(t);
            
            cells=t;
        }
        
        return cells;
    }
};