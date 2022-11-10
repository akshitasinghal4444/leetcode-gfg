class Solution {
public:
    string removeDuplicates(string str) 
    {
        string ans;
        for(auto i:str)
        {
            if(!ans.empty() and ans.back()==i)
                ans.pop_back();
            else
                ans.push_back(i);
        }
        return ans;
    }
};