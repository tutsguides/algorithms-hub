public class BinarySearch {
    static boolean pred(int num) {
        if (num >= 12) return true;
        return false;
    }

    static int search(int[] nums) {
        int low = -1;
        int high = nums.length;

        while (high > low + 1) {
            int mid = low + (high - low) / 2;

            if (pred(nums[mid])) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }

    public static void main(String[] args) {
        int[] nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};

        System.out.println(search(nums));
    }
}
