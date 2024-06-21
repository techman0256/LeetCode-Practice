class Solution {
    static void chooseToppings(int idx, int cost, int[] toppingCosts, int target, int res[]) {
        if ( idx == toppingCosts.length ) {
            if (res[0] == -1 || Math.abs(cost - target) < Math.abs(res[0] - target) || (Math.abs(cost - target) == Math.abs(res[0] - target) && cost < res[0])) {
                res[0] = cost;
            }
            return;
        }

        // if (toppingCosts[idx] > target) {
        //     return 0;
        // }
        // int take0 = 0, take1 = 0, take2 = 0;
        // if (toppingCosts[idx] <= target) {
        // } 
        // if ((2 *toppingCosts[idx]) <= target) {
        // }
        chooseToppings(idx + 1, cost + toppingCosts[idx],toppingCosts, target, res);
        chooseToppings(idx + 1, cost + (2 *toppingCosts[idx]), toppingCosts, target, res);
        chooseToppings(idx + 1, cost, toppingCosts, target, res);

        return;
    }
    public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
        int n = baseCosts.length;
        int m = toppingCosts.length;

        Arrays.sort(toppingCosts);
        Arrays.sort(baseCosts);
        
            int res[] = new int[]{-1};
        // int ans = Integer.MIN_VALUE;
        for (int i=0; i < n; i++) {
            int cost = baseCosts[i];
            int topCost = 0;

            chooseToppings(0, cost, toppingCosts, target, res);
            // ans = Math.max(ans, res[0]);


        }

        return res[0];
    }
}