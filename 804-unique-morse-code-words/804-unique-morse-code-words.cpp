class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string m[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-"             ,".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> ans;
        
        for(string s:words)
        {
            string t="";
            
            for(char c:s)
                t+=m[c-'a'];
            
            ans.insert(t);
        }
        
        return ans.size();
    }
};