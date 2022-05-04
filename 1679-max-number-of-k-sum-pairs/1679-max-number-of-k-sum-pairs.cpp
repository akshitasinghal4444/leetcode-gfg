class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        
        unordered_map<int,int> m;
        int c=0;
        
        for(int n:a)
        {
            if(m[k-n]>0)
            {
                m[k-n]--;
                c++;
            }
            else
                m[n]++;
        }
        
        return c;
        
    }
};