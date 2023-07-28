import java.util.*;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = piles[0];

        for (int i=0; i < piles.length; i++) {
            high = Math.max(piles[i], high);
        }

        while (low <= high) {
            int mid = (low + high) / 2;

            if (checkK(piles, h, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
        
    }
    static int checkK(int[] piles, int h, int k) {
        int count = 0;
        for (int i=0; i < piles.length; i++) {
            count += Math.ceil((double)piles[i] / (double)k);
        }

        // if (count <= h) return true;
        // else return false;

        return count;
    }
}