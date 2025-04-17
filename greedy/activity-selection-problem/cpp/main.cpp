#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Represents an activity with a start time `l` and finish time `r`.
struct activity {
    int l; // start time
    int r; // finish time
};

// Comparison function: orders activities by increasing finish time (`r`).
bool compare(const activity &a, const activity &b) {
    return a.r < b.r;
}

// Greedy solver for the Activity Selection Problem.
// Takes a list of activities and returns the maximum-size subset of non-overlapping activities.
vector<activity> solveActivitySelectionProblem(vector<activity> &activities) {
    // Trivial cases: zero or one activity is already optimal.
    if (activities.size() <= 1)
        return activities;

    // Sort activities so the one that finishes earliest comes first.
    sort(activities.begin(), activities.end(), compare);

    // Container for the chosen non-overlapping activities.
    vector<activity> selected_activities;
    // Always select the first (earliest-finishing) activity.
    selected_activities.push_back(activities[0]);
    // Keep track of when the last selected activity finishes.
    int last_finish_time = activities[0].r;

    // Iterate through the rest of the activities.
    for (size_t i = 1; i < activities.size(); ++i) {
        // If the next activity starts at or after the last finish time, select it.
        if (activities[i].l >= last_finish_time) {
            selected_activities.push_back(activities[i]);
            last_finish_time = activities[i].r;
        }
    }

    // Return the optimal set of non-overlapping activities.
    return selected_activities;
}

int main() {
    // Sample list of activities (start, finish)
    vector<activity> activities = {
        {1, 4}, {3, 5}, {0, 6},
        {5, 7}, {3, 9}, {5, 9},
        {6, 10}, {8, 11}, {8, 12},
        {2, 14}, {12, 16}
    };

    // Compute and print the selected activities
    auto selected_intervals = solveActivitySelectionProblem(activities);
    for (const auto &interval: selected_intervals) {
        cout << interval.l << ", " << interval.r << "\n";
    }

    return 0;
}
