class Solution {
public:
    void reverse(int start, int end, vector<int>& nums) {
        while (start < end) {
            nums[start] = nums[start] ^ nums[end];
            nums[end] = nums[start] ^ nums[end];
            nums[start] = nums[start] ^ nums[end];
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2) {
            return;
        }
        if (k > n) {
            k = k % n;
        }

        reverse(n - k, n - 1, nums);
        reverse(0, n - k - 1, nums);
        reverse(0, n - 1, nums);
    }
};