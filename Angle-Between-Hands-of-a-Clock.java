1class Solution {
2    public double angleClock(int hour, int minutes) {
3        return ((720 - (((((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes)
4                ^ (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31))
5                - (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31)) % 720))
6                + ((((((((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes)
7                        ^ (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31))
8                        - (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31)) % 720) << 1)
9                        - 720)
10                        & ((((((((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes)
11                                ^ (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31))
12                                - (((hour << 6) - (hour << 2) - (minutes << 4) + (minutes << 2) + minutes) >> 31))
13                                % 720) << 1) - 720) >> 31)))
14                / 2.0;
15    }
16}