public class BinarySearch {
    static int search(int[] nums, int key) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == key) {
                return mid; // found
            } else if (key < nums[mid]) {
                high = mid - 1; // search left half
            } else {
                low = mid + 1; // search right half
            }
        }
        return -1; // not found
    }

    public static void main(String[] args) {
        int[] nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};
        int key = 12;

        System.out.println(search(nums, key));
    }
}
