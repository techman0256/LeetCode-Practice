class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> dist;
        for (int num : nums) {
            dist[num]++;
        }
        int dist_in_array = dist.size();
        dist.clear();
        int count = 0;
        int start = 0, end = 0;
        
        while (end < n) {
            dist[nums[end]]++;
            while (dist.size() == dist_in_array) {
                count += n - end;
                cout << start << " " << end << " " << endl;
                dist[nums[start]]--;
                if (dist[nums[start]] == 0) dist.erase(nums[start]);
                start++;
            }
            end++;
        }
        
        return count;
    }
};