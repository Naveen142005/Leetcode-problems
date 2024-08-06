class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    int length = matrix.size();
    int top_left = 0;
    int top_right = length - 1;
    int bottom_right = length - 1;
    int bottom_left = length - 1;

    int f = 0;
    int break_point = length;

    for (int k = 0; k < length / 2; k++) {
        int bottom_right_index = bottom_right;
        int bottom_left_index = bottom_left;

        int cnt = 0;
        for (int j = k;; j++) {
            int t1 = matrix[top_left][j];
            int t2 = matrix[j][top_right];

            matrix[top_left][j] = matrix[bottom_left_index][k];
            matrix[j][top_right] = t1;

            matrix[bottom_left_index][k] = matrix[bottom_right][bottom_right_index];
            matrix[bottom_right][bottom_right_index] = t2;

            bottom_right_index -= 1;
            bottom_left_index -= 1;

            cnt += 1;
            if (cnt == length - 1) {
                break_point = length - 3;
                break;
            }

            if (cnt == break_point || break_point < 0) {
                break_point -= 2;
                if ((break_point == 0 && length % 2 == 1) || break_point < 0) f = 1;
                break;
            }
        }
        top_left += 1;
        if (f) break;
        top_right -= 1;
        bottom_right -= 1;
        bottom_left -= 1;
    }
    }
};