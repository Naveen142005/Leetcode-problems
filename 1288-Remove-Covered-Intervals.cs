public class Solution {
    public int RemoveCoveredIntervals(int[][] intervals) {
        
        int n = intervals.Length;
        int removed = 0;

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == j) continue;
                if (intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    // Console.WriteLine (intervals[i][0] + " " + intervals[i][1]);
                     removed += 1;
                     break;
                }
            }
        }
        // Console.WriteLine(n + " " + removed);
        return n - removed;
    }
}