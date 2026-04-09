1class Solution:
2    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
3        MOD = 10**9 + 7
4
5        mp = defaultdict(list) 
6        n = len(nums)
7        sq = int(sqrt(n))
8
9        for l, r, k, v in queries:
10            if k > sq:
11                for i in range(l, r + 1, k):
12                    nums[i] = (nums[i] * v) % MOD
13            else:
14                # pass
15                mp[k].append((l, r, v))
16        # print (len(mp))
17        # print(nums)
18        for k in mp:
19            diff = [1] * (n + k)
20            # print(k, mp[k])
21            for l, r, v in mp[k]:
22                diff[l] = (diff[l] * v) % MOD
23
24                rplus1 = (l + ((r - l) // (k )) * k ) + k
25                # print(l , r, k, rplus1)
26                diff[rplus1] = (diff[rplus1] * pow(v, -1, MOD)) % MOD
27            
28            # print(diff)
29
30            for i in range (k, n + k):
31                # print(i)
32                diff[i] = (diff[i] * diff[i - k]) % MOD
33            # print (diff)
34            for i in range(0, n):
35                nums[i] = (nums[i] * diff[i]) % MOD
36
37            # print (nums)
38        ans = 0
39        for i in nums:
40            ans = ans ^ i
41
42        return ans