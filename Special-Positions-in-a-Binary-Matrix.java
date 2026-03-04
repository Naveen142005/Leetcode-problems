1class Solution {
2    public int numSpecial(int[][] mat) {
3        int row[] = new int [101];   
4        int col[] = new int [101];   
5        int m, n;
6        m = mat.length;
7        n = mat[0].length;
8        for (int i = 0; i < m; i += 1) {
9            for (int j = 0; j < n; j += 1) {
10                if (mat[i][j] != 0) {
11                    row[i] += 1;
12                    col[j] += 1;
13                }
14            }
15        }
16        int cnt = 0;
17        for (int i = 0; i < m; i += 1) {
18            for (int j = 0; j < n; j += 1) {
19                // System.out.print(mat[i][j] + " ");
20                if (mat[i][j] != 0) {
21                    if (row[i] == 1 && col[j] == 1) cnt += 1;
22                }
23            }
24            // System.out.println();
25        }
26        return cnt;
27    }
28}