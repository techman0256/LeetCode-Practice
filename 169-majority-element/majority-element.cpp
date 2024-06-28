class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int count = 0;

        for (int i=0; i < n; i++) {
            if (count == 0) {
                maxi = nums[i];
                count = 1;
            } else {
                if (nums[i] == maxi) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        // if (count == 0) {
        //     for (int i=0; i < n; i++) {
        //         if (nums[i] == maxi) {
        //             count++;
        //         }
        //     }
        //     if (count > (n / 2)) return maxi
        // }
        return maxi;
    }
};