class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int ans = 0;
        int left = 0, right = cardPoints.length - 1;
        int sum = 0;
        
        for (left = 0; left < k; left++) {
            sum += cardPoints[left];
        }
        ans = Math.max(sum, ans);
        left--;
        for (right = cardPoints.length - 1; right >= cardPoints.length - k; right--) {
            sum = sum - cardPoints[left] + cardPoints[right];
            ans = Math.max(sum, ans);
            left--;
        }
       
        
        




        return ans;
    }
}