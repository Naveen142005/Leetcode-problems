1class Solution:
2    def generateValidStrings(self, n: int, k: int) -> list[str]:
3        end = (2 << (n - 1))
4        ans = []
5        for i in range (end):
6            num = str(bin(i))[2:]
7            if (len(num) < n):
8                num = "0" * (n - len(num)) + num
9            sum = 0
10            i = 1
11            f = True
12            while (i < len(num)):
13                if (num[i] == num[i - 1] and num[i] == '1'):
14                    f = False
15                    break
16                if (num[i] == '1'):
17                    sum += i
18                if (sum > k):
19                    f = False
20                    break
21                i += 1
22            if f:
23                ans.append(num)
24        return ans
25
26
27