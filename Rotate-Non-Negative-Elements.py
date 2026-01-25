1class Solution:
2    def rotateElements(self, nums: List[int], k: int) -> List[int]:
3        l = [i for i in nums if i >= 0]
4        if len(l):
5            k = k % len(l)
6            l = l[-(len(l) - k):] + l[:-(len(l) - k)]
7        
8        idx = 0
9        for i in range(0, len(nums)):
10            if (nums[i] >= 0):
11                nums[i] = l[idx]
12                idx += 1
13
14        return nums