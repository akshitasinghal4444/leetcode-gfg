class UndergroundSystem {
public:
    
    unordered_map<int,pair<string,int>> checkin;
    unordered_map<string,pair<int,int>> route;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [start,t1]=checkin[id];
        
        route[start+","+stationName].first++;
        route[start+","+stationName].second+=t-t1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double time=route[startStation+","+endStation].second;
        int n=route[startStation+","+endStation].first;
        
        return time/n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */