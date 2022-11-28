class TimeMap {
public:
    unordered_map<string,vector<int>> kt;  //key-timestamps
    unordered_map<string,vector<string>> kv;  //key-values
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        kt[key].push_back(timestamp);
        kv[key].push_back(value);
    }
    
    string get(string key, int timestamp) {
        int in=upper_bound(kt[key].begin(),kt[key].end(),timestamp)-kt[key].begin();
        
        if(in==0)
            return "";
        
        return kv[key][in-1];
    }
};

/*
class TimeMap {
public:
    unordered_map<string,vector<int>> kt;  //key-timestamps
    unordered_map<string,unordered_map<int,string>> ktv;    //key-(timestamps,value)
    
    TimeMap() {}
    
    int bin_search(vector<int> &a,int t)
    {
        int l=0,h=a.size()-1;
        int ans=-1;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(a[mid]==t)
                return t;
            
            if(a[mid]<t)
            {
                ans=a[mid];
                l=mid+1;
            }
            else
                h=mid-1;
        }
        
        return ans;
    }
    
    void set(string key, string value, int timestamp) {
        kt[key].push_back(timestamp);
        ktv[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        int t=bin_search(kt[key],timestamp);
        return ktv[key][t];
    }
};
*/

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */