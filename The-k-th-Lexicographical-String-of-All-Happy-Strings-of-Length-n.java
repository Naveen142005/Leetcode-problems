1class Solution {
2    public static String ans = "";
3    static int STK = 0;
4    public static void solve (int n, int k, char ch, StringBuilder stb) {
5        if (ans != "") return;
6
7        if (stb.length() == n) {
8            STK -= 1;
9            if (STK == 0) {
10                ans = stb.toString();
11            }
12            return;
13        }
14
15        for (char i = 'a'; i <= 'c'; i += 1) {
16            if (stb.charAt(stb.length() - 1) != i) {
17                stb.append(i);
18                solve (n, k, ch, stb);
19                stb.deleteCharAt(stb.length() - 1);
20            }
21        }
22    }
23    public String getHappyString(int n, int k) {
24        StringBuilder stb = new StringBuilder();
25        Solution.ans = "";
26        Solution.STK = k;
27        
28        for (char i = 'a'; i <= 'c'; i += 1) {
29            stb.append(i);
30            solve (n, k, i, stb);
31            stb.deleteCharAt(stb.length() - 1);
32        }
33        return ans;
34    }
35}