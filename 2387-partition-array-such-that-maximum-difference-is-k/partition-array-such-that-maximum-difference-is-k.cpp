class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int min = nums[0];
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] - min > k) {
                min = nums[i];
                count++;
            }
        }
        return count + 1;
    }
};