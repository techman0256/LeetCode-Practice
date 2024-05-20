import java.util.*;
class Solution {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;

        ArrayList<ArrayList<Integer>> qmap = new ArrayList<>();
        for (int i=0; i < m; i++) {
            qmap.add(new ArrayList<>());
            qmap.get(i).add(queries[i][1]);
            qmap.get(i).add(queries[i][0]);
            qmap.get(i).add(i);
        }

        Arrays.sort(nums);
        Collections.sort(qmap, (a, b) -> a.get(0) - b.get(0)); 

        int ans[] = new int[m];
        Trie t = new Trie();
        int i=0;

        for (ArrayList<Integer> query : qmap) {
            int m_i = query.get(0);
            int x = query.get(1);

            while (i < n && nums[i] <= m_i) {
                t.insert(nums[i]);
                i++;
            }

            int XOR = t.maxXOR(x);
            ans[query.get(2)] = XOR;
        }

        // for (int i=0; i < m; i++) {
        //     System.out.println(qmap.get(i).toString());
        // }



        return ans;
    }
}
class TrieNode {
    TrieNode links[] = new TrieNode[2];

    boolean containsKey(int bit) {
        return links[bit] != null;
    }
    void put(int bit, TrieNode node) {
        links[bit] = node;
    } 
    TrieNode get(int bit) {
        return links[bit];
    }
}
class Trie {
    TrieNode root;
    Trie() {
        root = new TrieNode();
    }

    public void insert(int num) {
        TrieNode node = root;
        for (int i=31; i >=0; i--) {
            int bit = num >> i & 1;
            if (!node.containsKey(bit)) {
                node.put(bit, new TrieNode());
            }
            node = node.get(bit);
        }
    }

    public int maxXOR(int x) {
        TrieNode node = root;
        if (node.links[0] ==null && node.links[1] == null) {
            return -1;
        }
        int ans = 0;
        for (int i=31; i >=0; i--) {
            int bit = (x >> i) & 1;
            if (node.containsKey(1 - bit)) {
                ans = ans | (1 << i);
                node = node.get(1 -bit);
            } else {
                node = node.get(bit);
            }
        }

        return ans;
    }
}