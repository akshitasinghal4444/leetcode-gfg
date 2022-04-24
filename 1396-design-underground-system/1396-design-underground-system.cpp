class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkins;
    unordered_map<string, pair<int, int>> routes;
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [stn, start] = checkins[id];
        // checkins.erase(id);
        string route = stn + "," + stationName;
        routes[route].first++, routes[route].second += t - start;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& [count, sum] = routes[startStation + "," + endStation];
        return (double)sum / count;
    }
};

/*
class UndergroundSystem {
public:
    
    unordered_map<string,unordered_set<int>> in_station,out_station;
    unordered_map<string,double> in_id,out_id;
    
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in_station[stationName].insert(id);
        in_id[to_string(id)+stationName]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        out_station[stationName].insert(id);
        out_id[to_string(id)+stationName]=t;
    }
    
    double getAverageTime(string startStation, string endStation) {
             
        double sum=0,n=0;
        for(int id:in_station[startStation])
        {
            if(out_station[endStation].find(id)!=out_station[endStation].end())
            {
                double st,et;
                st=in_id[to_string(id)+startStation];
                et=out_id[to_string(id)+endStation];
                sum+=et-st;
                n++;
            }
        }
        return sum/n;
    }
};
*/

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */