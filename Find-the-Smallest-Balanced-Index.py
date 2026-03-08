1class Solution:
2    def smallestBalancedIndex(self, nums: list[int]) -> int:
3        n = len(nums)
4        add = [0] * n
5        pro = [1] * n
6
7        add[0]  = nums[0]
8        pro[n - 1] = nums[n - 1]
9
10        if n == 2:
11            if nums[0] == 1:
12                return 1
13            return -1
14
15        mod = 10**9 + 7
16        
17        for i in range (1, n):
18            add[i] = (add[i - 1] + nums[i]) % mod
19            pro[n - i - 1] = (pro[n - i] * nums[n - i - 1]) % mod
20        
21        for i in range (1, n - 1):
22            if (add[i - 1] == pro[i + 1]): return i
23
24        return -1