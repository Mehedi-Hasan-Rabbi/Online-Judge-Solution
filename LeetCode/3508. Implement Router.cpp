class Router {
    int memLim = 0;
    queue<vector<int>> q;
    set<vector<int>> isExists;
    map<int, deque<int>> timeMap;
public:
    Router(int memoryLimit) {
        this->memLim = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};

        // If duplicate packet found
        if (isExists.count(packet))
            return false;
        
        // If memory is full then remove first packet
        if (q.size() == memLim) {
            vector<int> pac = q.front();
            q.pop();

            isExists.erase(pac);
            timeMap[pac[1]].pop_front();
        }
        
        // Add new packet
        q.push(packet);
        isExists.insert(packet);
        timeMap[packet[1]].push_back(packet[2]);

        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> pac = {};

        if (!q.empty()) {
            pac = q.front();
            q.pop();
            
            isExists.erase(pac);
            timeMap[pac[1]].pop_front();
        }

        return pac;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto l = lower_bound(timeMap[destination].begin(), timeMap[destination].end(), startTime);
        auto r = upper_bound(timeMap[destination].begin(), timeMap[destination].end(), endTime);

        return (r - l);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */