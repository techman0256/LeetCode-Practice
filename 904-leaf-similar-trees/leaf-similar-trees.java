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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leaves1 = leafValue(root1);
        List<Integer> leaves2 = leafValue(root2);
        if (leaves1.size() == leaves2.size()) {
            for (int i=0; i < leaves1.size(); i++) {
                if (leaves1.get(i) != leaves2.get(i)) return false;
            }
        } else {
            return false;
        }
        return true;
    }
    static List<Integer> leafValue(TreeNode root) {
        if (root.left == null && root.right == null) {
            return Arrays.asList(new Integer[]{root.val});
        }
        List<Integer> leaves = new ArrayList<Integer>();
        if (root.left != null) leaves.addAll(leafValue(root.left));
        if (root.right != null) leaves.addAll(leafValue(root.right));

        return leaves;
    }
}