class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - pos[i]) / speed[i];
            cars.push_back({pos[i], time});
        }

        sort(cars.begin(), cars.end());

        int fleets = 0;
        double maxtime = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cars[i].second > maxtime) {
                fleets++;
                maxtime = cars[i].second;
            }
        }
        return fleets;
    }
};