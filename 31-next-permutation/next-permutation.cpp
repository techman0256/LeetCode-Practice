class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int bp = -1;    //break-point
        for (int i=n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }

        if (bp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        cout << bp << endl;
        int pivot = bp + 1;
        for (int i=bp + 1; i < n; i++) {
            if (nums[i] > nums[bp] && nums[i] <= nums[pivot]) {
                pivot = i;
            }
        }
        cout << nums[pivot] << endl;

        swap(nums[pivot], nums[bp]);
        reverse(nums.begin() + bp + 1, nums.end());


        return;

    }
};