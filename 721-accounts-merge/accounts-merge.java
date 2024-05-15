class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int N = accounts.size();
        HashMap<Integer, String> hm = new HashMap<Integer, String>();
        HashMap<String, Integer> emailToVal = new HashMap<String, Integer>();

        // int dsu = 0;
        int id = N;
        for (int i=0; i < N; i++) {
            for (int j=1; j < accounts.get(i).size(); j++) {
                if (!emailToVal.containsKey(accounts.get(i).get(j))) {
                    hm.put(id, accounts.get(i).get(j));
                    emailToVal.put(accounts.get(i).get(j), id);
                    id ++;
                }
            }
        }

        int parent[] = new int[N + hm.size()];
        int size[] = new int[N + hm.size()];

         for (int i=0; i < size.length; i++) {
            size[i] = 1;
            parent[i] = i;
        }


        for (int i=0; i < N; i++) {
            int u = i;
            for (int j=1; j < accounts.get(i).size(); j++) {
                int v = emailToVal.get(accounts.get(i).get(j));

                unionBySize(u, v, parent, size);
            }
        }

        // System.out.println(Arrays.toString(size));
        // System.out.println(Arrays.toString(parent));
        for (int i=0; i < parent.length; i++) {
            parent[i] = findParent(parent, i);
        }
        // System.out.println(Arrays.toString(parent));

        List<List<String>> ans = new ArrayList<>();

        HashMap<Integer, Integer> lookup = new HashMap<Integer, Integer>();
        // int lu = 0;
        for (int i=0; i < N; i++) {
            if (parent[i] == i) {
                if (!lookup.containsKey(i)) {
                    lookup.put(i, ans.size());
                }
                // ans.add(accounts.get(i).get(0));
                ans.add(new ArrayList<>());
            }
        }
        for (int i=N; i < parent.length; i++) {
            // System.out.println(i);
            String email = hm.get(i);
            int where = lookup.get(parent[i]);

            ans.get(where).add(email);
        }

        for (Map.Entry<Integer, Integer> entry : lookup.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();

            Collections.sort(ans.get(value));
            ans.get(value).add(0, accounts.get(key).get(0));
        }

        return ans;
    }
    static int findParent(int parent[], int node) {
        if (parent[node] == node) return node;

        return parent[node] = findParent(parent, parent[node]);
    }
    static void unionBySize(int u, int v, int parent[], int size[]) {
        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if ( pu == pv ) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            // size[pu] = 0;
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
            // size[pv] = 0;
        }

        return;
    }
}