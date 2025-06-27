class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        map<string, vector<string>> hash;

        for (int i=0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            hash[s].push_back(strs[i]);
        }

        vector<vector<string>> answer;
        for (auto h : hash) {
            answer.push_back(h.second);
        }

        return answer;
    }
};