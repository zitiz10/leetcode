class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> requestCount(k, 0);
        
        // Min-heap to store busy servers: {free_time, server_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
        
        // Set to store currently available servers
        set<int> availableServers;
        for (int i = 0; i < k; ++i) {
            availableServers.insert(i);
        }
        
        for (int i = 0; i < n; ++i) {
            long long currTime = arrival[i];
            long long duration = load[i];
            
            // 1. Free up servers whose tasks have finished by currTime
            while (!busyServers.empty() && busyServers.top().first <= currTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            
            // 2. If no servers are available, drop the request
            if (availableServers.empty()) {
                continue;
            }
            
            // 3. Find the preferred server using lower_bound starting from (i % k)
            int target = i % k;
            auto it = availableServers.lower_bound(target);
            
            // If no server >= target is available, wrap around to the beginning of the set
            if (it == availableServers.end()) {
                it = availableServers.begin();
            }
            
            int assignedServer = *it;
            
            // 4. Assign the request to this server
            availableServers.erase(it);
            busyServers.push({currTime + duration, assignedServer});
            requestCount[assignedServer]++;
        }
        
        // 5. Find the maximum requests handled by any server
        int maxRequests = 0;
        for (int count : requestCount) {
            maxRequests = max(maxRequests, count);
        }
        
        // 6. Collect all servers that handled the maximum requests
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};