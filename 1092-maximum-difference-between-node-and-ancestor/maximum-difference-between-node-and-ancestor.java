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
    public int maxAncestorDiff(TreeNode root) {
        return maxDiff(root, new ArrayList<Integer>());
    }
    static int maxDiff(TreeNode root, List<Integer> ance) {
        if (root == null) {
            return 0;
        }
        int myMax = 0;
        for (Integer node: ance) {
            myMax = Math.max(myMax, Math.abs(node - root.val));
        }
        // System.out.println(root.val + " " + myMax);
        ance.add(root.val);
        int left = maxDiff(root.left, new ArrayList<Integer>(ance));
        int right = maxDiff(root.right, new ArrayList<Integer>(ance));

        return Math.max(Math.max(left, right), myMax);
    }
}