import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Activity {
    int l; // start time
    int r; // finish time

    public Activity(int l, int r) {
        this.l = l;
        this.r = r;
    }
}

public class ActivitySelection {

    // Comparator to sort activities by finish time (r)
    public static Comparator<Activity> compareByFinishTime = new Comparator<Activity>() {
        @Override
        public int compare(Activity a, Activity b) {
            return Integer.compare(a.r, b.r);
        }
    };

    // Function to solve the Activity Selection Problem
    public static List<Activity> solveActivitySelectionProblem(List<Activity> activities) {
        if (activities.size() <= 1)
            return activities;

        // Sort activities by finish time
        Collections.sort(activities, compareByFinishTime);

        List<Activity> selectedActivities = new ArrayList<>();
        selectedActivities.add(activities.get(0)); // Select the first activity
        int lastFinishTime = activities.get(0).r;

        // Iterate through the remaining activities
        for (int i = 1; i < activities.size(); i++) {
            if (activities.get(i).l >= lastFinishTime) {
                selectedActivities.add(activities.get(i));
                lastFinishTime = activities.get(i).r;
            }
        }

        return selectedActivities;
    }

    public static void main(String[] args) {
        // Sample list of activities (start, finish)
        List<Activity> activities = new ArrayList<>();
        activities.add(new Activity(1, 4));
        activities.add(new Activity(3, 5));
        activities.add(new Activity(0, 6));
        activities.add(new Activity(5, 7));
        activities.add(new Activity(3, 9));
        activities.add(new Activity(5, 9));
        activities.add(new Activity(6, 10));
        activities.add(new Activity(8, 11));
        activities.add(new Activity(8, 12));
        activities.add(new Activity(2, 14));
        activities.add(new Activity(12, 16));

        // Get the selected activities
        List<Activity> selectedActivities = solveActivitySelectionProblem(activities);

        // Print the selected activities
        for (Activity activity : selectedActivities) {
            System.out.println(activity.l + ", " + activity.r);
        }
    }
}
