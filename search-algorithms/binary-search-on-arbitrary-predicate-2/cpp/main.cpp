#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
private:
    bool pred(const int num) {
        if (num >= 12) return true;
        return false;
    }

public:
    int search(const vector<int> &nums) {
        int n = int(nums.size());
        int low = -1;
        int high = n;

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
};

int main() {
    vector nums = {2, 4, 9, 12, 12, 12, 43, 78, 85, 89};

    BinarySearch binarySearch;
    cout << binarySearch.search(nums) << endl;
}
