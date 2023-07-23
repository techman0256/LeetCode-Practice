/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer> dp = new HashMap<>();

        return robbery(root, dp);
    }

    static int robbery(TreeNode root, HashMap<TreeNode, Integer> memo) {
        if (root == null) {
            return 0;
        }

        if (memo.containsKey(root)) {
            return memo.get(root);
        }

        int take = Integer.MIN_VALUE;
        int leftleft = 0, leftright = 0, rightleft = 0, rightright = 0;
        int left = 0, right = 0;
        if (root.left != null) {
            leftleft = robbery(root.left.left, memo);
            leftright = robbery(root.left.right, memo);
        }
        if (root.right != null) {
            rightleft = robbery(root.right.left, memo);
            rightright = robbery(root.right.right, memo);

        }

        take = root.val + leftleft + leftright + rightright + rightleft;

        int notTake = robbery(root.left, memo) + robbery(root.right, memo);

        memo.put(root, Math.max(take, notTake));

        return Math.max(take, notTake);
    }
}