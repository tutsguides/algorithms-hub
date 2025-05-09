#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
    int search(const vector<int> &nums, int key) {
        int n = int(nums.size());
        int low = -1;
        int high = n;

        while (high > low + 1) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= key) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (high != n && nums[high] == key) {
            return high;
        }

        return -1;
    }
};

int main() {
    vector nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};
    int key = 12;

    BinarySearch binarySearch;
    cout << binarySearch.search(nums, key) << endl;
}
