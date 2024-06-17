class Solution {
public:
    static void generate(string now, int open, int close, int n, vector<string> &ans) {
        // base case
        if (close == n) {
            ans.push_back(now);
            return;
        }

        // int last = now[now.length() - 1];
        if (open == close && open < n) {
            generate(now + '(', open + 1, close, n, ans);
        } else if (open > close ) {
            if (open < n) {
                generate(now + '(', open + 1, close, n, ans);
            }
            generate(now + ')', open, close + 1, n, ans);
        }
        return;
       
    }
    vector<string> generateParenthesis(int n) {
        // stack<char> stk;
        vector<string> ans;

        generate("", 0, 0, n, ans);
        return ans; 


    }
};