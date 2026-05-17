1class Solution:
2    def canReach(self, arr: List[int], start: int) -> bool:
3        
4        visi = [0] * len(arr)
5        
6        def dp(i, prev):
7            if i < 0 or i >= len(arr):
8                return False
9      
10            if (visi[i] == 1):
11                return False
12            if (arr[i] == 0):
13                return True
14
15            left = False
16            right = False
17
18            visi[i] = 1
19
20            left = dp(i + arr[i], arr[i])
21            if (left): 
22                return left
23            right = dp(i - arr[i],arr[i])
24
25            visi[i] = 0
26
27            return left or right
28        return dp(start, -1)