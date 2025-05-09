public class BinarySearch {
    static int search(int[] nums, int key) {
        int low = -1;
        int high = nums.length;

        while (high > low + 1) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= key) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (high != nums.length && nums[high] == key) {
            return high;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};
        int key = 12;

        System.out.println(search(nums, key));
    }
}
