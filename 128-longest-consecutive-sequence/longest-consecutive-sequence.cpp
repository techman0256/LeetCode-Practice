class Solution {
public:
    int findParent(int node, map<int, int> &parent) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        map<int, int> parent;
        map<int, int> size;
        for (int i=0; i < n; i++) {
            if (parent.find(nums[i]) != parent.end()) {
                continue;
            }
            parent[nums[i]] = nums[i];
            size[nums[i]] = 1;
            int pu = findParent(nums[i], parent);
            if ( parent.find(nums[i] + 1) != parent.end() ) {
                int pv = findParent(parent[nums[i] + 1], parent);

                parent[pv] = pu;
                size[pu] += size[pv];
                size[pv] = 0;
            }
            if ( parent.find(nums[i] - 1) != parent.end() ) {
                int pv = findParent(parent[nums[i] - 1], parent);
                parent[pv] = pu;
                size[pu] += size[pv];
                size[pv] = 0;
            }
        }

        int ans = 0;
        for (auto pair: size) {
            ans = max(ans, pair.second);
        }

        return ans;
    }
};