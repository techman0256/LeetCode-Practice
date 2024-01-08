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
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        
        int ans = 0;
        int right = 0, left = 0;

        right = rangeSumBST(root.right, low, high);
        left = rangeSumBST(root.left, low, high);
        ans += left + right;
        
        if (root.val >= low && root.val <= high) {
            ans += root.val; 
        }
        return ans;
    }
}