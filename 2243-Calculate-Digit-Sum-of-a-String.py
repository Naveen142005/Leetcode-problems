class Solution:
    def digitSum(self, s: str, k: int) -> str:
        
        while True:
            n = len(s)
            temp = 0
            ss = ""
            cnt = 0

            if (n <= k):
                break
            for i in range (0, n):
                cnt += 1
                temp += int(s[i])
               
                if cnt == k:
                    cnt = 0
                    ss += str(temp)
                    temp = 0

            # print (ss, temp)      
            if (cnt):
                ss += str(temp)
                temp = 0
            # print("==")
            # print(ss, temp)
            # print("==")
            s = ss       
        
        return s      