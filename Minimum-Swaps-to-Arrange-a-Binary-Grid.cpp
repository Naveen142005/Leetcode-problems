1class Solution {
2    public int minSwaps(int[][] grid) {
3        int n = grid.length;
4
5        int tt = n - 1;
6        // while (tt > 0) {
7        //     int cnt = 0;
8        //     for (int i = 0; i < n; i += 1) {
9        //         if (grid[i][tt] == 0) cnt += 1;
10        //         if (cnt >= tt) break;
11        //     }
12        //     if (cnt < tt) return -1;
13        //     tt -=1;
14        // }
15
16        int mx = 0;
17        HashMap<Integer, int[]> mp = new HashMap<>();
18
19        for (int i = 0; i < n; i += 1) 
20            mp.put(i, grid[i]);
21        
22        for (int i = 0; i < n; i += 1) {
23            int [] temp = mp.get(i);
24            Boolean isAllZero = true; 
25            for (int x = n - 1; x >= i + 1; x -= 1) {
26                if (temp[x] != 0) {
27                    isAllZero = false;
28                    break;
29                }
30            }
31
32            if (!isAllZero) {
33            
34                for (int xx = i + 1; xx < n; xx += 1) {
35                    Boolean isOk = true;
36                    for (int yy = n - 1; yy >= i + 1; yy -= 1) {
37                        if (mp.get(xx)[yy] != 0) {
38                            isOk = false;
39                            // System.out.println(xx + " " + yy);
40                            break;
41                        }
42                    }
43                    if (isOk) {
44                        int st = i;
45                        int end = xx;
46
47                        int[] endarr = mp.get(end);
48    
49                        for (int pp = end; pp > st; pp -= 1) {
50                            mp.put(pp, mp.get(pp - 1));
51                        }
52                        mp.put(st, endarr);
53                        // System.out.println(end + " " + st);
54                        mx += (end - st);
55                        break;
56                    }
57                }
58            }
59
60        }
61        for (int i = 0; i < n; i += 1) {
62            int [] temp = mp.get(i);
63            Boolean isAllZero = true; 
64            for (int x = n - 1; x >= i + 1; x -= 1) {
65                if (temp[x] != 0) {
66                   return -1;
67                }
68            }
69        }
70        
71        return mx;
72    }
73}