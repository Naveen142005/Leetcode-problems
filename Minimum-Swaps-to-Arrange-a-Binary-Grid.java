1def lastone(row: list[int]) -> int:
2    try:
3        return len(row) - 1 - row[::-1].index(1)
4    except ValueError:
5        return 0
6
7class Solution:
8    def minSwaps(self, grid: List[List[int]]) -> int:
9        n = len(grid)
10        bit = [0] * (n + 1)  # binary indexed tree
11
12        def bitadd(i: int):
13            while i <= n:
14                bit[i] += 1
15                i += i & -i
16
17        def bitquery(i: int) -> int:
18            v = 0
19            while i > 0:
20                v += bit[i]
21                i -= i & -i
22            return v
23
24        buckets = [[] for _ in range(n)]  # list of minheaps for each rightmost one position
25        for i in range(n):
26            heappush(buckets[lastone(grid[i])], i)
27
28        globalheap = []
29        swaps = 0
30        for i in range(n):
31            while buckets[i]:
32                heappush(globalheap, heappop(buckets[i]))
33            if not globalheap:
34                return -1
35            j = heappop(globalheap)
36            swaps += j - bitquery(j)
37            bitadd(j + 1)
38
39        return swaps
40