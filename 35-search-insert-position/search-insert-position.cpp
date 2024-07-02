class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int left = -1, right = n;

        while (right > left + 1) {
            int mid = (left + right) /2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

    
        return right;
    }
};