class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0;
        int ans = 0;
        int totalDiff = 0;

        for (int i=0; i < n; i++) {
            int surplus = gas[i] - cost[i];
            fuel += surplus;
            totalDiff += surplus;
            if (fuel < 0) {
                ans = i + 1;
                fuel = 0;
            }
        }

        if (totalDiff < 0) return -1;
        else return ans;
    }
};