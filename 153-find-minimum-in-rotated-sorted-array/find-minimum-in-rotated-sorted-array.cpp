class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0, right = n - 1;

        while ( left <= right ) {
            int mid = (left + right) / 2;
            
            if (nums[left] < nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            if ( nums[left] <= nums[mid] ) {
               // left is sorted
               ans = min(ans, nums[left]);
               left = mid + 1;

            } else {
               // right is sorted
               ans = min(ans, nums[mid]);
               right = mid - 1;
            }
        }

        return ans;
    }
};