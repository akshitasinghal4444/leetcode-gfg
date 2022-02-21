class Solution {
public:
    int countBinarySubstrings(string s) {
        int z=0,o=0,ans=0;
        bool f=0;
        
        for(char c:s)
        {
            if(c=='0')
            {
                if(f)
                {
                    ans+=min(z,o);
                    f=0;
                    z=0;
                }
                z++;
            }
            else
            {
                if(!f)
                {
                    ans+=min(z,o);
                    f=1;
                    o=0;
                }
                o++;
            }
        }
        ans+=min(z,o);
        return ans;
    }
};