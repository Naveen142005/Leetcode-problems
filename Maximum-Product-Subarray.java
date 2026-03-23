1class Solution {
2    public int maxProduct(int[] nums) {
3        int n = nums.length;
4
5        int currMax = nums[0];
6        int product = currMax;
7        for (int i = 1; i < n; i += 1) {
8            if (product == 0) product = 1;
9            product = product * nums[i];
10            currMax = Math.max (product, currMax);
11        }
12
13        int mx = currMax;   
14        currMax = nums[n - 1];
15        product = currMax;
16
17        for (int i = n - 2; i >= 0 ; i -= 1) {
18            if (product == 0) product = 1;
19            product = product * nums[i];
20            currMax = Math.max (product, currMax);
21
22        }   
23        return Math.max(mx, currMax);
24    }
25}