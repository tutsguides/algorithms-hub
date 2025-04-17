#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Comparison function to sort activities by their finish time (second element of each interval)
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

// Solves the Activity Selection Problem using a greedy strategy.
// Given a list of intervals [start, finish], returns the largest set of non-overlapping intervals.
vector<vector<int> > solveActivitySelectionProblem(vector<vector<int> > &intervals) {
    // If there are zero or one intervals, they are trivially the solution
    if (intervals.size() <= 1)
        return intervals;

    // Sort all intervals in ascending order of their finish times
    sort(intervals.begin(), intervals.end(), compare);

    // This will hold our selected (non-overlapping) intervals
    vector<vector<int> > selected_intervals;

    // Always pick the first interval after sorting
    selected_intervals.push_back(intervals[0]);
    // Track the finish time of the last selected interval
    int last_finish_time = intervals[0][1];

    // Iterate over the remaining intervals
    for (size_t i = 1; i < intervals.size(); ++i) {
        // If the current interval starts after or exactly when the last selected one finishes
        if (intervals[i][0] >= last_finish_time) {
            // Select it
            selected_intervals.push_back(intervals[i]);
            // Update the last finish time
            last_finish_time = intervals[i][1];
        }
    }

    // Return the maximal set of non-overlapping intervals
    return selected_intervals;
}

int main() {
    vector<vector<int> > intervals = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}
    };

    auto selected_intervals = solveActivitySelectionProblem(intervals);
    for (const auto &interval: selected_intervals) {
        cout << interval[0] << ", " << interval[1] << "\n";
    }
}
