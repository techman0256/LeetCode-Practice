class Solution {
public:
    // writing DSU
    int findParent(int u, vector<int> &parent) {
        if (parent[u] == u) return u;

        return parent[u] = findParent(parent[u], parent);
    }
    void unionByLex(int u, int v, vector<int> &parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pv == pu) return;

        if (pu < pv) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
        }

        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // graph representation of string
        vector<int> parent(26);
        // vector<int> size(26, 1);
        for (int i=0; i < 26; i++) {
            parent[i] = i;
        }
        // convert to nodes

        for (int i=0; i < s1.length(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            unionByLex(u, v, parent);
        }

        string ans = "";
        for (int i=0; i < baseStr.size(); i++) {
            ans += (findParent(baseStr[i] - 'a', parent) + 'a');
        }

        return ans;
    }


};