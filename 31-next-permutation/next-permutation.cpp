class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int pivot = n;
        for (int i=n - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == n) {
            reverse(nums.begin(), nums.end());
            return;    
        }
        
        int idx = pivot;
        for (int i=n - 1; i >= pivot; i--) {
            if (nums[pivot - 1] < nums[i]) {
                idx = i;
                break;
            }
        }
        
        swap(nums[pivot - 1], nums[idx]);
        reverse(nums.begin() + pivot, nums.end());

        // cout << nums << endl;

        // return nums;

    }
};