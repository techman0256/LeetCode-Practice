class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        int cnt = 0;

        while (cookie < m && child < n) {
            if (s[cookie] >= g[child]) {
                cnt++;
                cookie++;
                child++;
            } else {
                cookie++;
            } 
        }   

        return cnt;
    }
};