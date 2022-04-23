class Solution {
public:

    unordered_map<string,int> freq;
    unordered_map<string,string> l_to_s,s_to_l;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if(l_to_s.find(longUrl)!=l_to_s.end())
            return l_to_s[longUrl];
        
        string t="";
        for(int i=0;i<10;i++)
            t+=(rand()%256);
        
        freq[t]++;
        t+=to_string(freq[t]);
        
        l_to_s[longUrl]=t;
        s_to_l[t]=longUrl;
        
        return t;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s_to_l[shortUrl];
    }
};


/*
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortUrl;
    }
};
*/

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));