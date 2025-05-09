#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
    int search(const vector<int>& nums, int key) {
        int n = int(nums.size());
        int low = 0; // last index with nums[low] < key
        int high = n-1; // first index with nums[high] >= key

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (key == nums[mid])
                return mid; // found

            if (key < nums[mid])
                high = mid - 1; // search left half
            else
                low = mid + 1; // search right half
        }

        return -1; // not found
    }
};

int main() {
    vector nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};
    int key = 12;

    BinarySearch binarySearch;
    cout << binarySearch.search(nums, key) << endl;
}
