class Solution {
public:
    void findNGE(vector<int> &arr, vector<int> &nge, bool right) {
        int n = arr.size();

        stack<int> stk;
        if (right == true) {
            for (int i=n - 1; i >= 0; i--) {
                while(!stk.empty() && stk.top() <= arr[i]) {
                    stk.pop();
                }
                if (!stk.empty()) {
                    nge[i] = stk.top();
                } else {
                    stk.push(arr[i]);
                }
            }
        } else {
            for (int i=0; i < n; i++) {
                while(!stk.empty() && stk.top() <= arr[i]) {
                    stk.pop();
                }
                if (!stk.empty()) {
                    nge[i] = stk.top();
                } else {
                    stk.push(arr[i]);
                }
            }
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> heightRev = height;
        vector<int> ngr(n, -1);
        vector<int> ngl(n, -1);
        sort(heightRev.begin(), heightRev.end(), greater<int>());

        findNGE(height, ngr, true);
        findNGE(height, ngl, false);

        int water = 0;

        for (int i=0; i < n; i++) {
            if (ngl[i] != -1 && ngr[i] != -1) {
                water += min(ngr[i], ngl[i]) - height[i];
            }
        }
        return water;
    }
};