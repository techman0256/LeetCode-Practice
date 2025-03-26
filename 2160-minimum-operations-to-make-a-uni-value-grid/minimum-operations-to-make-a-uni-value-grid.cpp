class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        set<int> reminder;
        for (int i=0; i < arr.size(); i++) {
            reminder.insert(arr[i] % x);
            if (reminder.size() > 1) return -1;
        }
        sort(arr.begin(), arr.end());

        int uniform = arr[arr.size() / 2];
        int result = 0;
        for (int num: arr) {
            result += abs(uniform - num) /x ;
        }

        return result;

    }   
};