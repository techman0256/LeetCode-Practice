class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;

        for (auto& rect : rectangles) {
            x.push_back({rect[0], rect[2]});
        }
        sort(x.begin(), x.end(), compare);
        bool vertical = lineSweep(x);

        for (auto& rect : rectangles) {
            y.push_back({rect[1], rect[3]});
        }
        sort(y.begin(), y.end(), compare);
        bool horizontal = lineSweep(y);

        return horizontal || vertical;
    }

    bool lineSweep(vector<vector<int>>& intervals) {
        vector<vector<int>> section;

        for (auto& interval : intervals) {
            // If no interval exists OR touching intervals should be separate
            if (section.empty() || section.back()[1] <= interval[0]) { 
                section.push_back(interval);
            } else { 
                // Overlapping interval -> Merge
                section.back()[1] = max(section.back()[1], interval[1]);
            }
        }

        return section.size() > 2;  // Valid cut if more than 2 sections
    }
};
