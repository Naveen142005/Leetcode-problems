1class Solution:
2    def rob(self, nums: List[int], colors: List[int]) -> int:
3        nums.append(0)
4        colors.append(-2)
5        # print(nums, colors)
6        @cache
7        def dp (idx, prev = -1):
8            if (idx < 0): 
9                return 0
10            res = 0
11            res1 = 0
12            res2 = 0
13            res3 = 0
14            if colors[idx] == prev:
15                return max(dp(idx - 1, -1),dp(idx - 1, colors[idx]))
16            
17            else: 
18                res = dp(idx - 1, colors[idx]) + nums[idx]
19                res3 = dp(idx - 1)
20            return max(res, res3, res1,res2)
21        return dp(len(nums) - 1)