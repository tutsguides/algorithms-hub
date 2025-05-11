#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool canFinish(const vector<int> &piles, int h, int k) {
        int hours = 0;

        for (auto p: piles) {
            hours += (p + (k - 1)) / k;
            if (hours > h) return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canFinish(piles, h, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return r;
    }
};

int main() {
    vector piles = {3, 6, 7, 11};
    int h = 8;

    Solution sol;
    cout << sol.minEatingSpeed(piles, h) << endl;
}
