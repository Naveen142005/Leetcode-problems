class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        arr = []
        for i in grid:
            for j in i:
                arr.append(j)
        n = len(arr)
        k = k % n

        arr = arr[-k:] + arr[:-k]
        s = len(grid[0])

        ans = []
        temp = []
        for i in range (len(arr)):
            temp.append(arr[i])
            if len(temp) == s:
                ans.append(temp)
                temp = []
        return ans
