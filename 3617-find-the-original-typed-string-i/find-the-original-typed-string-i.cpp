class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int answer = 0;
        char curr = word[0];
        int freq = 0;
        for (int i=0; i < n; i++) {
            if (curr == word[i]) {
                freq++;
            } else {
                answer += freq - 1;
                curr = word[i];
                freq = 1;
            }
        }
        answer += freq - 1;

        return answer + 1;
    }
};