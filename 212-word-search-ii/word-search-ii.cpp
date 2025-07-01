class TrieNode {
public:
    TrieNode* links[26];
    string word; // store word at leaf

    TrieNode() {
        for (int i = 0; i < 26; ++i) links[i] = nullptr;
        word = "";
    }
};

class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    TrieNode* root;

    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a']) {
                node->links[ch - 'a'] = new TrieNode();
            }
            node = node->links[ch - 'a'];
        }
        node->word = word; // store full word at the end
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char ch = board[i][j];
        if (ch == '#' || !node->links[ch - 'a']) return;

        node = node->links[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // avoid duplicate entries
        }

        board[i][j] = '#'; // mark visited
        for (int k = 0; k < 4; k++) {
            int newx = i + dir[k][0];
            int newy = j + dir[k][1];
            if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                dfs(board, newx, newy, node, result);
            }
        }
        board[i][j] = ch; // restore
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        root = new TrieNode();

        // Step 1: Insert all words into Trie
        for (string& word : words) {
            insert(word);
        }

        vector<string> result;

        // Step 2: DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
