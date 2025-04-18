class Activity:
    def __init__(self, l, r):
        self.l = l  # start time
        self.r = r  # finish time


# Function to solve the Activity Selection Problem
def solve_activity_selection_problem(activities):
    if len(activities) <= 1:
        return activities

    # Sort activities by finish time
    activities.sort(key=lambda activity: activity.r)

    selected_activities = []
    selected_activities.append(activities[0])  # Select the first activity
    last_finish_time = activities[0].r

    # Iterate through the remaining activities
    for i in range(1, len(activities)):
        if activities[i].l >= last_finish_time:
            selected_activities.append(activities[i])
            last_finish_time = activities[i].r

    return selected_activities


# Sample list of activities (start, finish)
activities = [
    Activity(1, 4), Activity(3, 5), Activity(0, 6),
    Activity(5, 7), Activity(3, 9), Activity(5, 9),
    Activity(6, 10), Activity(8, 11), Activity(8, 12),
    Activity(2, 14), Activity(12, 16)
]

# Get the selected activities
selected_activities = solve_activity_selection_problem(activities)

# Print the selected activities
for activity in selected_activities:
    print(f"{activity.l}, {activity.r}")
