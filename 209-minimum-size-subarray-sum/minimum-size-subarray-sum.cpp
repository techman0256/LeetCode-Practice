class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int win_len = INT_MAX;
        int sum = 0;
        int start = 0, end = 0;
        while (end < n) {
            cout << start << " " << end << endl;
            if (sum >= target) {
                cout << " lol " << endl;
                win_len = min(end - start , win_len);
                sum -= nums[start];
                start++;

            } else {
                sum += nums[end];
                end++;

            }
            cout << sum << endl;

        }

        while (start < n && sum >= target) {
                win_len = min(end - start, win_len);
                sum -= nums[start];
                start++;
        }

        if (win_len == INT_MAX) {
            return 0;
        }

        return win_len;
    }
};