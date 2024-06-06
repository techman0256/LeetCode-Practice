class Solution {
public:
    void generate(string str, int open, int close, stack<char> top, int n, vector<string> &ans) {
        if (str.size() == 2 * n) {
            cout << "lol";
            ans.push_back(str);
           
        }
        
        int len = str.length();
        // cout << top.size() << " " << len << endl;

        if (top.size() < n and open < n) {
            top.push('(');
            generate(str + '(', open +1, close, top, n, ans);
        }
        if (!top.empty() and top.top() == '(' and close < open) {
            top.pop();
            cout << open <<  " " << close << endl;
            generate(str + ')', open, close + 1, top, n, ans);
        }
        
        // return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> top;
        // top.push('(');
        generate("", 0, 0, top, n, ans);
        return ans;
    }
};