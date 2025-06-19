class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int min = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] - nums[min] > k) {
                min = i;
                count++;
            }
        }
        return count + 1;
    }
};