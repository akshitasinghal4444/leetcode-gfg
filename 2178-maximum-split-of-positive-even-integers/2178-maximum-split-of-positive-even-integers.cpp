class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        
        if(s%2!=0)
            return {};
        
        vector<long long> ans;
        
        for(long long i=2;s>=i;i+=2)
        {
            ans.push_back(i);
            s-=i;
        }
        
        if(s!=0)
        {
            long long i=ans.back();
            ans.pop_back();
            ans.push_back(i+s);
        }
        
        return ans;
        
    }
};

/*

28
2-26
4-22
6-14
8-6

*/