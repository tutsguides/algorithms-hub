import java.util.Arrays;

class Solution {
    private boolean canFinish(int[] piles, int h, int k) {
        int hours = 0;

        for (int pile : piles) {
            hours += (pile + (k - 1)) / k;
            if (hours > h) return false;
        }

        return true;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int l = 0;
        int r = Arrays.stream(piles).max().getAsInt() + 1;

        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (canFinish(piles, h, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    }

    public static void main(String[] args) {
        int[] piles = {3, 6, 7, 11};
        int h = 8;

        Solution sol = new Solution();
        System.out.println(sol.minEatingSpeed(piles, h));
    }
}
