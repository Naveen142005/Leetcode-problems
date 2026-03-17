1class Solution {
2    public int maximalSquare(char[][] matrix) {
3        int m = matrix.length;
4        int n = matrix[0].length;
5
6        int dp[][] = new int[m][n];
7
8        int mx = 0;
9        for (int i = 0; i < m; i += 1) {
10            dp[i][0] = (matrix[i][0] == '1' ? 1 : 999999);
11            if (dp[i][0] == 1) mx = 1;
12
13        }
14
15        for (int i = 0; i < n; i += 1) {
16            dp[0][i] = (matrix[0][i] == '1' ? 1 : 999999);
17            if (dp[0][i] == 1) mx = 1;
18        }
19        
20        for (int i = 1; i < m; i += 1) {
21            for (int j = 1; j < n; j += 1) {
22                dp[i][j] = 999999;
23                if (matrix[i][j] == '1') { 
24                    dp[i][j] = 1;
25                    if (matrix[i - 1][j - 1] == '1' 
26                            && matrix[i - 1][j] == '1'
27                                && matrix[i][j - 1] == '1' 
28                        )
29                        dp[i][j] = 1 + Math.min (
30                            dp[i - 1][j - 1],
31                            Math.min(dp[i - 1][j], dp[i][j - 1])
32                        );
33                    mx = Math.max(mx, dp[i][j]);
34                    System.out.println(mx);
35                }
36            }
37        }
38        //  for (int i = 0; i < m; i += 1) {
39        //     for (int j = 0; j < n; j += 1) { System.out.print(dp[i][j] + " ");}
40        //     System.out.println();
41        //  }
42      
43        return mx*mx;
44    }
45}