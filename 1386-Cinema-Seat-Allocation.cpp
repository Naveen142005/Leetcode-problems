class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int t = 0;

        sort(reservedSeats.begin(), reservedSeats.end());

        int temp = -1;
        int mask = 0;
        int k = 0;

        for (auto i : reservedSeats) {

            if (temp == -1) {
                temp = i[0];
                mask |= (1 << (i[1] - 1));
            }
            else if (temp == i[0]) {
                mask |= (1 << (i[1] - 1));
            }
            else {
                k++;

                // 2,3,4,5
                if (!(mask & 2) &&
                    !(mask & 4) &&
                    !(mask & 8) &&
                    !(mask & 16)) {

                    t++;

                    mask |= 2;
                    mask |= 4;
                    mask |= 8;
                    mask |= 16;
                }

                // 4,5,6,7
                if (!(mask & 8) &&
                    !(mask & 16) &&
                    !(mask & 32) &&
                    !(mask & 64)) {

                    t++;

                    mask |= 8;
                    mask |= 16;
                    mask |= 32;
                    mask |= 64;
                }

                // 6,7,8,9
                if (!(mask & 32) &&
                    !(mask & 64) &&
                    !(mask & 128) &&
                    !(mask & 256)) {

                    t++;
                }

                mask = 0;
                temp = i[0];
                mask |= (1 << (i[1] - 1));
            }
        }

        // Last row
        if (temp != -1) {

            k++;

            // 2,3,4,5
            if (!(mask & 2) &&
                !(mask & 4) &&
                !(mask & 8) &&
                !(mask & 16)) {

                t++;

                mask |= 2;
                mask |= 4;
                mask |= 8;
                mask |= 16;
            }

            // 4,5,6,7
            if (!(mask & 8) &&
                !(mask & 16) &&
                !(mask & 32) &&
                !(mask & 64)) {

                t++;

                mask |= 8;
                mask |= 16;
                mask |= 32;
                mask |= 64;
            }

            // 6,7,8,9
            if (!(mask & 32) &&
                !(mask & 64) &&
                !(mask & 128) &&
                !(mask & 256)) {

                t++;
            }
        }

        return t + (n - k) * 2;
    }
};