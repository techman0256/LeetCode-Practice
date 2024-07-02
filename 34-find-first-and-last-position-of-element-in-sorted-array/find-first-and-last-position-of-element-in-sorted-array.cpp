class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        int left = -1, right = n;
        while (right > left + 1 ) {
            int mid = (right + left) /2;

            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if ( right == n || nums[right] != target ) {
            ans.push_back(-1);
        } else {
            
            ans.push_back(right);
        }

        left = -1;
        right = n;

        while (right > left + 1 ) {
            int mid = (right + left) /2;

            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if ( left == -1 || nums[left] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(left);
        }
        

        return ans;
    }
};