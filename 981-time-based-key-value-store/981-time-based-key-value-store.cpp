class TimeMap {
public:
    unordered_map<string,map<int,string>> m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        m[key][time]=value;
    }
    
    string get(string key, int time) {

        auto it=m[key].upper_bound(time);
        
        if(it==m[key].begin())
            return "";
        
        it--;
        return it->second;
    }
};

/*
class TimeMap {
public:
    unordered_map<string,vector<string>> m1;
    unordered_map<string,vector<int>> m2;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        m1[key].push_back(value);
        m2[key].push_back(time);
    }
    
    string get(string key, int time) {

        int in=upper_bound(m2[key].begin(),m2[key].end(),time)-m2[key].begin();
        
        if(in==0)
            return "";
        
        return m1[key][in-1];
    }
};
*/

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */