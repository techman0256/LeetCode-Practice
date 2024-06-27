class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int win = 0;
        int start = 0;
        int end = 0;

        if (n == 1) return nums[0];


        while (start < n) {
            // skip zeroes
            while (start < n && nums[start] == 0) {
                start++;
            }
            end = start;
            while (end < n && nums[end] != 0) {
                end++;
            }
            win = max(win, end - start);
            start = end;

        }

        return win;
    }
};