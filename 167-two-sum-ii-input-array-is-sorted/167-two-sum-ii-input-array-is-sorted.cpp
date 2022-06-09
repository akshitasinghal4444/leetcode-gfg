class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int i=0;
        int j=a.size()-1;
        // vector<int> ans;
        
        while(i<j)
        {
            int s=a[i]+a[j];
            if(s==t)
                return {i+1,j+1};
            if(s<t)
                i++;
            else
                j--;
        }
        return {};
        
    }
};